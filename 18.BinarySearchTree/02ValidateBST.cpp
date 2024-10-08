#include <bits/stdc++.h> 
/*************************************************************
 
    Following is the Binary Tree node structure

    class BinaryTreeNode 
    {
    public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/

// void inOrderTraversal(BinaryTreeNode<int> *root , vector<int> &arr) {

//     //base case
//     if (root == NULL) {
//         return ;
//     }

//     //recursive call
//     inOrderTraversal(root->left , arr);

//     arr.push_back(root->data);

//     inOrderTraversal(root->right, arr);


// }

// bool validateBST(BinaryTreeNode<int> *root) {
//     // Write your code here
//     vector<int> arr;
//     inOrderTraversal(root , arr);

//     return is_sorted(arr.begin(), arr.end());
// }



//another approach

bool isBST(BinaryTreeNode<int> *root, int min, int max) {

    //base case
    if (root == NULL) {
       return  true;
    }

    //recursive call

    if (root->data >= min && root->data <= max) {
        bool left = isBST(root->left, min, root->data);
        bool right = isBST(root->right, root->data, max);
        return left && right;
    } else {
    
    return false;}
}


bool validateBST(BinaryTreeNode<int> *root) {
    // Write your code here
  return isBST(root, INT_MIN, INT_MAX);
}