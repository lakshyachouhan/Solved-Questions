class Solution {
public:
    vector<int> zigzagTraversal(vector<vector<int>>& grid) {

        vector<int> temp ;

        int i = 0 ; 
        bool left = 0 ;

        while(i < grid.size()){

            if(left == 0){

                for(int j=0; j<grid[0].size(); j++)
                    temp.push_back(grid[i][j]);

                left = 1 ;
            }

            else{
                for(int j=grid[0].size()-1; j>=0; j--)
                    temp.push_back(grid[i][j]);

                left = 0 ;
            }

            i++;
        }

        vector<int> ans ;
        for(int i=0; i<temp.size(); i+=2)
                ans.push_back(temp[i]);

        return ans ;
                
    }
};