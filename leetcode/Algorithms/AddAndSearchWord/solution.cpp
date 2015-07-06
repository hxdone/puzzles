// by hxdone
// TODO: 1. change recursion to iterative backtracking
//       2. compress the suffix pathes which have only one child in a row

class TrieNode {
public:
    TrieNode(): children({NULL}), word_ends(false) {}
    TrieNode* children[26];
    bool word_ends;
};

class WordDictionary {
public:
    WordDictionary() {
        root = new TrieNode();
    }
    // Adds a word into the data structure.
    void addWord(string word) {
        TrieNode* cur  = root;
        for (int i = 0; i < word.length(); ++i) {
            if (cur->children[word[i]-'a'] == NULL)
                cur->children[word[i]-'a'] = new TrieNode();
            cur = cur->children[word[i]-'a'];
        }
        cur->word_ends = true;
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
        return search(word, 0, root);
    }
    
    TrieNode* root;
private:
    bool search(string& word, int i, TrieNode* t) {
        while (t && i < word.length()) {
            if (word[i] != '.')
                t = t->children[word[i++]-'a'];
            else {
                for (int j = 0; j < 26; ++j)
                    if (search(word, i+1, t->children[j]))
                        return true;
                return false;
            }
        }
        return t && t->word_ends;
    }
};

// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");
