/*
Jitna easy solution , utnna hi difficult que samajhna hai
isliye medium kyoki question kuch bol rha hai -> beautiful,partition,even length , minimum

CRUX -> EVEN LENGTH KE CONSECUTIVE 0/1 BANANE HAI 
USKE LIYE MIN. CHANGES 

HR DO KO CHECK KRNA OPTIMALLY RHEGA , KYOKI 4 KO CONS. BANEKE DEKHE TOH DEPENDENCY PICHE WALE PR 

ISSE ACHA DO DO KE CONSE. GROUPS BANAO 
*/

class Solution {
public:
    int minChanges(string s) {
        
        int ans = 0;
        for(int i=0; i<s.size(); i+=2){

            if(s[i] != s[i+1])  ans++;
        } 

        return ans ;        
    }
};