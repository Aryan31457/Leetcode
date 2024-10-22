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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        vector<long long >level;
        queue<TreeNode*>q;
        q.push(root);
            while(!q.empty()){
           long long sum=0;
           int x=q.size();
            for(int i=0;i<x;i++){
                TreeNode* topi=q.front();
                sum+=topi->val;
                if(topi->left){
                q.push(topi->left);
                }
                if(topi->right){
                q.push(topi->right);
                } 
                q.pop();
            }
            level.push_back(sum);
            }
            sort(level.begin(),level.end());
            int n=level.size();
            if(n-k<0)return -1;
            return level[n-k];

        
    }
};