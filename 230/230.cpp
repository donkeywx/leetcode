/*
 * @lc app=leetcode.cn id=230 lang=cpp
 *
 * [230] 二叉搜索树中第K小的元素
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:

    int kthSmallest(TreeNode* root, int k) {
        int res = 0;        
        stack<TreeNode*> st;

        TreeNode* cur = root;
        while(!st.empty() || cur)
        {
            while(nullptr != cur)
            {
                st.push(cur);
                cur = cur->left;
            }

            TreeNode* tmp = st.top();
            st.pop();
            k--;
            if (k == 0)
            {
                res = tmp->val;
                break;
            }

            cur = tmp->right;
        }

        return res;
    }
};
// @lc code=end

