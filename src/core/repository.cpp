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

#include <string>

#include <cppgit2/repository.hpp>

#include "repository.hpp"
#include "files.hpp"

using namespace cppgit2;
using namespace std;

void neutron::Repository::update_filelist()
{
    repo.for_each_status(
        [&](string path, cppgit2::status::status_type status_flags) {
            file f;
            f.filename = path;
            f.cb = ftxui::CheckBox();
            switch (status_flags)
            {
            case cppgit2::status::status_type::index_modified:
                f.status = modified;
                break;

            case cppgit2::status::status_type::ignored:
                f.status = ignored;
            }

            files.push_back(f);
        });
}
