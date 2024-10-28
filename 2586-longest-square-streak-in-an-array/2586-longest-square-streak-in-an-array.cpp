#define ll long long

/*
Bohot time baad koi out of the box approach socha 
Work Hard , Dream Big
one day will be ours 

1 -> DP , sort ke baad , lis wala pattern
constraints dekhe 1e5 , lis wont work it is O(N^2)

kuch aur socho 
Squares ka track rkhke dekho {ele, uske subseq ki length}
agr uske ke aage wala element mila toh extend its length

*/

class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        
        unordered_map<ll,int> eleLength ;
        int ans = -1 ;
        sort(nums.rbegin(),nums.rend());

        for(auto ele:nums){

            ll sq = (ele * 1LL * ele);
            if(eleLength.count(sq) != 0){
                eleLength[ele] = eleLength[sq] + 1 ;
                ans = max(ans,eleLength[ele]);
            }

            else eleLength[ele] = 1 ;
        }

        return ans == 1 ? -1 : ans ;
    }
};