class Solution {
public:
    bool  isValid(string &s){

        if(s == "")
            return false ;

        for(auto &ch:s){

            if(isdigit(ch) || isalpha(ch) || ch == '_')
                continue ;

            else return false ;
        }

        return true ;
    }

    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {

        vector<string> e, g, p , r  ;

        for(int i=0; i<code.size(); i++){

            string cod = code[i] , type = businessLine[i];

            if(isActive[i] == false || !isValid(cod))
                continue ;

            if(type == "electronics")
                e.push_back(cod);

            else if(type == "grocery")
                g.push_back(cod);

            else if(type == "pharmacy")
                p.push_back(cod);

            else if(type == "restaurant")
                r.push_back(cod);            
        }        

        vector<string> ans ;
        sort(e.begin(),e.end());
        sort(g.begin(),g.end());
        sort(p.begin(),p.end());
        sort(r.begin(),r.end());

        ans.insert(ans.end(),e.begin(),e.end());
        ans.insert(ans.end(),g.begin(),g.end());
        ans.insert(ans.end(),p.begin(),p.end());
        ans.insert(ans.end(),r.begin(),r.end());

        return ans ;
    }
};