class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot){
        
        vector<int> greater , small ;
        int countp = count(nums.begin(),nums.end(),pivot);

        for(auto &ele:nums){

            if(ele > pivot) greater.push_back(ele);
            else if(ele < pivot)    small.push_back(ele);
        }   

        vector<int> ans ;
        ans.insert(ans.end(),small.begin(),small.end());

        while(countp--)     ans.push_back(pivot);
        ans.insert(ans.end(),greater.begin(),greater.end());
        
        return ans ;
    }
};