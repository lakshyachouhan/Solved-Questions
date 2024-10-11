class Solution {
public:
    int compress(vector<char>& chars) {
        
        int i = 0; // for interating in chars
        int ansIndex = 0;
        int j = 0; // for checking equal 

        while(i < chars.size()){
            
            j = i+1;
            while(j<chars.size() && chars[j]==chars[i])
               j++ ;

            chars[ansIndex++] = chars[i];
            int count = j-i;

            if(count > 1){
                string out = to_string(count);
                for(auto ch: out)
                   chars[ansIndex++] = ch ;
            }
            i = j ;
        }

    return ansIndex ;
    }
};