/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int solve(TreeNode* root, priority_queue<int> &maxHeap) {
        
        if(root == NULL)
            return 0;

        int leftH = solve(root->left, maxHeap);
        int rightH = solve(root->right, maxHeap);
        
        if(leftH == -1 || rightH == -1 || leftH != rightH)
            return -1;

        int totalNodes = leftH + rightH + 1;
        maxHeap.push(totalNodes);

        return totalNodes;
    }

    int kthLargestPerfectSubtree(TreeNode* root, int k) {
        priority_queue<int> maxHeap;
        solve(root, maxHeap);

        while(k > 1 && !maxHeap.empty()) {
            maxHeap.pop();
            k--;
        }

        if(maxHeap.empty()) return -1;
        
        return maxHeap.top();
    }
};
