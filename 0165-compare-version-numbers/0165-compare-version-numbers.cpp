class Solution {
public:
    int compareVersion(string version1, string version2) {
        
        int i = 0 , j = 0 ;

        while(i < version1.size() || j < version2.size()){

            int first = 0 , second = 0 ;
            while(i < version1.size() && version1[i] != '.'){

                first = first * 10 + (version1[i] - '0');
                i++;
            } 
            
            while(j < version2.size() && version2[j] != '.'){

                second = second * 10 + (version2[j] - '0');
                j++;
            } 

            if(first < second)
                return -1 ;

            else if(second < first)
                return 1 ;

            i++,j++;
        }

        return 0 ;
    }
};