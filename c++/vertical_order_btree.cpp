#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


void printvector(vector<int> &v){
    cout<<"\t{";
    for(auto i:v)cout<<i<<",";
    cout<<"},"<<endl;
}
void print2D(vector<vector<int>> &v){
    
    cout<<"{";
    for(auto i:v) printvector(i);
    cout<<"}"<<endl;

}

class Solution {
public:
    void fun(TreeNode *node, int r, int c, int &minicol, int &maxicol, unordered_map<int, vector<int>> &map){
        if(node!=NULL){
            minicol = min( minicol, c);
            maxicol = max( maxicol, c);
            map[c].push_back(node->val);
            fun(node->left, r+1, c-1,minicol, maxicol, map );
            fun(node->right, r+1, c+1,minicol, maxicol, map );
        }
        /*
        if(node->left != NULL){
            map[c-1].push_back(node->left->val);
            minicol = min( minicol, c-1);
            fun(node->left, r+1, c-1,minicol, maxicol, map );
        }
        if(node->right != NULL){
            map[c+1].push_back(node->right->val);
            maxicol = max( maxicol, c+1);
        }
        */
        
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        unordered_map<int, vector<int>> map;
        int minicol=0;
        int maxicol=0;
        fun(root, 0, 0, minicol,maxicol, map);
        vector<vector<int>> output;
        for(int i=minicol; i<= maxicol; i++){
            vector<int> arr;
            for(auto j:map.at(i)) arr.push_back(j); 
            output.push_back(arr);
        }
        return output;
        
    }
};

int main(){
    Solution s1;
    struct TreeNode *root = new TreeNode(1);
    struct TreeNode *n1 = new TreeNode(2);
    struct TreeNode *n2 = new TreeNode(3);
    struct TreeNode *n3 = new TreeNode(4);
    struct TreeNode *n4 = new TreeNode(5);
    struct TreeNode *n5 = new TreeNode(6);
    struct TreeNode *n6 = new TreeNode(7);
    root->left = n1;
    root->right = n2;
    n1->left = n3;
    n1->right = n4;
    n2->left = n5;
    n2->right = n6;
    vector<vector<int>> arr = s1.verticalTraversal(root);
    print2D(arr);
    return 0;
}
