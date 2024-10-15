class Solution {
public:
    int dp[3001][3001];
    int solve(string &source, string &pattern,unordered_set<int> &st,int i,int j){

        if(j >= pattern.size()){

            int ans = 0 ;
            while(i < source.size()){
                if(st.find(i) != st.end())   ans++;
                i++;
            }

            return ans; 
        }
            

        if(i >= source.size())  return -1e6 ;

        if(dp[i][j] != -1)
            return dp[i][j];

        int include = -1e6 , exclude = 0 ;
        if(source[i] == pattern[j])
            include = solve(source,pattern,st,i+1,j+1);

        if(st.find(i) != st.end())   exclude = 1;
        exclude += solve(source,pattern,st,i+1,j);

        return dp[i][j] =  max(include,exclude);
    }


    int maxRemovals(string source, string pattern, vector<int>& targetIndices) {
        
        unordered_set<int> st(targetIndices.begin(),targetIndices.end());

        memset(dp,-1,sizeof(dp));
        int ans = solve(source,pattern,st,0,0);
        return ans ;
    }
};