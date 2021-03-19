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

#include <string>
#include <cppgit2/repository.hpp>
#include <ftxui/component/checkbox.hpp>

#include "repository.hpp"
#include "../util/convert.hpp"

using namespace gitty;
using namespace std;

vector<file> Repository::files;
cppgit2::repository Repository::repo;
cppgit2::index Repository::idx;

Repository::Repository(const string &path, bool is_bare)
{
    using namespace cppgit2;
    repo = repository::init(path, is_bare);
    idx = repo.index();
}

void Repository::update()
{
    using namespace cppgit2;
    vector<file> files_;

    // repo.for_each_status(
    //     [&](const std::string &path, status::status_type status_flags) {
    //         if ((status_flags & status::status_type::index_modified) !=
    //             status::status_type::index_modified)
    //         {
    //             file new_file;
    //             new_file.filename = to_wstring(path);
    //             new_file.path = path;

    //             if ((status_flags & status::status_type::ignored) !=
    //                 status::status_type::ignored)
    //                 new_file.status = ignored;
    //             else
    //                 new_file.status = modified;

    //             files_.push_back(new_file);
    //         }
    //     });

    updateFilesList(files_);
}

void Repository::updateFilesList(vector<file> files_)
{
    Repository::files = files_;
}
