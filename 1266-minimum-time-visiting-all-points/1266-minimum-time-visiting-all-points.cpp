class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        
        int ans = 0 ;
        
        for(int i=1; i<points.size(); i++){

            int diffH = abs(points[i-1][0] - points[i][0]) ;
            int diffV = abs(points[i-1][1] - points[i][1]) ;

            int mini = min(diffH,diffV) ;
            int maxi = max(diffH,diffV) ;

            ans += mini ; // sqrt(2)
            ans += maxi - mini ;
        }

        return ans ; 
    }
};