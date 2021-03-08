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

#include <ftxui/component/screen_interactive.hpp>
#include <ftxui/component/button.hpp>

#include "document.hpp"
// #include "core/repository.hpp"
#include "components/stage.hpp"
#include "components/commit.hpp"

int main(void)
{
    using namespace ftxui;

    // Neutron::Repository repo = Neutron::Repository();

    Neutron::Document document = Neutron::Document();
    auto screen = ScreenInteractive::Fullscreen();

    // Component initialisation
    Neutron::Stage stage = Neutron::Stage();
    Neutron::Commit commit = Neutron::Commit();

    // Register components
    document.registerComponent(&stage);
    document.registerComponent(&commit);

    screen.Loop(&document);

    return EXIT_SUCCESS;
}
