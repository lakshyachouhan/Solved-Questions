class Solution {
public:
    bool isSafe(vector<vector<char>>& board,int row,int col,char val){
        
        int n = board.size();
        
        // row check & col check
        for(int k=0; k<n; k++){

            if(board[k][col] == val)
                return false ;

            if(board[row][k] == val)
                return false ;
        }

        for(int i=0; i<n; i++){

            int r = (3 * (row/3)) + i/3 ;
            int c = (3 * (col/3)) + i%3 ;

            if(board[r][c] == val)
                return false;
        }

        return true ;
    }

    bool solve(vector<vector<char>>& board){

        int n = board.size();
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){

                if(board[i][j] == '.'){

                    for(char k='1'; k<='9'; k++){

                        if(isSafe(board,i,j,k)){

                            board[i][j] = k ;
                            bool aageKaAns = solve(board);
                            if(aageKaAns)
                                return true ;

                            else board[i][j] = '.' ;
                        }
                    }

                    return false ;   //  important fix
                }
            }
        }

        return true ;
    }

    void solveSudoku(vector<vector<char>>& board) {
        
        solve(board);
    }
};