class Solution {
public:
    void includeEle(vector<int> &count,int ele){

        for(int i=0; i<32; i++){

            bool bit = (1<<i) & ele ;

            if(bit)
                count[i]++; 
        }
    }

    void excludeEle(vector<int> &count,int ele){

        for(int i=0; i<32; i++){

            bool bit = (1<<i) & ele ;

            if(bit)
                count[i]--; 
        }
    }

    int check(vector<int> &count){

        int ele = 0 ;
        for(int i=0; i<32; i++){

            if(count[i])
                ele |= (1<<i);
        }

        return ele ;
    }

    vector<int> smallestSubarrays(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> count(32,0);
        vector<int> ans(n);

        // max. OR kitna ban skta hai iss element se 
        // agr iske equal nhi hai , toh phir j ko move 
        // otherwise agr equal hai , toh phir yhi max. hai
        // j ko move krne se bhi no change 
        vector<int> suffixOR(n);
        suffixOR[n-1] = nums[n-1];

        for(int i=n-2; i>=0; i--){

            suffixOR[i] = suffixOR[i+1] | nums[i];
        }
        
        int j = 0 ;
        for(int i=0; i<n; i++){

            while(j < n && check(count) != suffixOR[i]){
                includeEle(count,nums[j]);
                j++;
            }
            
            // cout << i << "   " << check(count) << "   " << j << endl ;
            ans[i] =   max(j-i,1)  ; // [0]
            excludeEle(count,nums[i]);
        }

        return ans ;
    }
};