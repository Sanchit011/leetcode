class Trie {
public:
    /** Initialize your data structure here. */
    struct Trie* child[26] = {};
    bool isEnd = false;
    Trie() {}
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Trie* node = this;
        for(char c : word){
            int x = c - 'a';
            if(!node->child[x]) node->child[x] = new Trie();
            node = node->child[x];
        }
        node->isEnd = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Trie* node = this;
        for(char c : word){
            int x = c - 'a';
            if(!node->child[x]) return false;
            node = node->child[x];
        }
        return node->isEnd;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Trie* node = this;
        for(char c : prefix){
            int x = c - 'a';
            if(!node->child[x]) return false;
            node = node->child[x];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */