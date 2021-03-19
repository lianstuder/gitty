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

#include <ftxui/component/component.hpp>
#include <ftxui/component/container.hpp>
#include <ftxui/component/input.hpp>

#include "commit.hpp"
#include "../core/repository.hpp"

using namespace gitty;
using namespace ftxui;
using namespace std;

CommitComponent::CommitComponent()
{
    Add(&container);
    container.Add(&commit_message_input);
    commit_message_input.placeholder = L"Commit message";
    commit_message_input.on_enter = [this] {
        commit_message_input.content = L"";
    };
}

Element CommitComponent::Render()
{
    return container.Render();
}
