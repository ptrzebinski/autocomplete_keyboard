#include "../include/AutocompleteEngine.hpp"
#include <fstream>
#include <iostream>
bool AutocompleteEngine::load_dictionary(const std::string& filepath) {
    std::ifstream file(filepath);
    if(!file.is_open()) {
        std::cerr<<"CRITICAL ERROR: Could not open file: "<<filepath<<"\n";
        return false; 
    }
    std::string word;
    long long frequency;
    while(file >> word >> frequency) {
        if(word.length() > 0 && word.length() < 40) {
            trie.insert(word);
        }
    }
    file.close();
    return true;
}
std::vector<std::string> AutocompleteEngine::get_suggestions(const std::string& prefix) {
    return trie.Get_words_with_prefix(prefix);
}
