#include <iostream>
#include <string>
#include <vector>
#include "ftxui/component/component.hpp"
#include "ftxui/component/screen_interactive.hpp"
#include "ftxui/dom/elements.hpp"

#include "../include/AutocompleteEngine.hpp"

using namespace ftxui;

int main() {
    AutocompleteEngine engine;
    std::string path = "./data/dictionary.txt";

    if (!engine.load_dictionary(path)) {
        std::cerr << "CRITICAL ERROR: dictionary file not found at path: " << path << "\n";
        return 1;
    }

    std::string search_query = "";
    Component input_field = Input(&search_query, "Start writing...");

    auto renderer = Renderer(input_field, [&] {
        std::vector<std::string> suggestions;
        
        if (!search_query.empty()) {
            suggestions = engine.get_suggestions(search_query);
        }

        Elements results_elements;
        if (suggestions.empty() && !search_query.empty()) {
            results_elements.push_back(text(" No results ") | color(Color::Red));
        } 

        else {
            for (const auto& word : suggestions) {
                results_elements.push_back(
                    hbox({
                        text(" > ") | color(Color::Green),
                        text(word) | bold
                    })
                );
            }
        }

        return vbox({
            text(" AUTOCOMPLETE KEYBOARD ") | bold | color(Color::Cyan) | center,
            separator(),
            hbox(text(" Search: "), input_field->Render()) | border,
            vbox(std::move(results_elements)) | border
        }) | border;
    });

    auto screen = ScreenInteractive::TerminalOutput();
    screen.Loop(renderer);

    return 0;
}