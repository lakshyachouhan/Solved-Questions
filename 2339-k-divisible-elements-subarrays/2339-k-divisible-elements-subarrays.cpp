class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) {
        
        set<vector<int> > st ;

        for(int i=0; i<nums.size(); i++){
            int count = 0 ;
            vector<int> curr ;
            for(int j=i; j<nums.size();j++){

                curr.push_back(nums[j]);
                if(nums[j]%p == 0) count++;
                if(count > k) break ;
                st.insert(curr);
            }
        }

        return st.size();
    }
};