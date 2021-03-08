#include <ftxui/component/button.hpp>
#include <ftxui/component/container.hpp>
#include <git2.h>

#include "stage.hpp"

using namespace Neutron;
using namespace ftxui;
using namespace std;

Stage::Stage()
{
    Add(&main_container);
    main_container.Add(&unstaged_container);
    main_container.Add(&staged_container);

    unstaged_files.resize(5);
    for (int i = 0; i < unstaged_files.size(); ++i)
    {
        unstaged_files[i].label = (L"Checkbox " + to_wstring(i));
        unstaged_files[i].state = true;
        unstaged_container.Add(&unstaged_files[i]);
    }

    staged_files.resize(5);
    for (int i = 0; i < staged_files.size(); ++i)
    {
        staged_files[i].label = (L"Checkbox " + to_wstring(i));
        staged_files[i].state = true;
        staged_container.Add(&staged_files[i]);
    }
}

Element Stage::Render()
{
    return window(
        text(L"Stage"),
        vbox(
            window(
                text(L"Unstaged"),
                unstaged_container.Render()),
            window(
                text(L"Staged"),
                staged_container.Render())));
}
