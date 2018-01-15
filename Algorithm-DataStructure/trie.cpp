// summary for Trie (reTRIEve)

// Advantages:
//  utilize the common prefix to save space
//  efficient search with prefix


// Able to write a TrieNode class

const int NUM_ALPHABET = 26;

class TrieNode {
public:
    vector<TrieNode *> children;
    bool isComplete;
    
    TrieNode(bool status=false) : isComplete(status) {
        children.resize(NUM_ALPHABET);
    }
    
    ~TrieNode() {
        children.clear();
    }
};


class Trie {
public:
    Trie() {
        root = new TrieNode(false);
    }
    
    ~Trie() {
        delete root;
    }
    
    void insert(string word);
    bool search(string word);
    bool startWith(string prefix);
    
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
        node = node->children[c - 'a'];
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

bool Trie::startWith(string prefix) {
    TrieNode *node = root;
    for (int i = 0; i < prefix.size(); ++i) {
        char c = prefix[i];
        if (node->children[c - 'a'] == NULL) return false;
        node = node->children[c - 'a'];
    }
    return true;
}




