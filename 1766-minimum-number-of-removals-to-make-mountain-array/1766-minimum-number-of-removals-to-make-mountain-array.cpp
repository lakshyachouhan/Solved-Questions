class Solution {
public:
    void LISfill(vector<int> &nums,vector<int> &LIS){

        int n = nums.size();
        vector<int> v ;
        v.push_back(nums[0]);
        LIS[0] = 1 ;

        for(int i=1; i<n; i++){

            if(nums[i] > v.back()){
                v.push_back(nums[i]);
                LIS[i] = v.size();
            }  
            else{
                auto lb = lower_bound(v.begin(),v.end(),nums[i]);
                int index = lb - v.begin();
                v[index] = nums[i];
                LIS[i] = index+1;
            }
        }
    }

    void LDSfill(vector<int> &nums,vector<int> &LDS){

        int n = nums.size();
        vector<int> v ;
        v.push_back(nums[n-1]);
        LDS[n-1] = 1 ;

        for(int i=n-2; i>=0; i--){

            if(nums[i] > v.back()){
                v.push_back(nums[i]);
                LDS[i] = v.size();
            }  
            else{
                auto lb = lower_bound(v.begin(),v.end(),nums[i]);
                int index = lb - v.begin();
                v[index] = nums[i];
                LDS[i] = index+1;
            }
        }
    }


    int minimumMountainRemovals(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> LIS(n);
        vector<int> LDS(n);

        LISfill(nums,LIS);
        LDSfill(nums,LDS);

        int ans = 0;
        for(int i=0; i<n; i++){
            
            // isme ek side ka seq missing hoga , kyoki 1 toh vo khud hi element hai 
            if(LIS[i] == 1 || LDS[i] == 1)  continue ;

            int curr = LIS[i] + LDS[i] - 1 ;
            ans = max(ans,curr);
        }

        return n - ans ;
    }
};