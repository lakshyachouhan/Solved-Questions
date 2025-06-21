class Solution {
public:
    // Coin Piles From GFG
    int minimumCoins(vector<int>& arr, int k) {
       
       // brute force 
       // hr ek element ke equal krke dekho 
       // greedy wala nhi chala , jo ki question mis read kiya tha 
       // one operation possible hai , minimise ka 
       // lekin delete bhi toh kr skte hai 0 krke
       // left wale poore remove , right walo ko convert 
       
       sort(arr.begin(),arr.end());
       int n = arr.size();
       vector<int> prefix(n,0);
       // uss element ko include krke
       prefix[0] = arr[0];
       
       for(int i=1; i<n; i++)
            prefix[i] += prefix[i-1] + arr[i];
            
        int ans = 1e9 ;
        
        for(int i=0; i<n; i++){
            
            int removed = 0;
            if(i-1 >= 0)
                removed = prefix[i-1];
                
            int idx = upper_bound(arr.begin(),arr.end(),arr[i]+k) - arr.begin();
            // idx to last tak convert 
                
            int rightSum = prefix[n-1] - prefix[idx-1] ;
            int convertedEle = arr[i] + k ;
            int curr = removed + rightSum - (convertedEle * (n-idx)) ;
            
            ans = min(ans,curr);
        }
        
        return ans ;
       
    }

    int minimumDeletions(string word, int k) {

        // edge cases : [1 1 1 1 1 1 1 3]
        // [1 3 3 3]  
        vector<int> freq(26,0);
        
        for(auto ch:word){
            freq[ch-'a']++;
        }

        vector<int> v ;
        for(int i =0; i <26; i++){

            if(freq[i] != 0)
                v.push_back(freq[i]);
        }

        int ans = minimumCoins(v,k);
        return ans ;

    }
};