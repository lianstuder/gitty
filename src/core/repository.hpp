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

#pragma once

#include <string>
#include <cppgit2/repository.hpp>

#include "files.hpp"

namespace gitty
{
    class Repository
    {
    public:
        Repository(const std::string &path, bool is_bare);
        void update();

        static std::vector<gitty::file> files;
        static cppgit2::repository repo;
        static cppgit2::index idx;

    private:
        void updateFilesList(std::vector<gitty::file>);
    };
}
