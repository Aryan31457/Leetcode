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
//Using 2 stacks
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>ans;
        if(root==NULL)return ans;
        stack<TreeNode*>s1,s2;
        s1.push(root);
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
            TreeNode* node=s2.top();
            if(node!=NULL){
            if(node->left)s1.push(node->left);
            if(node->right)s1.push(node->right);
            }
        }
        while(!s2.empty()){
            TreeNode* node=s2.top();
            ans.push_back(node->val);
            s2.pop();
        }
        return ans;
    }

};