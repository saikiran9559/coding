
    TreeNode *insert_values_at_begin(vector<int> &arr, int i, int n)
    {
        TreeNode *temp = nullptr;
        if (i < n)
        {
            temp = new TreeNode(arr.at(i));
            temp->left = insert_arr_values(arr, 2 * i + 1, n);
            temp->right = insert_arr_values(arr, 2 * i + 2, n);
        }
        return this->root = temp;
    }