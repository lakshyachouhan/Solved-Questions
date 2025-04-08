class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        
        // ulta socho
        // instead of starting , think from ending steps 

        unordered_map<int,bool> vis ;
        int count = 0 ;
        int n = nums.size();

        for(int i=n-1; i>=0; i--){

            int ele = nums[i];
            if(vis[ele] == 1){
                break ;
            }

            count++;
            vis[ele] = 1 ;
        }

        int rem = n - count ; 

        int ans = rem/3 ;
        if(rem%3 != 0)  
            ans++;

        return ans ;
    }
};