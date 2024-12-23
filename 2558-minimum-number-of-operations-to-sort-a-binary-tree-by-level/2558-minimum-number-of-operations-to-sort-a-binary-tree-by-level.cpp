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
    int minSwaps(vector<int>& arr) {
       vector<pair<int,int>>temp;
       int n=arr.size();
       for(int i=0;i<n;i++){
           temp.push_back({arr[i],i});
       }
       sort(temp.begin(),temp.end());
       int ans=0;
       for(int i=0;i<n;i++){
           while(i!=temp[i].second){
               swap(temp[i],temp[temp[i].second]);
               ans++;
           }
       }
       return ans;
    }
    void solve(TreeNode* root,vector<vector<int>>&level){
        if(root==NULL)return;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            vector<int>temp;
            int s=q.size();
            for(int i=0;i<s;i++){
                TreeNode *node=q.front();
                q.pop();
                temp.push_back(node->val);
                if(node->left){
                    q.push(node->left);
                }
                if(node->right){
                    q.push(node->right);
                }
            }
            level.push_back(temp);
        }
    }
    int minimumOperations(TreeNode* root) {
        vector<vector<int>>level;
        solve(root,level);
        int ans=0;
        for(int i=0;i<level.size();i++){
            ans+=minSwaps(level[i]);
        }
        return ans;
        
    }
};