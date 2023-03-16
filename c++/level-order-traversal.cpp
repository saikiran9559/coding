/* Level Order Binary Tree */

#include <bits/stdc++.h>
using namespace std;

// binary tree node
struct TreeNode
{
    int val;         // value of the node
    TreeNode *left;  // left pointer of the node
    TreeNode *right; // right pointer of the node

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class BinaryTree
{
public:
    TreeNode *root = nullptr; // Root node of the binary tree

    Solution(){};

    // insertNode() method inserts single value at a time to the binary tree
    void insertNode(int val)
    {
        if (!this->root)
        {
            this->root = new TreeNode(val);
            return;
        }

        vector<TreeNode *> node_list;
        node_list.push_back(this->root);

        int top = 0;

        while (top < node_list.size())
        {
            TreeNode *temp = node_list.at(top);

            if (!temp->left)
            {
                temp->left = new TreeNode(val);
                return;
            }

            else if (!temp->right)
            {
                temp->right = new TreeNode(val);
                return;
            }
            else
            {
                node_list.push_back(temp->left);
                node_list.push_back(temp->right);
                top++;
            }
        }
        return;
    }

    /*
    The insertListOfValues method is used to insert a list of values into the binary tree
    by calling insertNode for each value in the list.
    */
    void insertListOfValues(vector<int> &arr, int n)
    {
        for (auto val : arr)
        {
            this->insertNode(val);
        }
    }

    /*
    The levelOrderTraversal() method is responsible for printing the level order traversal of a binary tree.
    It first checks if the root node is nullptr and returns if it is.
    Then, it creates an empty vector node_list and adds the root node to it.
    It also initializes an integer variable top to 0, which points to the current node in node_list.

    The method then enters a loop that runs until top becomes equal to the size of the node_list.
    Within the loop, it takes the node at index top from node_list and prints its value.
    If the node has a left child, the method adds it to node_list.
    If the node has a right child, it adds it to node_list as well. It then increments top by 1.

    This process continues until all nodes in the tree have been visited and printed.
    */
    void levelOrderTraversal()
    {

        TreeNode *root = this->root;
        if (!root)
        {
            cout << "Empty\n"
                 << endl;
            return;
        }

        vector<TreeNode *> node_list;
        node_list.push_back(root);

        int top = 0;

        while (top < node_list.size())
        {
            TreeNode *temp = node_list.at(top);

            cout << temp->val << ", ";

            if (temp->left)
            {
                node_list.push_back(temp->left);
            }
            if (temp->right)
            {
                node_list.push_back(temp->right);
            }
            top++;
        }
        cout << endl
             << endl;
    }
};

int main()
{
    BinaryTree binary_tree;
    while (true)
    {
        cout << "1:Input list of values\n2:Input single value\n3:Print level order traversal\n0:Exit" << endl;
        cout << "Enter the option(0, 1, 2, 3): ";
        int option;
        cin >> option;
        cout << endl;
        if (option == 0)
        {
            break;
        }
        else if (option == 1)
        {

            int n;
            cout << "Enter length of list:";
            cin >> n;
            vector<int> arr(n);
            cout << endl;
            cout << "Enter list of values: ";
            for (int i = 0; i < n; i++)
            {
                cin >> arr.at(i);
            }
            cout << endl;
            binary_tree.insertListOfValues(arr, n);
        }
        else if (option == 2)
        {

            int val;
            cout << "Enter the val: ";
            cin >> val;
            binary_tree.insertNode(val);
            cout << endl;
        }
        else if (option == 3)
        {
            binary_tree.levelOrderTraversal();
        }
        else
        {
            cout << "Invalid Option\n"
                 << endl;
        }
    }
    return 0;
}