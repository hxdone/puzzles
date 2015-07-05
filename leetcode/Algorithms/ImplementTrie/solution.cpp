// by hxdone

class TrieNode {
public:
    // Initialize your data structure here.
    TrieNode(): children({NULL}), word_end(false) {}
    TrieNode* children[26];
    bool word_end;
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string word) {
        TrieNode* cur_node = root;
        for (int i = 0; i < word.length(); ++i) {
            if (cur_node->children[word[i]-'a'] == NULL)
                cur_node->children[word[i]-'a'] = new TrieNode();
            cur_node = cur_node->children[word[i]-'a'];
        }
        if (cur_node == NULL)
            cur_node = new TrieNode();
        cur_node->word_end = true; 
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        TrieNode* cur_node = root;
        for (int i = 0; i < word.length(); ++i) {
            if (cur_node->children[word[i]-'a'])
                cur_node = cur_node->children[word[i]-'a'];
            else
                return false;
        }
        return cur_node->word_end;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        TrieNode* cur_node = root;
        for (int i = 0; i < prefix.length(); ++i) {
            if (cur_node->children[prefix[i]-'a'])
                cur_node = cur_node->children[prefix[i]-'a'];
            else
                return false;
        }
        return true;
    }

private:
    TrieNode* root;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");
