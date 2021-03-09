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

#include <ftxui/component/component.hpp>
#include <ftxui/component/container.hpp>

#include "core/repository.hpp"

namespace neutron
{
    class Document : public ftxui::Component
    {
    private:
        ftxui::Container container = ftxui::Container::Vertical();

    public:
        Document()
        {
            Add(&container);
        };
        inline ftxui::Element Render() override
        {
            return ftxui::vbox(
                ftxui::text(L"Neutron") | ftxui::center | ftxui::bold,
                ftxui::hbox(container.Render()));
        };
        inline void registerComponent(ftxui::Component *elem)
        {
            container.Add(elem);
        };
    };
}
