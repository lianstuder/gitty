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

#pragma once

#include <ftxui/component/component.hpp>
#include <ftxui/component/container.hpp>
#include <ftxui/component/input.hpp>

namespace Neutron
{
    class Commit : public ftxui::Component
    {
    private:
        ftxui::Container container = ftxui::Container::Vertical();
        ftxui::Input commit_message_input;
        std::string commit_message;

    public:
        Commit();
        ftxui::Element Render();
    };
}
