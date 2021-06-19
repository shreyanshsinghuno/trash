#include<bits/stdc++.h>
#include"generictreenode.h"
using namespace std;

TreeNode<int> * takeInput(){
    int n;
    cout << "Give root data " << endl;
    cin >> n;
    TreeNode<int>* root = new TreeNode<int>(n);
    cout << "number of childrens of " << n << endl;
    int ch;
    cin >> ch;
    while(ch--){
        TreeNode<int>*child = takeInput();
        root->childrens.push_back(child);
    }
    return root;
}

void printTree(TreeNode<int> *root){
    // idhar int dena padega coz template hai abhi node 
    // not already int node
    if(root == NULL){
        return;
    }
    cout << root->data << " : ";
    for(int i=0;i<root->childrens.size();i++){
        cout <<root->childrens[i]->data << ',';
    }
    cout << endl;
    for(int i=0;i<root->childrens.size();i++){
        printTree(root->childrens[i]);
    }
    

}
int main(){
    //TreeNode<int>* root = new TreeNode<int>(10);
    // TreeNode<int>* root = new TreeNode<int>();
    // root->data = 10;
    // ye kaafi chutiyap hai ki data alag se aese set karo 
    // to ek naya constructor bana lo jyada sahi hai
    // TreeNode<int>* nodea = new TreeNode<int>(20);
    // TreeNode<int>* nodeb = new TreeNode<int>(30);
    // // 3 nodes bn gaye but they arent connected yet
    // root->childrens.push_back(nodea);
    // root->childrens.push_back(nodeb);

    TreeNode<int>* root = takeInput();
    cout << endl;
    printTree(root);
    // todo : delete the tree

    return 0;
}