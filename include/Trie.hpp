#pragma once 
#include "TrieNode.hpp"
#include <string> 
#include <vector>
class Trie {
private:
    TrieNode* root;
    void Bfs(const std::string& prefix, std::vector<std::string>& results);
public:
    Trie();
    ~Trie();
    void insert(const std::string& word);
    std::vector<std::string> Get_words_with_prefix(const std::string& prefix);
};