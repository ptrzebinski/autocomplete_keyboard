#include "../include/Trie.hpp"
#include<queue>
#include<algorithm>

Trie::Trie() {
    root = new TrieNode();
}
Trie::~Trie() {
    delete root;
}

void Trie::insert(const std::string& word) {
    TrieNode* current = root;
    
    for(char letter : word) {
        if(current->children.find(letter) == current->children.end()) {
            current->children[letter] = new TrieNode();
        }
        current = current->children[letter];
    }
    current->is_end_of_word = true;
}
void Trie::Bfs(const std::string& prefix, std::vector<std::string>& results) {
    
    TrieNode* current = root;
    
    for(char letter : prefix) {
        if(current->children.find(letter) == current->children.end()) {
            return;
        }
        current = current->children[letter];
    }

    std::queue<std::pair<std::string, TrieNode*>> to_process;
    to_process.push({prefix, current});
    
    while(!to_process.empty() && results.size() < 5) {
        auto [currentWord, node] = to_process.front();
    
        to_process.pop();
        if(node->is_end_of_word) {
            results.push_back(currentWord);
        }
    
        for(auto const& [letter, child] : node->children) {
            to_process.push({currentWord+letter, child});
        }
    }
}
std::vector<std::string> Trie::Get_words_with_prefix(const std::string& prefix) {
    std::vector<std::string> results;
    Bfs(prefix, results);
    std::sort(results.begin(), results.end(), [](const std::string& a, const std::string& b) {
        return a.size() < b.size(); 
    });
    return results;
}
