// gitty Git TUI
// Copyright (C) 2021  Lian Studer

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see https://github.com/lianstuder/gitty.

#include <iostream>
#include <unistd.h>
#include <thread>
#include <ftxui/component/screen_interactive.hpp>
#include <ftxui/component/button.hpp>

#include "document.hpp"
#include "components/stage.hpp"
#include "components/commit.hpp"
#include "core/repository.hpp"

int main(void)
{
    using namespace gitty;
    using namespace ftxui;
    using namespace std;

    char cwd_buff[FILENAME_MAX];
    getcwd(cwd_buff, FILENAME_MAX);
    const string current_working_dir(cwd_buff);

    cout << current_working_dir << endl;

    Repository repository(current_working_dir, false);
    repository.update();

    Document document;
    auto screen = ScreenInteractive::Fullscreen();

    // Component initialisation
    StageComponent stage;
    CommitComponent commit;

    // Register components
    document.registerComponent(&stage);
    document.registerComponent(&commit);

    // thread update([&]() {
    //     for (;;)
    //     {
    //         using namespace std::chrono_literals;
    //         this_thread::sleep_for(1.0s);
    //         repository.update();
    //     }
    // });

    screen.Loop(&document);

    return EXIT_SUCCESS;
}
