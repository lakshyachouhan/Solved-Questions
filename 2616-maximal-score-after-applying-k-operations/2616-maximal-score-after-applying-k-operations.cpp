#define ll long long 
class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        
        priority_queue<int> maxHeap(nums.begin(),nums.end()) ;
        ll ans = 0 ;

        while(k--){

            auto top = maxHeap.top();
            maxHeap.pop();
                        cout << top << endl ;


            ans += top ;
            top = ceil((double)top/3.0) ;
            maxHeap.push(top);
        }

        return ans ;        
    }
};