class TrieNode{
    public :
    char value ;
    TrieNode* children[26];
    bool isTerminal ;

    TrieNode(char ch){
        this -> value = ch ;
        for(int i=0; i<26; i++) this->children[i] = NULL ;
        this -> isTerminal = false ;
    }

    void insert(TrieNode* root,string &word){

        TrieNode* temp = root ;
        for(auto &ch:word){

            int index = ch - 'a' ;
            if(temp->children[index] == NULL)
                temp->children[index] = new TrieNode(ch);

            temp = temp->children[index] ;
        }

        temp->isTerminal = true ;
    }
};

class Solution {
public:
    vector<int> dp ;

    int solve(TrieNode* root,string &t,int i){

        if(i >= t.size())
            return 0 ;

        if(dp[i] != -1)
            return dp[i];

        int ans = 1e9 ;
        TrieNode* temp = root ;

        for(int j=i; j<t.size(); j++){
            
            int index = t[j]-'a';
            if(temp->children[index] == NULL)   break ;
            // ye wal toh mil gaya aage wla dekho 

            int curr = 1 + solve(root,t,j+1);
            ans = min(ans,curr);
            
            temp = temp->children[index]; // aur badi length se bhi check karo
        }

        return dp[i] = ans ;
    }

    int minValidStrings(vector<string>& words, string target) {
        
        TrieNode* root = new TrieNode('-');

        for(auto &s:words)
            root->insert(root,s);

        int n = target.size();
        dp.resize(n,-1);

        int ans = solve(root,target,0);
        return ans == 1e9 ? -1 : ans ; 
    }
};