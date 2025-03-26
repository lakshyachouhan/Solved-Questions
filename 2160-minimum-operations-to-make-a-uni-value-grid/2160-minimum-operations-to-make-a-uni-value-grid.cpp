class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        
        // Kab Possible nhi hai :
        // jab no. ka remainder same nhi ho 
        // toh sabka remainder same aana chaiye x se 
        // divide krne pr 

        // Kisse replace for minimum : Median 

        vector<int> v ;
        int m = grid.size() ;
        int n = grid[0].size() ;
        unordered_set<int> st ;

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){

                st.insert(grid[i][j] % x);
                v.push_back(grid[i][j]);

                if(st.size() == 2)
                    return -1 ;
            }
        }

        sort(v.begin(),v.end());

        int total = m*n ;
        int median = v[total/2];

        int ans = 0 ;

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){

                ans += abs(median-grid[i][j]) / x ;
            }
        }

        return ans ;
    }
};