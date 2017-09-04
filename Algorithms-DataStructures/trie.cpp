// summary for Trie (reTRIEve)

// Able to write a TrieNode class

const int NUM_ALPHABET = 26;

class TrieNode {
public:
    vector<TrieNode *> children;
    bool isComplete;
    
    TrieNode(bool status) : isComplete(status) {
        children.resize(NUM_ALPHABET);
    }
};


class Trie {
public:
    Trie() {
        root = new Trie(false);
    }
    
    void insert(string word);
    bool search(string word);
    
private:
    TrieNode *root;
};


void Trie::insert(string word) {
    TrieNode *node = root;
    for (int i = 0; i < word.size(); ++i) {
        char c = word[i];
        if (node->children[c - 'a'] == NULL) {
            node->children[c - 'a'] = new TrieNode(false);
        }
        node = node->children[c  'a'];
    }
    node->isComplete = true;
}


bool Trie::search(string word) {
    TrieNode *node = root;
    for (int i = 0; i < word.size(); ++i) {
        char c = word[i];
        if (node->children[c - 'a'] == NULL) return false;
        node = node->children[c - 'a'];
    }
    return node->isComplete;
}






