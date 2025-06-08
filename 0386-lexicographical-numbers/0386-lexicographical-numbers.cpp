class Solution {
public:
    vector<int> lexicalOrder(int n) {
        
        vector<int> ans ;
        int curr = 1 ;

        while(ans.size() != n){

            ans.push_back(curr);

            if(curr < n && curr*10 <= n)
                curr *= 10 ;

            else{

                while(curr >= n || curr%10 == 9)
                    curr /= 10 ;

                curr++;
            }

        }

        return ans ;
    }
};