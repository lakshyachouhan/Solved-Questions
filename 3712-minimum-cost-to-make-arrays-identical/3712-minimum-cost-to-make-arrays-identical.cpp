#define ll long long 

class Solution {
public:
    long long minCost(vector<int>& arr, vector<int>& brr, long long k) {

        ll ans = 0 ;
        // initially calculate 
        for(int i=0; i<arr.size(); i++){

            ans += abs(brr[i]-arr[i]);
        }

        ll curr = k ;
        sort(arr.begin(),arr.end());
        sort(brr.begin(),brr.end());

        // split ke baad matlab +k
        for(int i=0; i<arr.size(); i++){

            curr += abs(brr[i]-arr[i]);
        }

        return min(curr,ans);
    }
};