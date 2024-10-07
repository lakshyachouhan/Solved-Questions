class Solution {
public:
    int maxArea(vector<int>& height) {
        
        int n = height.size();
        int ans = 0 ;

        // for(int i=0; i<n; i++){

        //     for(int j=i+1; j<n; j++){

        //         int curr = min(height[i],height[j]) * (j-i) ;
        //         ans = max(ans,curr);
        //     }
        // }

        // area = length * width 

        int i = 0 , j = n-1 ;
        while(i < j){
            int curr = min(height[i],height[j]) * (j-i) ;
            ans = max(ans,curr);

            if(height[i] < height[j])
               i++;
            else j-- ;

        }
        
        return ans ;
    }
};