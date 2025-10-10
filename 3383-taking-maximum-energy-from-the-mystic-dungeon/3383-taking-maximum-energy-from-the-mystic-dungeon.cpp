class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {

        int n = energy.size();

        int ans = -1e9 ;
        // initial answers by starting from last k 
        for(int i=max(n-k,0); i<n; i++){

            ans = max(ans,energy[i]);
        }
        
        for(int i=k; i<n; i++){
            
            if(energy[i-k] < 0)
                continue ;
                
            energy[i] += energy[i-k];
        }

        for(int i=max(n-k,0); i<n; i++){

            ans = max(ans,energy[i]);
        }

        return ans ;        
    }
};