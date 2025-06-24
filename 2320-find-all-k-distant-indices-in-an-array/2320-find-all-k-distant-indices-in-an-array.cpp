class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        
        vector<int> ans ;

        int n = nums.size();
        int found = n+2*k  ;
        vector<int> left(n);

        for(int i=0; i<n; i++){

            if(nums[i] == key)
                found = i ;

            left[i] = abs(i-found) ;
        }

        found = n+ 2*k ;
        for(int i=n-1; i>=0; i--){

            if(nums[i] == key)
                found = i ;

           left[i] = min(left[i],abs(found-i)) ;

            cout << i << "  " << left[i] << endl ;
            if(left[i] <= k)
                ans.push_back(i);
        }

        sort(ans.begin(),ans.end());
        return ans ;
    }
};