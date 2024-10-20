class Solution {
public:
    bool parseBoolExpr(const std::string& expression) {

        stack<char> st;
        char temp = ' ', op = ' ';

        for (char ch : expression) {
            if (ch == '(' || ch == ',')
                continue;

            if (ch == 't' || ch == 'f' || ch == '!' || ch == '&' || ch == '|')
                st.push(ch); 
            else if (ch == ')') {

                bool isTrue = false, isFalse = false;

 
                while (!st.empty() && st.top() != '!' && st.top() != '&' && st.top() != '|') {
                    char val = st.top();
                    st.pop();
                    if (val == 't') isTrue = true;
                    if (val == 'f') isFalse = true;
                }

                if (!st.empty())
                    op = st.top(), st.pop(); 


                if (op == '!')     temp = isTrue ? 'f' : 't';
                else if (op == '&')    temp = (isFalse) ? 'f' : 't';
                else if (op == '|')    temp = isTrue ? 't' : 'f';
    

                st.push(temp);
            }
        }

        return st.top() == 't';
    }
};