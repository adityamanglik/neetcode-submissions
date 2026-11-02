class PrefixTree {
    struct Node{
        char val;
        unordered_map<char, Node*> children;
    };
public:
    Node* root;
    PrefixTree() {
        root = new Node;
    }
    
    void insert(string word) {
        Node* curr = root;
        for(int index = 0; index < word.length(); ++index)
        {// start traversing from root
            if(curr->children.find(word[index]) == curr->children.end()){
                Node* newNode = new Node;
                newNode->val = word[index];
                curr->children[word[index]] = newNode;
            }
            curr = curr->children[word[index]];
        }
        // insert string terminator at end
        Node* newNode = new Node;
        newNode->val = '0';
        curr->children['0'] = newNode;
    }
    
    bool search(string word) {
        Node* curr = root;
        for(int index = 0; index < word.length(); ++index){
            if(curr->children.find(word[index]) == curr->children.end())
                return false;
            curr = curr->children[word[index]];
        }
        if(curr->children.find('0') == curr->children.end())
            return false;
        return true;
    }
    
    bool startsWith(string prefix) {
        Node* curr = root;
        for(int index = 0; index < prefix.length(); ++index){
            if(curr->children.find(prefix[index]) == curr->children.end())
                return false;
            curr = curr->children[prefix[index]];
        }
        return true;
    }
};
