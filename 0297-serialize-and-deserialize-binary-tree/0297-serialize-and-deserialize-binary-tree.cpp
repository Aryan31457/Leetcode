/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ans;
        if(root==NULL){
            return ans;
        }
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int x=q.size();
            for(int i=0;i<x;i++){
                TreeNode* node=q.front();
                q.pop();
                if(node==NULL){
                    ans+='#';
                    ans+=',';
                }
                else{
                    ans+=to_string(node->val);
                    ans+=',';
                    q.push(node->left);
                    q.push(node->right);
                }
            }
        }

        return ans;
        
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
       if(data.empty()){return NULL;}
        stringstream s(data);
        string str;
        getline(s,str,',');
        TreeNode* root=new TreeNode(stoi(str));
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode* curr=q.front();
            q.pop();
            getline(s,str,',');
            if(str=="#"){
                curr->left==NULL;
            }
            else{
                TreeNode* lefti=new TreeNode(stoi(str));
                curr->left=lefti;
                q.push(lefti);
            }

            getline(s,str,',');
            if(str=="#"){
                curr->right==NULL;
            }
            else{
                TreeNode* righti=new TreeNode(stoi(str));
                curr->right=righti;
                q.push(righti);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));