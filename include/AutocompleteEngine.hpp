#pragma once
#include "Trie.hpp"
#include <string>
#include <vector>

class AutocompleteEngine {
private:
    Trie trie;    
public:
    bool load_dictionary(const std::string& filepath);
    
    std::vector<std::string> get_suggestions(const std::string& prefix);
};
