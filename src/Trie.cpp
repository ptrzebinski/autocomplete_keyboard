#include "../include/Trie.hpp"
#include<queue>
#include<algorithm>

Trie::Trie() {
    root = new TrieNode();
}
Trie::~Trie() {
    delete root;
}

void Trie::insert(const std::string& word, long long frequency) {
    TrieNode* current = root;
    
    for(char letter : word) {
        if(current->children.find(letter) == current->children.end()) {
            current->children[letter] = new TrieNode();
        }
        current = current->children[letter];
    }
    current->is_end_of_word = true;
    current->frequency = frequency;
}
void Trie::Bfs(const std::string& prefix, std::vector<Suggestion>& results) {

    TrieNode* current = root;
    
    for(char letter : prefix) {
        if(current->children.find(letter) == current->children.end()) {
            return;
        }
        current = current->children[letter];
    }

    std::queue<std::pair<std::string, TrieNode*>> to_process;
    to_process.push({prefix, current});
    
    while(!to_process.empty()) {
        auto [currentWord, node] = to_process.front();
        to_process.pop();

        
        if(node->is_end_of_word) {
            results.push_back({currentWord, node->frequency});
        }
    
        for(auto const& [letter, child] : node->children) {
            to_process.push({currentWord+letter, child});
        }
    }
}
std::vector<std::string> Trie::Get_words_with_prefix(const std::string& prefix) {
    std::vector<Suggestion> all_results;
    Bfs(prefix, all_results);

    std::sort(all_results.begin(), all_results.end(), [](const Suggestion& a, const Suggestion& b) {
        return a.frequency > b.frequency; 
    });
    std::vector<std::string> final_results;
    int number_of_suggestions = 5;
    int limit = std::min(number_of_suggestions, (int)all_results.size());
    for(int i=0; i<limit; i++) {
        final_results.push_back(all_results[i].word);
    }
    return final_results;
}
