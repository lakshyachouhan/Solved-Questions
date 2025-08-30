class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
        // all rows check
        int n = board.size();
        for(int i=0; i<n; i++){
            set<char> st ;
            for(int j=0; j<n; j++){
                char ch = board[i][j];
                if(ch != '.'){
                    if(st.find(ch) != st.end())
                        return false ;
                    else st.insert(ch);
                }
            }
                
        }

        // all columns check 
         for(int j=0; j<n; j++){
            set<char> st ;
            for(int i=0; i<n; i++){
                char ch = board[i][j];
                if(ch != '.'){
                    if(st.find(ch) != st.end())
                        return false ;
                    else st.insert(ch);
                }
            }
                
        }

        // checking each submatrix of 3 *3
         for(int i=0; i<n; i+=3){

            // is row ke all check
            for(int j=0; j<n; j+=3){
                
                set<char> st ;
                for(int k=0; k<n; k++){

                char ch = board[3*(i/3) + k/3][3*(j/3) + k%3];
                if(ch != '.'){
                    if(st.find(ch) != st.end())
                        return false ;
                    else st.insert(ch);
                    }
                }
            }    
        }

        return true ;        
    }
};