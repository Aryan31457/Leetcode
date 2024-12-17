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
    void mapping(TreeNode* root,unordered_map<TreeNode*,TreeNode*>&parent){
        if(root==NULL){return ;}

        if(root->left){
            mapping(root->left,parent);
            parent[root->left]=root;
        }
        if(root->right){
            mapping(root->right,parent);
            parent[root->right]=root;
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*>parent;
        mapping(root,parent);
        // for(auto i:parent){
        //     cout<<i.first->val<<" "<<i.second->val<<endl;
        // }

        unordered_map<TreeNode*,bool>visited;

        queue<TreeNode*>q;
        q.push(target);
        visited[target]=true;

        int dist=0;
        while(!q.empty())
        {
             if(dist==k){
                break;
            }
            int s=q.size();
            for(int i=0;i<s;i++){
            TreeNode* node=q.front();
            q.pop();
            if(node->left && !visited[node->left]){
                q.push(node->left);
                visited[node->left]=true;
            }
            if(node->right && !visited[node->right]){
                q.push(node->right);
                visited[node->right]=true;
            }
            if(parent[node]!=NULL && !visited[parent[node]]){
                q.push(parent[node]);
                visited[parent[node]]=true;
            }
            }
            dist++;
        }
        vector<int>ans;
        // cout<<q.size()<<endl;
        while(!q.empty()){
            TreeNode* node=q.front();
            q.pop();
            ans.push_back(node->val);
        }
        return ans;
        
    }
};