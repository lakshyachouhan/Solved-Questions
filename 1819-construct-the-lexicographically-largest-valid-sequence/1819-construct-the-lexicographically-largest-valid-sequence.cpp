class Solution {
public:
    bool solve(int n,vector<int>& build,vector<int> &freq,int index){

        if(index >= build.size())
            return true ;

        if(build[index] != 0)
            return solve(n,build,freq,index+1);

        for(int i=n; i>=1; i--){

            if(freq[i] != 0){

                // place krke dekho 
                if(i == 1){
                    build[index] = 1 ;

                    freq[i] = 0 ;
                    if(solve(n,build,freq,index+1))
                            return 1 ;

                    // backtrack
                    freq[i] = 1 ;
                    build[index] = 0 ;
                }

                else{
                    // yha pr i & index+i dono pr place 
                    if(index+i < build.size() && build[index+i] == 0){
                        build[index] = i ;
                        build[index+i] = i ;
                        // cout << i << "  " << index << endl ;

                    freq[i] = 0 ; 
                
                    if(solve(n,build,freq,index+1))
                        return 1 ;

                    // backtrack
                    freq[i] = 2 ;
                    build[index] = 0 ;
                    build[index+i] = 0 ;
                    }
                  
                }
            }
        }

        build[index] = 0 ;
        return false ;
    }

    vector<int> constructDistancedSequence(int n) {
        
        vector<int> build(2*n-1,0);
        vector<int> freq(n+1,2);

        freq[1] = 1 ;
        freq[0] = 0 ;
        solve(n,build,freq,0);

        return build ;
    }
};