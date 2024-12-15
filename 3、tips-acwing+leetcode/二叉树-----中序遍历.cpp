//显式递归
class Solution1 {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ret;
        if(root==NULL)return ret;
        inorderHelper(ret,root);
        return ret;
    }
private:
    void inorderHelper(vector<int>& ret,TreeNode* root)
    {
        if(root==NULL)return;
        inorderHelper(ret,root->left);
        ret.push_back(root->val);
        inorderHelper(ret,root->right);
    }
};

//栈
class Solution2 {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ret;
        if(root==NULL)return ret;
        TreeNode *curr=root;
        stack<TreeNode*> st;
        while(!st.empty()||curr!=NULL)
        {
            while(curr!=NULL)
            {
                st.push(curr);
                curr=curr->left;
            }
            curr=st.top();
            st.pop();
            ret.push_back(curr->val);
            curr=curr->right;
        }
        return ret;
    }
};


//Morris中序
class Solution3 {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ret;
        if(root==NULL)return ret;
        TreeNode *curr=root;
        TreeNode *pre;
        while(curr)
        {
            if(curr->left==NULL)
            {
                ret.push_back(curr->val);
                curr=curr->right;
            }
            else
            {
                pre=curr->left;
                while(pre->right&&pre->right!=curr)
                    pre=pre->right;
                if(pre->right==NULL)
                {
                    pre->right=curr;
                    curr=curr->left;
                }
                else
                {
                    ret.push_back(curr->val);
                    pre->right=NULL;
                    curr=curr->right;
                }
            }
        }
        return ret;
    }
};