class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
        
        if(bound == 0)
            return {} ;

        int i = 1 ;
        int j = 1 ;
        unordered_set<int> st ;

        while(i <= bound){
            
            j = 1 ;
            while(i + j  <= bound){
                st.insert(i+j);
                j *= y ;

                if(y == 1)  break ;
            }

            i *= x ;
            if(x == 1) break ;
        }

        return vector<int>(st.begin(),st.end());
    }
};