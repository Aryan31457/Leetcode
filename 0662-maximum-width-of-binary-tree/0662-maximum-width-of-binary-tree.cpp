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
 #define ll unsigned long long
class Solution {
    int height(TreeNode* root){
        if(root==NULL)return 0;
        return max(height(root->left),height(root->right))+1;
    }
    void level(TreeNode* root, vector<pair<ll,ll>>&ans,int cnt,ll pos){
        if(root==NULL)return ;

        ans[cnt].first=min(pos, ans[cnt].first);
        ans[cnt].second=max(pos, ans[cnt].second);
        if(root->left){
            level(root->left,ans,cnt+1,(ll)2*pos);
        }
        if(root->right){
            level(root->right,ans,cnt+1,(ll)2*pos+1);
        }
    }
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(root==NULL)return 0;

        int depth=height(root);
        vector<pair<ll,ll>>ans(depth+1, {ULLONG_MAX, 0});

       
        // cout<<depth;
        if(root==NULL)return 0;

        level(root,ans,0,1);
        
        ll maxi=0;
        for(int i=0;i<depth;i++){
            // cout<<ans[i][ans[i].size()-1]<<" "<<ans[i][0]<<endl;
            maxi=max(ans[i].second-ans[i].first+1,maxi);
        }
        return (int)maxi;


    }
};