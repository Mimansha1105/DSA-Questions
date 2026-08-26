class WordDictionary {
public:
class Node {
    public:
        Node* children[26];
        bool isEnd;
        Node() {
            for(int i = 0; i < 26; i++) {
                children[i] = NULL;
            }
            isEnd = false;
        }
    };
    Node* root;
    WordDictionary() {
    root = new Node();
    }
    void addWord(string word) {
         Node* curr = root;
        for(char c : word) {
            int index = c - 'a';
            if(curr->children[index] == NULL) {
                curr->children[index] = new Node();
            }
            curr = curr->children[index];
        }
        curr->isEnd = true;
    }

bool searchkro(string &word, int index, Node* curr) {
        if(index == word.size()) {
            return curr->isEnd;
        }
        char c = word[index];
        if(c != '.') {
            int idx = c - 'a';
            if(curr->children[idx] == NULL) {
                return false;
            }
            return searchkro(word, index + 1,
                                curr->children[idx]);
        }
        for(int i = 0; i < 26; i++) {
            if(curr->children[i] != NULL) {
                if(searchkro(word, index + 1,
                                curr->children[i])) {
                    return true;
                }
            }
        }
        return false;
    }
    bool search(string word) {
      return searchkro(word, 0, root);  
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */