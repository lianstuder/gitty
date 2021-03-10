#pragma once

#include <string>

#include <cppgit2/repository.hpp>

#include <ftxui/component/checkbox.hpp>
#include <ftxui/component/button.hpp>
#include <ftxui/component/container.hpp>

#include "../core/files.hpp"
#include "../core/repository.hpp"

namespace neutron
{
    class Stage : public ftxui::Component
    {
    private:
        ftxui::Container main_container = ftxui::Container::Vertical();

        neutron::Repository repo;

        // Subcontainers
        ftxui::Container unstaged_container = ftxui::Container::Vertical();
        ftxui::Container staged_container = ftxui::Container::Vertical();

        std::vector<neutron::file> unstaged_files;
        std::vector<neutron::file> staged_files;

    public:
        Stage(neutron::Repository *);
        ftxui::Element Render();
        auto stage_selected(neutron::file *);
    };
}
