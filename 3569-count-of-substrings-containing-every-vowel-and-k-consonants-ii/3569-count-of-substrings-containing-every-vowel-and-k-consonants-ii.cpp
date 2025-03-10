#define ll long long 

class Solution {
public:
    bool isVowel(char &ch){

        return ch == 'a' || ch == 'e' 
        || ch == 'o' || ch == 'i' || ch == 'u'  ;
    }

    long long countOfSubstrings(string word, int k) {
        
        ll ans =  0;
        unordered_map<char,int> mp ;
        int n = word.size();
        vector<int> nextConsonant(n,n);
        int next = n ;

        for(int i=n-1; i>=0; i--){

            nextConsonant[i] = next ;
            if(!isVowel(word[i]))
                next = i ;
        }

        int i = 0 , j = 0 ;
        int cons = 0 ;
        while(j < n){

            if(isVowel(word[j]))
                mp[word[j]]++;

            else cons++;

            while(cons > k){

                if(isVowel(word[i])){
                     mp[word[i]]--;
                     if(mp[word[i]] == 0)
                        mp.erase(word[i]) ;
                }
                    
                else cons--;
                i++;
            }

            // minimise krte time ans le rhe hai 
            while(mp.size() == 5 && cons == k){

                ans += nextConsonant[j] - j ; // aage ke jitne poore add
                if(isVowel(word[i])){
                     mp[word[i]]--;
                     if(mp[word[i]] == 0)
                        mp.erase(word[i]) ;
                }
                    
                else cons--;
                i++;
            }

            j++;
        }

        while(mp.size() == 5 && cons == k){

                ans += nextConsonant[j] - j ; // aage ke jitne poore add
                if(isVowel(word[i])){
                     mp[word[i]]--;
                     if(mp[word[i]] == 0)
                        mp.erase(word[i]) ;
                }
                    
                else cons--;
                i++;
        }

        return ans ;

    }
};