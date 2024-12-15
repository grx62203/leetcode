//显式递归
void preOrder(TreeNode *root)
{
    if(root == NULL)
        return;
    visit(root);
    preOrder(root->left);
    preOrder(root->right);
}

//栈
vector<int> preOrder(TreeNode *root)
{
    vector<int> result;
    stack<TreeNode*> helper;
    if(root == NULL)    return result;
 
    while(root || !helper.empty())
    {
        if(root)
        {
            result.push(root->val);
            helper.push(root);
            root = root->left;
        }else{
            root = helper.top();
            helper.pop();
            root = root->right;
        }
    }
 
    return result;
}