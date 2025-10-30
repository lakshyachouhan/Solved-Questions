class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        
        int ans = 0 ;
        int incOp = 0 ;

        for(auto ele:target){

            if(ele < incOp)
                incOp = ele ;

            else if(ele > incOp){
                ans += ele - incOp ;
                incOp = ele ;
            }
        }

        return ans ;
    }
};