class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        
        int n = nums.size();
        vector<int> breakPoints;
        for(int i=1; i<n; i++){

            if((nums[i]&1) == (nums[i-1]&1)){
                breakPoints.push_back(i-1); // noted 
            }
        }

        vector<bool> ans ;
        for(auto i:queries){
            
            int s = i[0] , e = i[1];
            if (e == s + 1) {
                ans.push_back((nums[s] & 1) != (nums[e] & 1));
                continue;
            }

            auto it = lower_bound(breakPoints.begin(),breakPoints.end(),s);

            if(it == breakPoints.end() || *it >= e)  ans.push_back(1);
            else ans.push_back(0);
        }

        return ans ;
    }
};

