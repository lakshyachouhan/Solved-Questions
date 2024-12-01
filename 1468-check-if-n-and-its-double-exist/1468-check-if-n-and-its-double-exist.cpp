class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        
        unordered_map<int,bool> freq ;
        for(auto ele:arr){

            if(ele % 2 == 0){
                if(freq[ele/2] || freq[ele*2] ) return true ;
            }
            else{
                if(freq[ele* 2]) return true ;
            }

            freq[ele] = 1;
        }

        return false ;
    }
};