#pragma once 
#include "TrieNode.hpp"
#include <string> 
#include <vector>

struct Suggestion {
    std::string word;
    long long frequency;
};

class Trie {
private:
    TrieNode* root;
    void Bfs(const std::string& prefix, std::vector<Suggestion>& results);
public:
    Trie();
    ~Trie();
    void insert(const std::string& word, long long frequency);
    std::vector<std::string> Get_words_with_prefix(const std::string& prefix);
};