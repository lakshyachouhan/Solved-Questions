class Solution {
public:
    bool isCircularSentence(string sentence) {
        
        char lastChar ;
        int n = sentence.size();

        for(int i=0; i<n; i++){

            if(i-1 >=0 && sentence[i-1] == ' '){
                // cout << lastChar << endl ;
                if(lastChar != sentence[i]) 
                    return false ;
            }

            if(i+1<n && sentence[i+1] == ' '){
                // cout << i << endl ;
                lastChar = sentence[i];
            }
            
        }

        return sentence[0] == sentence[n-1];
    }
};