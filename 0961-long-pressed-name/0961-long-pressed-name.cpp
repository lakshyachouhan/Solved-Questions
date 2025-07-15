class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        
        int i = 0 , j = 0 ;

        while(i < typed.size()){

            if(j<name.size() && typed[i] == name[j])
                i++,j++;

            else if(j>0 && typed[i] == name[j-1])
                i++;

            else return false ;
        }

        return j == name.size() ;
    }
};