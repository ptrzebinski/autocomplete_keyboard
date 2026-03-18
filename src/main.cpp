#include <iostream>
#include <string>
#include <vector>
#include<algorithm>
#include<cctype>
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
        std::string current = search_query.substr(search_query.find_last_of(' ') + 1);
        
        if (!search_query.empty()) {
            bool upper_case = ('A' <= current[0] && current[0] <= 'Z');
            
            if(upper_case) current[0] += 32;
            
            suggestions = engine.get_suggestions(current);
            
            if(upper_case) {
                for(auto& word : suggestions) {
                    if(!word.empty()) word[0] -= 32;
                }
            }
        }

        Elements results_elements;
        if (suggestions.empty() && !current.empty()) {
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