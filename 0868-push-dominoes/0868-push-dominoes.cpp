class Solution {
public:
    bool check(string &dominoes){

          int n = dominoes.size();
        vector<int> left(n,0) , right(n,0);
        int c = 0 ;

        for(int i=0; i<n; i++){
            
            char ch = dominoes[i] ;
            if(ch == 'L')
                c = 0 ;

            else if(ch == 'R')
                c = 1 ;

            else{
            left[i] = max(c,0) ;
            c--;
            }
        }

        for(int i=n-1; i>=0; i--){
            
            char ch = dominoes[i] ;
            if(ch == 'L')
                c = 1 ;

            else if(ch == 'R')
                c = 0 ;

            else{
            right[i] = max(c,0) ;
            c--;
            }
        }

        bool change = 0 ;
        for(int i=0; i<n; i++){

            char &ch = dominoes[i] ;
            if(ch == '.'){

                // cout << i << "  " << left[i] << " " << right[i] << endl ;
                if(left[i] > right[i])
                    ch = 'R' , change = 1;

                else if(left[i] < right[i])
                    ch = 'L' , change = 1; 
            }
        }

        return change ;
    }

    string pushDominoes(string dominoes) {
        
        bool change = check(dominoes);
        while(change){
            change = check(dominoes);
        }

        return dominoes ;
    }
};