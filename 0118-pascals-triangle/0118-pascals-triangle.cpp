class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        
        // nCr = nCr-1 * (n-r+1)/r
        vector<vector<int>> ans ;
        for(int i=0; i<numRows; i++){

            vector<int> curr = {1};
            for(int r=1; r<=i; r++){

                int temp = curr.back() * (i-r+1)/r ;
                curr.push_back(temp);
            }

            ans.push_back(curr);
        }

        return ans ;
    }
};