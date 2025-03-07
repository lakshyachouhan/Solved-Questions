class Solution {
public:
    void findAllPrimes(int l,int r,vector<int> &v){

        for(int ele=l; ele<=r; ele++){

            if(ele == 1 || ele == 0)
                continue ;

            bool f = 1 ;
            for(int j=2; j*j <= ele; j++){

                if(ele%j == 0){
                    f = 0 ;
                    break ;
                }
            }

            if(f)   
                v.push_back(ele);
        }

    }

    vector<int> closestPrimes(int left, int right) {
        
        vector<int> v ;
        findAllPrimes(left,right,v);

        sort(v.begin(),v.end());
        int ansIndex = 0 ;
        int diff = 1e9 ;

        if(v.size() < 2)
            return {-1,-1};

        for(int i=0; i<v.size()-1; i++){

            int curr = v[i+1] - v[i];
            if(diff > curr){
                diff = curr ;
                ansIndex = i ;
            }
        }


        return {v[ansIndex],v[ansIndex+1]};
    }
};