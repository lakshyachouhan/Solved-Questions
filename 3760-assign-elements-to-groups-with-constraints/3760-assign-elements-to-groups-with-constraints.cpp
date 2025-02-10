class Solution {
public:
    vector<int> assignElements(vector<int>& groups, vector<int>& elements) {
        
        vector<int> ans ;
        unordered_map<int,int> mp ; // {element,index}

        for(int i=0; i<elements.size(); i++){

            if(mp.count(elements[i]) == 0){
                mp[elements[i]] = i ;
            }
        }

        for(auto grp:groups){

            int curr = 1e9 ;
            for(int i=1; i*i<=grp; i++){

                if(grp%i == 0 && mp.count(i))
                    curr = min(curr,mp[i]);

                // apn sqrt(grp) tak hi check kr rhe hai 
                // lekin grp = 4 , toh 4 ko bhi check krna chaiye
                // isliye when i = 1 , usme div = 4 
                // wala check ho jayega 
                
                int div = grp/i ;
                if(grp%div == 0 && mp.count(div))
                    curr = min(curr,mp[div]);
            }

            if(curr == 1e9) ans.push_back(-1);
            else ans.push_back(curr);            
        }

        return ans ;
    }
};