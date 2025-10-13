class Solution {
public:
    bool check(string &w1,string &w2){

        vector<int> v(26,0);
        for(auto ch:w1)
            v[ch-'a']++;

        for(auto ch:w2)
            v[ch-'a']--;

        for(auto ele:v){

            if(ele != 0)
                return false ;
        }

        return true ;
    }

    vector<string> removeAnagrams(vector<string>& words) {
        
        int i = 0 ;
        
        for(int j=1; j<words.size(); j++){

            if(check(words[i],words[j]))
                continue ;

            else words[++i] = words[j];
        }

        return vector<string>(words.begin(),words.begin()+i+1);
    }
};