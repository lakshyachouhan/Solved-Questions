class Solution {
public:
    TreeNode* solve(int currH, int &i, string &s) {

        cout << currH << "  " << s[i] << endl;
        if (i >= s.size())
            return NULL;

        int count = 0, j = i;
        while (j < s.size() && s[j] == '-') {
            count++;
            j++;
        }

        if (count != currH + 1)
            return NULL;

        int val = 0;
        while (j < s.size() && isdigit(s[j])) {
            val = val * 10 + (s[j] - '0');
            j++;
        }

        i = j; 
        TreeNode* root = new TreeNode(val);

        root->left = solve(currH + 1, i, s);
        root->right = solve(currH + 1, i, s);

        return root;
    }

    TreeNode* recoverFromPreorder(string traversal) {

        int i = 0;
        return solve(-1, i, traversal);
    }
};
