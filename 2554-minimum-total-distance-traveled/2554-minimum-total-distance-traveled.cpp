#define ll long long 

class Solution {
public:
    vector<vector<ll>> dp;
    ll solve(vector<int>& robot, vector<int> &factoryPos,int i,int j){

        if(i >= robot.size())   return 0 ;
        if(j >= factoryPos.size()) return 1e12 ;

        if(dp[i][j] != -1)
            return dp[i][j];

        ll include = abs(factoryPos[j]-robot[i]) + solve(robot,factoryPos,i+1,j+1) ;
        ll exclude = 0 + solve(robot,factoryPos,i,j+1);

        return dp[i][j] = min(include,exclude) ;        
    }


    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        
        sort(robot.begin(),robot.end());
        sort(factory.begin(),factory.end());

        vector<int> factoryPos ;
        for(auto &i:factory){
            while(i[1]--){
                factoryPos.push_back(i[0]);
            }
        }

        dp.resize(robot.size()+1,vector<ll>(factoryPos.size()+1,-1));
        ll ans = solve(robot,factoryPos,0,0);
        return ans ;
    }
};