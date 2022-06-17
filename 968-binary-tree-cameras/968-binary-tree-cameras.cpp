class Solution {
public:
    int camera=0;
    int helper(TreeNode* root){
        if(root==NULL) return 0;
        int lchild=helper(root->left);
        int rchild=helper(root->right);
        if(lchild==1 || rchild==1){
            camera++;
            return -1;
        }
        if(lchild==-1 || rchild==-1) return 0;
        else return 1;
    }
    int minCameraCover(TreeNode* root) {
       if(helper(root)==1) {
           camera++;
       }
       return camera;
    }
};
