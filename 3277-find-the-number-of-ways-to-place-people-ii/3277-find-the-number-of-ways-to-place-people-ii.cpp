class Solution {
public:
    static bool comp(vector<int>&a,vector<int>& b){

        if(a[0] == b[0])
            return a[1] > b[1];

        return a[0] < b[0];
    }

    int numberOfPairs(vector<vector<int>>& points) {
        
        sort(points.begin(),points.end(),comp);
        // x in increasing order 
        // if x is same , then y in decreasing 
        // graph mein plot krke dekho 

        int ans = 0 ;

        for(int i=0; i<points.size(); i++){

            int cx = points[i][0] , cy = points[i][1] ; 
            int limitY = -100000000000 ;  // constraints -1e10

            for(int j=i+1; j<points.size(); j++){

                int tx = points[j][0] , ty = points[j][1];

                if(cy < ty) continue ;
                if(limitY < ty){
                    ans++;
                    limitY = ty ;
                }
            }

        }

        return ans ;
    }
};