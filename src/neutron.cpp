// Neutron Git TUI
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
// along with this program.  If not, see https://github.com/lianstuder/neutron.

#include <iostream>
#include <thread>

#include <ftxui/component/screen_interactive.hpp>
#include <ftxui/component/button.hpp>

#include "document.hpp"
// #include "core/repository.hpp"
#include "components/stage.hpp"
#include "components/commit.hpp"

int main(void)
{
    using namespace ftxui;

    neutron::Repository repo = neutron::Repository();

    neutron::Document document = neutron::Document();
    auto screen = ScreenInteractive::Fullscreen();

    // Component initialisation
    neutron::Stage stage = neutron::Stage(&repo);
    neutron::Commit commit = neutron::Commit(&repo);

    // Register components
    document.registerComponent(&stage);
    document.registerComponent(&commit);

    std::thread update([&]() {
        for (;;)
        {
            using namespace std::chrono_literals;
            std::this_thread::sleep_for(1.0s);
            repo.update_filelist();
        }
    });

    screen.Loop(&document);

    return EXIT_SUCCESS;
}
