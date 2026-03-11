#pragma once
#include<unordered_map>

struct TrieNode {
    std::unordered_map<char, TrieNode*> children;
    bool is_end_of_word;
    TrieNode() : is_end_of_word(false) {}
    ~TrieNode() {
        for(auto& pair : children){
            delete pair.second;
        }
    }
};