class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        
        unordered_map<int,int> mp1 ;
        map<int,int> occValue ;

        for(auto &ele:arr)
            mp1[ele]++;

        int totalUnique = mp1.size();

        for(auto &[ele,freq]:mp1){
            occValue[freq]++;
        }

        // jiski freq kam vo pehle
        for(auto &[occ,value]:occValue){

            while(value && k >= occ ){
                k -= occ ;
                value--;
                totalUnique--;
            }

            if(value != 0)
                break ;   // early leaving the loop
        }

        return totalUnique ;
    }
};