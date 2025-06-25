class Solution {
public:
    int solve(string &s1,string &s2,int i,int j){

        if(i >= s1.size())
            return s2.size() - j ;

        if(j >= s2.size())
            return s1.size() - i ;

        if(s1[i] == s2[j])
            return 1 + solve(s1,s2,i+1,j+1);

        else{
            int op1 = 1 + solve(s1,s2,i,j+1);
            int op2 = 1 + solve(s1,s2,i+1,j);

            return min(op1,op2);
        }
    }

    int solveMem(string &s1,string &s2,int i,int j, vector<vector<int>> &dp){

        if(i >= s1.size())
            return s2.size() - j ;

        if(j >= s2.size())
            return s1.size() - i ;

        if(dp[i][j] != -1)
            return dp[i][j];

        int ans ;
        if(s1[i] == s2[j])
            ans = 1 + solveMem(s1,s2,i+1,j+1,dp);

        else{
            int op1 = 1 + solveMem(s1,s2,i,j+1,dp);
            int op2 = 1 + solveMem(s1,s2,i+1,j,dp);

            ans = min(op1,op2);
        }

        return dp[i][j] = ans ;
    }
    
    void solveTab(string &s1,string &s2, vector<vector<int>> &dp){

        for(int j=0; j<s2.size(); j++)
            dp[s1.size()][j] = s2.size() - j ;

        for(int i=0; i<s1.size(); i++)
            dp[i][s2.size()] = s1.size() - i ;

        dp[s1.size()][s2.size()] = 0; // MISSING
        // dhyan rkhna 

        for(int i=s1.size()-1; i>=0; i--){
            for(int j=s2.size()-1; j>=0; j--){

                    int ans ;
                    if(s1[i] == s2[j])
                        ans = 1 + dp[i+1][j+1];

                    else{
                        int op1 = 1 + dp[i][j+1];
                        int op2 = 1 + dp[i+1][j];
                        ans = min(op1,op2);
                    }

                    dp[i][j] = ans ;

                    // cout << dp[i][j] << " ";
            }

            cout << endl ;
        }

    }

    string shortestCommonSupersequence(string s1, string s2) {
        
        // solve(s1,s2,0,0);

        vector<vector<int>> dp(s1.size()+1,vector<int>(s2.size()+1,-1));
        // solveMem(s1,s2,0,0,dp);

        // dp table fill ho chuka hai 
        // ab uska use krke ans string build 
        // lekin ye tabulation se krenge toh better understanding 

        solveTab(s1,s2,dp);

        string ans = "";
        int i = 0, j = 0;

        while (i < s1.size() && j < s2.size()) {

            if (s1[i] == s2[j]) {
                ans += s1[i];
                i++, j++;
            } 
            
            else {
                // jo length choti thi , wo wale se character lo 
                // dry run in dp table 
                if(dp[i][j+1] < dp[i+1][j]){
                    ans += s2[j] ;
                    j++;
                }

                else 
                        ans += s1[i++];
                
                // else {
                //     // When both choices are equal length, pick lexicographically smaller
                //     if (s1[i] <= s2[j]) 
                //             ans += s1[i++];
                    
                //     else ans += s2[j++];
                // }

            }
        }

        while (i < s1.size()) ans.push_back(s1[i++]);
        while (j < s2.size()) ans.push_back(s2[j++]);

        return ans;
    }       
};