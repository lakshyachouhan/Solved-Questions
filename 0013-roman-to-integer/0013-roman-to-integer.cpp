class Solution {
public:
    int romanToInt(string s) {
        
    int values[] = { 900,400,90,40,9,4,1000,500,100,50,10,5,1};//1000 500 100 50 10 5 1

    string roman[] = {"CM","CD","XC","XL","IX","IV","M","D","C","L","X","V","I"};

    int i=0 ; 
    int ans = 0;

    while(s.length() != 0){

        while(s.find(roman[i]) != string::npos){
            ans += values[i];
            s.erase(s.find(roman[i]),roman[i].length());
        }
        i++;
    }

    return ans ;
    }
};