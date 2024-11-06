class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        
        vector<int> v(nums);
        sort(v.begin(),v.end());

        for(int i=0; i<v.size(); i++){

            set<int> st ;
            for(int j=i;j<v.size(); j++){

                st.insert(__builtin_popcount(nums[j]));

                if(nums[j] == v[i]){
                    if(st.size() > 1)   return false ;
                    swap(nums[j],nums[i]);
                }
            }
        }

        return true ;
    }
};