class Solution {
public:
    int trap(vector<int>& height) {
        // # DRY RUN SE KHUD SE KIYA AFTER ONE YEAR 
        // DO DRY RUN , THEN GO TO CODE
        int n = height.size();
        int leftMaxi = height[0];
        vector<int> leftMax(n,0);
        vector<int> rightMax(n,0);

        for(int i=1; i<n; i++){

            leftMax[i] = max(height[i-1],leftMax[i-1]);
            // or use a maxi variable 
        }

        for(int i=n-2; i>=0; i--){

            rightMax[i] = max(rightMax[i+1],height[i+1]);
        }

        int ans = 0;
        for(int i=0; i<n; i++){

            if(min(leftMax[i],rightMax[i]) > height[i]){
                ans += min(leftMax[i],rightMax[i]) - height[i] ; 
                // itna water  i wala store kr skta hai
            }
        }

        return ans ;
    }
};