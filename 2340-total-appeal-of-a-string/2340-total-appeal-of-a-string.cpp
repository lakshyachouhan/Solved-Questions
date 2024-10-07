class Solution {
public:
    long long appealSum(string s) {
        
        long long ans = 0 ;
        unordered_map<char,int> prevIndex ;
        int n = s.size();

        for(int i=0; i<n; i++){

            long long curr ;
            char ch = s[i] ;
            if(prevIndex.find(ch) != prevIndex.end())
                curr = (i+1 - (prevIndex[ch]+1)) * (n-i);

            else curr = (i+1) * (n-i);

            ans += curr ; 
            prevIndex[ch] = i ;
        }

        return ans ;
    }
};