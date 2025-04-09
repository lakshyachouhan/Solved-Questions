class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        
        set<int> st;

        for(auto ele:nums){

            if(ele < k)
                return -1 ;

            st.insert(ele);
        }

        auto it = st.upper_bound(k);
        int ans = distance(it,st.end()) ;

        return ans ;
    }
};