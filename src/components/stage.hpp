#pragma once

#include <string>

#include <ftxui/component/checkbox.hpp>
#include <ftxui/component/button.hpp>
#include <ftxui/component/container.hpp>

namespace Neutron
{
    struct File
    {
        std::string filename;
        ftxui::CheckBox cb;
    };

    class Stage : public ftxui::Component
    {
    private:
        ftxui::Container main_container = ftxui::Container::Vertical();

        // Subcontainers
        ftxui::Container unstaged_container = ftxui::Container::Vertical();
        ftxui::Container staged_container = ftxui::Container::Vertical();

        std::vector<ftxui::CheckBox> unstaged_files;
        std::vector<ftxui::CheckBox> staged_files;

    public:
        Stage();
        ftxui::Element Render();
    };
}
