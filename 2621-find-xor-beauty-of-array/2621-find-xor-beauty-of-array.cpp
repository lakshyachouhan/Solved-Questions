class Solution {
public:
    int xorBeauty(vector<int>& nums) {
        

        /*
    For every effective value efv(i,j,k) there is another equal efv(j,i,k) which gives efv(i,j,k) ^ efv(j,i,k) = 0 except when i=j, so if i!=j the efv doesn't contribute to the result, so we don't need to xor all triplets, we can just xor all the pairs. Furthermore for every pair efv(a,b) = (a|a)&b = a&b there is another equal efv(b,a) which again doesn't contribute to the xor because efv(a,b)^efv(b,a)=0, except when a=b, so we only need to xor all the efv(x,x,x) = (x|x)&x = x values

        */
        int ans = 0 ;

        for(auto ele:nums)
            ans ^= ele ;

        return ans ;
    }
};