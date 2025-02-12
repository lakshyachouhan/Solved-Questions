class Solution {
public:
     int convert(int ele){

            int sum = 0 ;
            while(ele){
                sum += ele%10 ;
                ele /= 10 ;
            }

            return sum ;
     }

    int maximumSum(vector<int>& nums) {
        
        unordered_map<int,int> mp ;
        int ans = -1 ;

        for(auto &ele:nums){

            int sum = convert(ele);

            if(mp.count(sum)){

                // pehle se hai , toh sum lelo
                // & maximum dono mein se jo hai vo mp mein update
                int curr = ele + mp[sum];
                ans = max(ans,curr);
                mp[sum] = max(mp[sum],ele);
            }

            else mp[sum] = ele ;
        }

        return ans ;        
    }
};