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
#include <codecvt>
#include <locale>

namespace gitty
{
    using convert_t = std::codecvt_utf8<wchar_t>;
    std::wstring_convert<convert_t, wchar_t> conv;

    inline std::string to_string(std::wstring wstr)
    {
        return conv.to_bytes(wstr);
    }

    inline std::wstring to_wstring(std::string str)
    {
        return conv.from_bytes(str);
    }
}
