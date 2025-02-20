class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        
        unordered_set<string> st(nums.begin(),nums.end()) ;

        int n = nums.size();
        int range = (1 << n) - 1 ; // 2 ^ n -1 

        for(int i=0; i<=range; i++){

            int num = i ;
            string curr = "";

            for(int len=0; len<n; len++){

                int bit = num & 1 ;
                num >>= 1 ;
                curr += to_string(bit);
            }

            reverse(curr.begin(),curr.end());
            if(st.find(curr) == st.end())
                return curr ;
        }

        return " " ;
    }
};