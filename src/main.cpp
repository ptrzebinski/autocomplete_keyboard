#include "../include/AutocompleteEngine.hpp"
#include <string>
#include <iostream>

int main() {
    AutocompleteEngine engine;
    std::string path = "./data/dictionary.txt";
    if(!engine.load_dictionary(path)) {
        return 1;
    }
    std::string input;
    while(true) {
        std::cout<<"Search >";
        std::cin >> input;
        if(input == "exit") {
            std::cout<<"Closing the program";
            break;
        }
        std::vector<std::string> suggestions = engine.get_suggestions(input);
        if(suggestions.empty()) {
            std::cout<<"No answer";
            continue;
        }
        for(const auto& word : suggestions) {
            std::cout<<word<<" ";
        }
        std::cout<<"\n";
    }
    return 0;
}
