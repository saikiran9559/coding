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

class Solution {
public:
    
 /*   
    TreeNode *fun(TreeNode *node){
        if(node!=NULL){
            if(node->val==1){
                node->left =  fun(node->left);
                node->right = fun(node->right);
                return node;
             }else if((node->left!=NULL and node->left->val == 1) or node->right!=NULL and node->right->val==1){
                node->left = fun(node->left);
                node->right = fun(node->right);
                return node;
            }else{
                return NULL;
            }
        }
        return node;
    }
*/
    /*
    TreeNode *construct(Vector<int> &values){
        vector<TreeNode*>{
        }
        for(auto i:values){

        }
    }
    */
void printvector(vector<int> v){
    cout<<"{";
    for(auto i:v) cout<<i<<",";
    cout<<"}"<<endl;
}


    vector<int> levelorder(TreeNode *temp){
        vector<int> output;
        if(temp==NULL) return output;
        vector<TreeNode*> nodes{temp};
        int count=1;
        int i=0;
        while(i<count){
            if(nodes.at(i)==NULL){
                output.push_back(2);
                i++;
                continue;
            }
            if(nodes.at(i)->left==NULL and nodes.at(i)->right==NULL){
                output.push_back(nodes.at(i)->val);
                i++;
                continue;
            }
            nodes.push_back(nodes.at(i)->left);
            nodes.push_back(nodes.at(i)->right);
            output.push_back(nodes.at(i)->val);
            count+=2;
            i++;
        }
        return output;
        
    }

    TreeNode *fun(TreeNode *node){
        if(node==NULL) return NULL;
        if(node->left==NULL and node->right==NULL){
            if(node->val == 0) return NULL;
            return node;
        }
        node->left = fun(node->left);
        node->right = fun(node->right);
        if(node->left==NULL and node->right==NULL){
            if(node->val == 0) return NULL;
            return node;
        }
        return node;
    }

    TreeNode* pruneTree(TreeNode* root) {
        return fun(root);
    }
};

int main(){
    TreeNode *n1 = new TreeNode(1);
    TreeNode *n2 = new TreeNode(0);
    TreeNode *n3 = new TreeNode(0);
    TreeNode *n4 = new TreeNode(1);
    n1->right = n2;
    n2->left = n3;
    n2->right = n4;
    Solution s1;
    s1.printvector(s1.levelorder(n1));
    n1 = s1.pruneTree(n1);
    s1.printvector(s1.levelorder(n1));
    return 0;
}
