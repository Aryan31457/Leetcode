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
    int kthSmallest(TreeNode* root, int k) {
        vector<int>arr;
        if(root==NULL)return 0;
        queue<TreeNode*>q;
        q.push(root);

        while(!q.empty()){
            int s=q.size();

            for(int i=0;i<s;i++){
                TreeNode *temp=q.front();
                arr.push_back(temp->val);
                q.pop();
                if(temp->left){
                    q.push(temp->left);
                }
                if(temp->right){
                    q.push(temp->right);
                }   
            }

        }
        sort(arr.begin(),arr.end());
        return arr[k-1];
    }
};