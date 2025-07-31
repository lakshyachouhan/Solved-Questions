class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        
        // bitwise ORs of subarrays ending at index i 
        unordered_set<int> curr ;
        unordered_set<int> ans ;
        int n = arr.size();

        for(int i=0; i<n; i++){
            
            unordered_set<int> prev(curr) ;
            curr.clear();

            for(auto ele:prev){
                curr.insert(ele | arr[i]);
                ans.insert(ele | arr[i]);
            }

            ans.insert(arr[i]);
            curr.insert(arr[i]);
        }

        return ans.size();
    }
};