class TrieNode{
    public:
    char value ;
    int childCount ;
    TrieNode* children[26];
    bool isTerminal ;

    TrieNode(char ch){
        this -> value = ch ;
        this -> isTerminal = false ;
        this -> childCount = 0;
        for(int i=0; i<26; i++)
        this -> children[i] = NULL;
   }
};

void insertWord(TrieNode* root,string word){

    if(word.length() == 0){
        root -> isTerminal = true ;
        return ;
    }

    char ch = word[0];
    int index = word[0] - 'a';
    TrieNode* child ;

    if(root->children[index] != 0)
       child = root->children[index];

    else{
        child = new TrieNode(ch);
        root->children[index] = child ;
        root->childCount++ ;
    }

    insertWord(child,word.substr(1));
}




class Solution {
public:
    
    string longestCommonPrefix(vector<string>& strs) {
        TrieNode* root = new TrieNode('-');

        for(auto s:strs)
           insertWord(root,s);

        string ans = "";
        TrieNode* temp = root ;
        while(temp->childCount == 1){

            if(temp -> isTerminal ){
                return ans ;
            }
            // cout << temp->value ;
            for(int i=0; i<26;i++)
            {
                if(temp->children[i] != NULL){
                    temp = temp->children[i];
                    break;
                }
            }
            
            ans.push_back(temp->value);
        }

        return ans ;
    }
};