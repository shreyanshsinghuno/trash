#include<vector>
using namespace std;

template<typename T>
class TreeNode {
    public : 
    // so that we dont need getters and setters
    T data;
    vector<TreeNode<T>*> childrens;
    // vector <TreeNode * > childrens;
    // ye bhi chalega but   
    // we dont neccesarily need to tell the type of treenode pointer as it assumes already the typename T
    TreeNode <T> (int data){
        this->data = data;
    }


};
