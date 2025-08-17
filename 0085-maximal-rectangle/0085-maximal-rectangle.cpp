class Solution {
public:
    vector<int> nextSmaller(vector<int> &arr){

        int n = arr.size();
        vector<int> ans(n);
        stack<int> st ;

        for(int i=n-1; i>=0; i--){

            int curr = arr[i];
            while(!st.empty() && arr[st.top()] >= curr)
                st.pop();

            if(st.empty())  ans[i] = n ;
            else ans[i] = st.top();

            st.push(i);
        }

        return ans ;
    }

    vector<int> prevSmaller(vector<int> &arr){

        int n = arr.size();
        vector<int> ans(n);
        stack<int> st ;

        for(int i=0; i<n; i++){

            int curr = arr[i];
            while(!st.empty() && arr[st.top()] > curr)
                st.pop();

            if(st.empty())  ans[i] = -1 ;
            else ans[i] = st.top();

            st.push(i);
        }

        return ans ;
    }

    int area(vector<int> &arr){

        vector<int> n = nextSmaller(arr);
        vector<int> p = prevSmaller(arr);

        int ans = 0 ;
        for(int i=0; i<arr.size(); i++){

            int l = arr[i];
            int b = n[i]-p[i]-1 ;
            int curr = l * b ;

            ans = max(ans,curr);
        }

        return ans ;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        
        vector<vector<int>> v ;
        for(int i=0; i<matrix.size(); i++){

            vector<int> temp ;
            for(auto ele:matrix[i]){
                if(ele == '1')  temp.push_back(1);
                else temp.push_back(0);
            }

            v.push_back(temp);
        }


        int ans = area(v[0]);
        for(int i=1; i<v.size(); i++){

            for(int j=0; j<v[i].size(); j++){

                if(v[i][j] != 0)
                    v[i][j] += v[i-1][j];
            }

            int curr = area(v[i]);
            ans = max(ans,curr);
        }

        return ans ;
    }
};