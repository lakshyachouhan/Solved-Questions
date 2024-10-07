class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
    sort(nums.begin(),nums.end());
    vector<vector<int>> ans ;
    set<vector<int>> s;
    int j , k;
    int n = nums.size();

    for(int i=0; i<n; i++){
        j = i+1 ; k = n-1 ;

        while(j < k){
            if(nums[i]+nums[j]+nums[k] == 0)
                s.insert({nums[i],nums[j++],nums[k--]});
            
            else if(nums[i]+nums[j]+nums[k] > 0)
                 k--;

            else j++ ;
              
        }
    }

    for(auto v:s){
        ans.push_back(v);
    }
    return ans ;
    }
};