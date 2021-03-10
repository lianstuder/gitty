#include <ftxui/component/button.hpp>
#include <ftxui/component/container.hpp>

#include "stage.hpp"
#include "../core/repository.hpp"

using namespace neutron;
using namespace ftxui;
using namespace std;

Stage::Stage(neutron::Repository *)
{
    Add(&main_container);
    main_container.Add(&unstaged_container);
    main_container.Add(&staged_container);

    for (file &f : repo.files)
    {
        CheckBox cb = CheckBox();
        cb.label = to_wstring(f.filename);
        cb.on_change = stage_selected(&f);
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

auto Stage::stage_selected(neutron::file *f)
{
    return [&] {
        f->status = added;
        auto index = repo.repo.index();
        index.add_entry_by_path(f->filename);
    };
}
