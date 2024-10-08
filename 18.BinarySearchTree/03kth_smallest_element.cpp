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


int solve(BinaryTreeNode<int> *root , int &i , int k){

    //base case
    if(root == NULL){
        return -1;
    }

    int left = solve(root->left, i, k) ;

    if(left != -1){
        return left;
    }

    i++;
    if(i == k ){
        return root->data;
    }

    return solve(root->right, i, k);



}

int kthSmallest(BinaryTreeNode<int> *root, int k) {
    int i = 0;
    int ans = solve(root ,i , k );
    return ans;

  
}