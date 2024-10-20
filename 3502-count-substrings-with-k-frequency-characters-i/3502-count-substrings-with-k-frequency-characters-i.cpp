class Solution {
public:
    int numberOfSubstrings(string s, int k) {

        if(k == 1)
            return (s.size()*(s.size()+1)) / 2 ;
        
        int ans = 0 ;
        vector<int> v(26,0);

        for(int i=0; i<s.size(); i++){

            fill(v.begin(),v.end(),0);
            for(int j=i; j<s.size(); j++){

                v[s[j]-'a']++;
                if(v[s[j] - 'a'] >= k){
                    ans += s.size()-j ;
                    break ;
                }

            }
        }

        return ans ;
    }
};