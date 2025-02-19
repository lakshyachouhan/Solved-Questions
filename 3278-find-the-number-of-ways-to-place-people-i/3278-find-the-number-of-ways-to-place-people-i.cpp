class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        
        int n = points.size();
        int ans = 0 ;

        for(int i=0; i<n; i++){

            int cx = points[i][0] , cy = points[i][1];

            for(int j=0; j<n; j++){

                int tx = points[j][0] , ty = points[j][1];
                if(j == i || cx > tx || cy < ty) continue ;

                bool f = 1 ;

                // check if any point is inside or in line 
                for(int k=0; k<n; k++){

                    if(k == i || k == j)    continue ;
                    int kx = points[k][0] , ky = points[k][1];

                     if((cx <= kx && kx <= tx) && (ty <= ky && ky <= cy)){

                        f = 0 ;
                        break ;
                     } 

                }

                if(f)   ans++;
            }
        }

        return ans ;
    }
};