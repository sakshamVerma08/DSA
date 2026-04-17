#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
        int val;
        Node* left;
        Node* right;

        Node(){
            left=nullptr;
            right=nullptr;
        }
        Node(int val){
            this->val=val;
            left=nullptr;
            right=nullptr;
        }
};

class Solution{
    private:
        Node *root;
    public:
        Solution(int val){
            this->root = new Node(val);
        }
        Solution(int val, Node*l, Node* r){
            this->root = new Node(val);
            root->left=l;
            root->right=r;
        }
        Solution(Node* root, Node* l, Node* r){
            this->root = root;
            this->root->left = l;
            this->root->right = r;
        }

        bool checkSum(Node* root){
            if(!root)return true;

            if(root->left==nullptr)return true;

            bool left = checkSum(root->left);
            if(!left)return false;
            bool right = checkSum(root->right);
            if(!right)return false;

            if(root->val == root->left->val + root->right->val)return true;
            else return false;
        }
};


int main(){

    // Let's consider true for a Leaf Node.

    auto root = new Node(1);
    auto left = new Node(0);
    auto right = new Node(1);
    root->left=left;
    root->right = right;
    right->left= new Node(0);
    right->right = new Node(0);

    left->left = new Node(1);
    left->right = new Node(0);

    Solution* s = new Solution(root,left,right);
    bool flag = s->checkSum(root);

    /*

        1
        /\
        0 1
        /\/\
        0010
    */

    if(flag)cout<<"TRUE"<<endl;
    else cout<<"FALSE"<<endl;
}

