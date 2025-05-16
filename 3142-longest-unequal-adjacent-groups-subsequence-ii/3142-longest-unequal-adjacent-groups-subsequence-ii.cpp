class Solution {
public:
    bool check(vector<string>& words, vector<int>& groups,int prev,int i){

        int count = 0 ;
        if(words[i].size() != words[prev].size() || groups[i] == groups[prev])
            return false ;

        for(int j=0; j<words[i].size(); j++){

            if(words[i][j] != words[prev][j])
                count++;

            if(count > 1)
                return false ;
        }

        return count == 1 ;
    }

    int dp[1001][1001];
    int solve(vector<string>& words, vector<int>& groups,int prev,int i){

        if(i >= words.size())
            return 0 ;

        if(dp[i][prev+1] != -1)
            return dp[i][prev+1];

        int include = 0 ;
        if(prev == -1 || check(words,groups,i,prev))
            include = 1 + solve(words,groups,i,i+1);

        int exclude = 0 + solve(words,groups,prev,i+1);

        return dp[i][prev+1] = max(include,exclude);

    }


    vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups) {
        
        memset(dp,-1,sizeof(dp));
        int ans1 = solve(words,groups,-1,0);
        // cout << ans1 << endl ;

        // print krke dekho , kaise ans ban rha hai , phir build 
        // for(int i=0; i<words.size()+1; i++){
        //     for(int j=0; j<words.size()+1; j++)
        //         cout << dp[i][j] << " " ;

        //         cout << endl ;
        // }

        // dp mein answers ki length store hai each index ki 

        // vector<string> ans ;
        // int curr = 1 ;
        // for(int i=words.size()+1; i>=0; i--){
        //     for(int j=words.size()+1; j>=0; j--){

        //         if(dp[i][j] >= curr){

        //             if(!ans.empty() && ans.back().size() != words[i].size())
        //                 continue ;

        //             ans.push_back(words[i]);
        //             curr++;
        //             break ;
        //         }
        //     }
        // }

        // reverse(ans.begin(),ans.end());

            // initialize the base‐case row so dp[n][*] == 0
            int n = words.size();
        for (int prevIdx = 0; prevIdx <= n; ++prevIdx)
            dp[n][prevIdx] = 0;


        vector<string> ans;
        int prev = -1, i = 0;
        while (i < words.size()) {

            int exc = dp[i+1][prev+1];
            int inc = (prev==-1 || check(words,groups,i,prev))
                       ? 1 + dp[i+1][i+1]
                       : -1;

            if (inc >= exc && inc > 0) {
                // taking i is at least as good as skipping
                ans.push_back(words[i]);
                prev = i;
                i++;
            } 
            
            else i++; // skip i 
        }
        
        return ans ;
    }
};