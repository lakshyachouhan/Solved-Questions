class Solution {
public:
    int isPossible(int val,vector<int>& tops, vector<int>& bottoms){

        int n = tops.size();
        int t = 0 , b = 0 ;

        for(int i=0; i<n; i++){

            if(tops[i] == val)  t++;
            if(bottoms[i] == val)   b++;

            if(tops[i] != val && bottoms[i] != val)
                return -1 ;
        }

        return max(t,b);
    }

    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        
        int ans = -1 ;

        for(int i=1; i<=6; i++){
            
            int curr = isPossible(i,tops,bottoms) ;
            if(curr != -1)
                ans = max(ans,curr);
        }

        // itni jagah swapping krni padegi 
        return ans == -1 ? ans : tops.size()-ans ;
    }
};