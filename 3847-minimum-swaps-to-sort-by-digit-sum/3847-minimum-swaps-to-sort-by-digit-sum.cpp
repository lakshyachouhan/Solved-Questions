class Solution {
public:
    static bool comp(int a ,int b){

        int s1 = 0 , s2 = 0 ;
        int ele1 = a , ele2 = b ;

        while(ele1){
            s1 += ele1%10 ;
            ele1 /= 10 ;
        }

        while(ele2){
            s2 += ele2%10 ;
            ele2 /= 10 ;
        }

        if(s1 == s2)
                return a < b ;

        return s1 < s2 ;
    }
    
    int minSwaps(vector<int>& nums) {

        unordered_map<int,int> mp ;
        vector<int> temp = nums ;
        for(int i=0; i<temp.size(); i++)
                mp[temp[i]] = i ;
        
        sort(nums.begin(),nums.end(),comp);

        int ans =  0 ;
        for(int i=0; i<temp.size(); i++){

            if(nums[i] != temp[i]){
                // nums[i] correct element 
                ans++;
                int index = mp[nums[i]];               
                mp[temp[i]] = index ;
                swap(temp[index],temp[i]);
            }
        }

        return ans ;        
    }
};