#include <ftxui/component/button.hpp>
#include <ftxui/component/container.hpp>

#include "stage.hpp"
#include "../core/repository.hpp"

using namespace gitty;
using namespace ftxui;
using namespace std;

StageComponent::StageComponent()
{
    Add(&main_container);
    main_container.Add(&unstaged_container);
    main_container.Add(&staged_container);

    for (file &f : Repository::files)
    {
        if (f.status == modified)
        {
            CheckBox cb;
            cb.label = f.filename;
            cb.on_change = [&] {
                if (cb.state)
                {
                    Repository::idx.add_entry_by_path(f.path);
                    f.status = added;
                    staged.push_back(text(f.filename));
                }
                else
                {
                    Repository::idx.remove_entry_by_path(f.path);
                    f.status = modified;
                }
            };
            unstaged_container.Add(&cb);
        }
    }
}

Element StageComponent::Render()
{
    return window(
        text(L"Stage"),
        vbox(
            window(
                text(L"Unstaged"),
                unstaged_container.Render()),
            window(
                text(L"Staged"),
                hbox(move(staged)))));
}
