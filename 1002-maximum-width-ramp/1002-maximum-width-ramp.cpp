class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        
        // hr element ke liye , last se jo pehla bada element mil rha hai usse ans mil skta hai

        stack<int> st ; // decreasing stack
        int ans = 0 ;

        int mini = 1e9 ;
        for(int i=0; i<nums.size(); i++){

            if(nums[i] < mini){
                mini = nums[i];
                st.push(i);
            }
        } 

        for(int i=nums.size()-1; i>=0; i--){
            
            while(!st.empty() && nums[i] >= nums[st.top()]){

                ans = max(ans,i-st.top());
                // ab jo bhi element ka pair aur bn rha hoga usse ans chota hi ayega , kyoki < n
                st.pop();
            }
        }

        return ans;
    }
};