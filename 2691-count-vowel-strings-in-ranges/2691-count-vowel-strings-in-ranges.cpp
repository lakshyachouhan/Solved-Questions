class Solution {
public:
    bool isVowelCheck(string &s){

        char ch = s[0];

        if(ch != 'a' && ch != 'e' && ch != 'o' && ch != 'u' && ch != 'i')
            return false ;

        char ch1 = s[s.size()-1];
        if(ch1 != 'a' && ch1 != 'e' && ch1 != 'o' && ch1 != 'u' && ch1 != 'i')
            return false ;

        return true ;
    }

    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        
        vector<int> prefix ;

        int sum = 0 ;
        for(auto w:words){

            if(isVowelCheck(w))  sum++;

            prefix.push_back(sum);
        }

        vector<int> ans ;
        for(auto q:queries){

            int s = q[0] , e = q[1];

            if(s == 0)  ans.push_back(prefix[e]);
            else{
                int curr = prefix[e] - prefix[s-1]; // s ko bhi inclusive 
                ans.push_back(curr);
            }
        }

        return ans ;
    }
};