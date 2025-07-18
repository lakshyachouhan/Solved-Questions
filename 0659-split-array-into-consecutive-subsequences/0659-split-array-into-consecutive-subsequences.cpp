class Solution {
public:
    bool isPossible(vector<int>& nums) {
        
        // two possibilities for each element 
        // whether extend previous 
        // or start a new one 

        unordered_map<int,int> freq, end ;
        for(auto ele:nums)
            freq[ele]++;

        for(auto ele:nums){

            if(freq[ele] == 0)
                continue ;

            if(end[ele-1] > 0){
                end[ele-1]--;
                end[ele]++;
            }

            else if(freq[ele+1] && freq[ele+2]){
                freq[ele+1]--;
                freq[ele+2]--;
                end[ele+2]++;
            }

            else return false ;

            freq[ele]--;
        }

        return true ;
    }
};