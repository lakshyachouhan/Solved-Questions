class Solution {
public:

// invalid hamesha issi tyoe se rhenge , koi bhi test case ho 
// ]]]]]][[[[[
// toh ]][[ close = 2 , even , ans = 1 , [][]
// ]]][[[  close = 3 , odd , ans = 2 , [][][]
    int minSwaps(string s) {
        
        stack<char> st ;

        for(auto &ch:s){

            if(ch == '['){
                st.push(ch);
            }

            else{
                if(!st.empty() && st.top() == '[')
                    st.pop();

                else st.push(ch);
            }
        }

        if(st.empty()) return 0 ;

        // if(st.size() == 2)   return 1 ;

        int close = st.size()/2 ;

        if(close&1)
            return close/2 +1 ;

        else return close/2 ;
    }
};