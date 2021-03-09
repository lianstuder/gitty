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

#include <string>

#include <ftxui/component/checkbox.hpp>
#include <cppgit2/repository.hpp>

namespace neutron
{
    enum class status
    {
        modified,
        ignored
    };

    struct file
    {
        std::string filename;
        neutron::status status;
        ftxui::CheckBox cb;
    };
}
