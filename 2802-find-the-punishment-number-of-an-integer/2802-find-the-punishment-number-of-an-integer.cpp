class Solution {
public:
    bool isPossible(string &s,int curr,int target,int index){
        
        // cout << s << " Call for " << index  << " " << curr << endl ;
        if(index >= s.size())
            return curr == target ;

        if(target < curr)
            return false ;

        // check all possible substrings 
        for(int i=index; i<s.size(); i++){

                                // starting index , length
            string temp = s.substr(index,i-index+1);
            int num = stoi(temp);

            curr += num ;
            bool aageKaAns = isPossible(s,curr,target,i+1);
            if(aageKaAns)
                return true ;

            curr -= num ;
        }

        return false ;
    }


    int punishmentNumber(int n) {
        
        int ans = 0 ;

        for(int i=1; i<=n; i++){

            int sq = i * i ;
            int curr = 0 ;
            string s = to_string(sq);

            if(isPossible(s,curr,i,0)){
                // cout << i << endl ;
                ans += sq ;
            }
                
        }

        return ans ;
    }
};