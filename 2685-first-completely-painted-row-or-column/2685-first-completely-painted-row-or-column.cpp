class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        
        map<int , pair<int,int> > eleIndexes ;
        int m = mat.size();
        int n = mat[0].size() ;

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){

                eleIndexes[mat[i][j]] = {i,j};
            }
        }

        vector<int> row(m,0) , col(n,0);

        for(int i=0; i<arr.size(); i++){

            int ele = arr[i];
            auto coor = eleIndexes[ele];

            int x = coor.first , y = coor.second ;
            row[x]++;
            col[y]++;

            if(row[x] == n || col[y] == m)
                return i ;
        }

        return -1 ;
    }
};