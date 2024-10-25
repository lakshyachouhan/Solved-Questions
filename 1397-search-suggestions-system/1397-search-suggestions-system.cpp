class TrieNode {
public:
    char value;
    TrieNode* children[26];
    bool isTerminal;

    TrieNode(char val) {
        this->value = val;
        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
        this->isTerminal = false;
    }

    void insertWord(TrieNode* root, string word) {
        insertUtil(root, word, 0);
    }

    bool searchWord(TrieNode* root, string word) {
        return searchUtil(root, word, 0);
    }

    vector<string> startsWith(TrieNode* root, string &prefix) {

        TrieNode* temp = root ;
        int i = 0 ;
        while(i < prefix.size()){
            
            int index = prefix[i] - 'a' ;
            if(temp->children[index] != NULL){
                temp = temp->children[index];
            }

            else break ;
            
            i++;
        }

        
        vector<string> ans ;
        if(i == prefix.size()){
            // agr prefix mila toh aage find 
            string prefixKeBaadKi ;
            searchModified(temp,ans,prefix,prefixKeBaadKi);

        }

        return ans;
    }

private:
    void insertUtil(TrieNode* root, string word, int i) {
        if (word.length() == i) {
            root->isTerminal = true;
            return;
        }

        char ch = word[i];
        int index = ch - 'a';
        TrieNode* child;

        if (root->children[index] != NULL) {
            child = root->children[index];
        } 
        else {
            child = new TrieNode(ch);
            root->children[index] = child;
        }

        insertUtil(child, word, i + 1);
    }

    bool searchUtil(TrieNode* root, string word, int i) {
        if (word.length() == i) {
            return root->isTerminal;
        }

        char ch = word[i];
        int index = ch - 'a';
        TrieNode* child;

        if (root->children[index] != NULL) {
            child = root->children[index];
        } else {
            return false;
        }

        return searchUtil(child, word, i + 1);
    }

    void searchModified(TrieNode* root,vector<string> &ans, string &prefix, string &build) {

        if (root->isTerminal) {
            ans.push_back(prefix+build);
        }

        if(ans.size() == 3) return ;

        for(int i=0; i<26; i++){

            TrieNode* next = root->children[i] ;
            if(next != NULL){
                build.push_back(i+'a');
                searchModified(next,ans,prefix,build);
                if(ans.size() == 3) return ;
                build.pop_back();
            }
        }
    }
};

class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        
        TrieNode* root = new TrieNode('-');
        for(auto &s:products){
            root->insertWord(root,s);
        }

        vector<vector<string>> ans ;
        string curr ;
        for(auto ch:searchWord){

            curr.push_back(ch);
            vector<string> currAns = root->startsWith(root,curr);
            ans.push_back(currAns);
        }

        return ans ;

    }
};