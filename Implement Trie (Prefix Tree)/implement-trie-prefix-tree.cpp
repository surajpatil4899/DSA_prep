class Trie {
    struct trienode{
      char val;
        int count;
        int endHere;
        trienode* child[26];
    };
    trienode* root;
    trienode* getNode(int index){
        trienode* newnode = new trienode;
        newnode->val = 'a'+index;
        newnode->count = newnode->endHere = 0;
        for(int i=0;i<26;i++)
            newnode->child[i] = NULL;
        return newnode;
    }
public:
    Trie() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        root = getNode('/'-'a');
    }
    
    void insert(string word) {
        trienode* curr =  root;
        int index;
        for(int i=0;word[i]!='\0';i++){
            index = word[i] - 'a';
            if(curr->child[index]==NULL) 
               curr->child[index] = getNode(index);
            curr->child[index]->count+=1;
            curr = curr->child[index];
        }
        curr->endHere += 1;
    }
    
    bool search(string word) {
         trienode* curr =  root;
        int index;
        for(int i=0;word[i]!='\0';i++){
            index = word[i] - 'a';
            if(curr->child[index]==NULL) 
               return false;
            curr = curr->child[index];
        }
        return (curr->endHere>0);
    }
    
    bool startsWith(string prefix) {
        trienode* curr =  root;
        int index;
        for(int i=0;prefix[i]!='\0';i++){
            index = prefix[i] - 'a';
            if(curr->child[index]==NULL) 
               return false;
            curr = curr->child[index];
        }
        return (curr->count>0);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */