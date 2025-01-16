class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {

        // nums1 ka koi sa bhi element lo usko saare nums2 ke element 
        // ke saath xor kro , toh uska (ya uski each bit ka) 
        // total mein kitni baar contibution
        // nums2.size() 
        // same for all other elements 

        vector<int> count(32,0);

        for(auto ele:nums1){

            for(int i=0; i<32; i++){

                bool bit = ele & (1<<i) ;
                if(bit){
                    count[i] += nums2.size();
                    count[i] %= 2 ;  // 0 ya 1 
                }
            }
        }

        for(auto ele:nums2){

            for(int i=0; i<32; i++){

                bool bit = ele & (1<<i) ;
                if(bit){
                    count[i] += nums1.size();
                    count[i] %= 2 ;
                }
            }
        }

        int ans = 0 ; 
        long long p = 1 ; 

        for(int i=0; i<32; i++){

            ans += p * count[i];
            p *= 2 ;
        }

        return ans ;
    }
};