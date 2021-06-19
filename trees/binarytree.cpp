#include<bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    int data = 0;
    TreeNode *left = nullptr;
    TreeNode *right = nullptr;

    TreeNode(int data)
    {
        this->data = data;
    }
};
// input_Section_====================================================================
TreeNode *createTree(vector<int> &arr, vector<int> &IDX)
{
    if (IDX[0] > arr.size() || arr[IDX[0]] == -1)
    {
        IDX[0]++;
        return nullptr;
    }

    TreeNode *node = new TreeNode(arr[IDX[0]++]);
    node->left = createTree(arr, IDX);
    node->right = createTree(arr, IDX);

    return node;
}

void display(TreeNode *node)
{
    if (node == nullptr)
        return;

    string str = "";
    str += ((node->left != nullptr ? to_string(node->left->data) : "."));
    str += (" <- " + to_string(node->data) + " -> ");
    str += ((node->right != nullptr ? to_string(node->right->data) : "."));

    cout << str << endl;

    display(node->left);
    display(node->right);
}

void traversal(TreeNode * root ){
  if(root==NULL)
  return;

  cout << "In Preorder : " << root->data<< endl;
  traversal(root->left);
   cout << "In Inorder : " << root->data<< endl;
  traversal(root->right);
  cout << "In Postorder : " << root->data<< endl;

}

int size(TreeNode *root)
{
    if(root == NULL){
        return 0;
    }
    int a=0,b=0;
        a=size(root->left);
        b=size(root->right);

    return a+b+1;
}

int sum(TreeNode *root)
{
    if(root == NULL){
        return 0;
    }
    int a=0,b=0;
        a=sum(root->left);
        b=sum(root->right);

    return a+b+root->data;
}

int max(TreeNode *root)
{
    if(root == NULL){
        return 0;
    }
    int a=0,b=0;
        a=max(root->left);
        b=max(root->right);
        a = max(a,b);
    return max(a,root->data);
}

int height(TreeNode *root)
{
    if(root == NULL){
        return -1;
    }
    int a=0,b=0;
        a=height(root->left);
        b=height(root->right);
    return max(a,b)+1;
}

void levelOrderTraversal(TreeNode * root){
  queue<TreeNode* >q;
  q.push(root);

  while(!q.empty()){
    int sz = q.size();
    for(int i=0;i<sz;i++){
      TreeNode*temp = q.front();
      q.pop();
      cout << temp->data << " ";
      if(temp->left)
      q.push(temp->left);
      if(temp->right)
      q.push(temp->right); 
    }
    cout << endl;
    }
}

void itertiveTraversals(TreeNode* root){
  if(root==NULL)
  return ;

  // string pre ="";
  // string in = "";
  // string post="";

  // stack<pair<TreeNode*,int > >st;
  // st.push({root,1});
  // while(!st.empty()){
  //   cout  << st.size()<< endl;
  //   pair<TreeNode*,int>temp = st.top();
  //   cout << temp.first->data << " " << temp.second << endl;
  //   if(temp.second == 1){
  //   pre+=to_string(temp.first->data);
  //   temp.second  = temp.second+1;
  //   if(temp.first->left!=NULL){
  //   st.push({temp.first->left,1});
  //   }
  //   }

  //   else if(temp.second == 2 )
  //   {
  //   in+=to_string(temp.first->data);
  //   temp.second  = temp.second+1;
  //   if(temp.first->right!=NULL){
  //   st.push({temp.first->right,1});
  //   }
  //   }
  //   else  {
  //     post+=to_string(temp.first->data);
  //     st.pop();
  //   }
  // }
  // cout << pre << endl;
  // cout << in << endl;
  // cout << post << endl;

   stack<pair<TreeNode* , int >> st ;
   pair<TreeNode* , int > rtp = {root,1};
    st.push(rtp);
    string pre = "";
    string post = "";
    string in = "";
    while (st.size() > 0) {
      cout << "ans"<< endl;
      pair<TreeNode*,int >top = st.top();
      cout << top.first->data << endl;
      if (top.second == 1) {
        pre += to_string(top.first->data) + " ";
        top.second++;
        if (top.first->left != NULL) {
          pair<TreeNode*,int>lp = {top.first->left, 1};
          st.push(lp);
        }
      } 
      else if (top.second== 2) {
        in += to_string(top.first->data) + " ";
        top.second++;
        if (top.first->right != NULL) {
          pair<TreeNode*,int > rp = {top.first->right, 1};
          st.push(rp);
        }
      } 
      else {
        post += to_string(top.first->data) + " ";
        top.second++;
        st.pop();
        break;
      }
    }
    cout << "ans"<< endl;
    cout << pre << endl;
    cout << in << endl;
    cout << post << endl;
}

vector<TreeNode*>ans;
bool nodeToRootPath(TreeNode * root, int target){
  if(root==NULL){
    return 0;
  }
  if(root->data  == target){
      ans.push_back(root);
    return true;
  
  }

  bool lc = nodeToRootPath(root->left,target);
  if(lc){
    ans.push_back(root);
  return lc;
  }
  bool rc = nodeToRootPath(root->right,target);
  if(rc){
      ans.push_back(root);
  return rc;
  }
  return false;
}

void printKthLevel(TreeNode *root,int k){
  queue<TreeNode* >q;
  q.push(root);
  int level = 0;
  while(!q.empty()){
    int sz = q.size();
    for(int i=0;i<sz;i++){
      TreeNode*temp = q.front();
      q.pop();
      if(level == k)
      cout << temp->data << endl;
      if(temp->left)
      q.push(temp->left);
      if(temp->right)
      q.push(temp->right); 
      
    }
    level++;
    }
}

void printkrec(TreeNode*root, int k){
  if(k<0 || root == NULL){
    return;
  }
  if(k==0)
  cout<< root->data << " " ;
  printkrec(root->left,k-1);
  printkrec(root->right,k-1);

}

void printkrecmodified(TreeNode*root, int k,TreeNode * blocker){
  if(k<0 || root == NULL || root == blocker){
    return;
  }
  if(k==0)
   cout<< root->data << endl ;
  printkrecmodified(root->left,k-1,blocker);
  printkrecmodified(root->right,k-1,blocker);
}

void printKfaraway(TreeNode * root , int k, int key,vector<TreeNode *> ans ) {
  // use node to root path and printKleveldown function ez;
  for(int i=0;i<ans.size(); i++){
    // printkleveldown karo magar block kr do if it goes in the path where our key is present 
    printkrecmodified(ans[i] , k - i , i==0 ? NULL : ans[i-1]);
  }

}

void printleaftorootinrange(TreeNode * root , vector<int> psf ,int sum , int lo ,int hi) {
  if(root == NULL) 
  return ;
  if(root->left ==NULL  && root->right == NULL ){
    sum+=root->data;
    if(sum >= lo  && sum <= hi)
    {
      psf.push_back(root->data);
    for(auto x : psf){
      cout << x << " " ;
    }
    cout <<  endl;
    }
    return; 
  }
  vector<int> temp  = psf;
  temp.push_back(root->data);
  printleaftorootinrange(root->left  , temp , sum + root->data , lo , hi) ;
  printleaftorootinrange(root->right , temp , sum + root->data , lo , hi) ;

}

TreeNode * clone(TreeNode * root){
  if(root == NULL)
  return NULL;

  TreeNode * lc = clone(root->left);
  TreeNode * rc = clone(root->right);

  TreeNode * nn = new TreeNode(root->data);
  root->left = nn;
  nn->left = lc;

  return root;
}

TreeNode * anticlone(TreeNode * root ){
  if(root == NULL)
  return NULL;

  root->left = root->left->left;
  anticlone(root->left);
  anticlone(root->right);

  return  root;
}


void printSingleChildNode(TreeNode * root ,TreeNode*parent ) {
  if(root == NULL)
  return;
  if(parent!=NULL && parent->left == root && parent->right==NULL){
    cout << root->data << endl;

  }
  else if (parent!=NULL && parent->right == root && parent->left==NULL){
    cout << root->data << endl;
  }

  printSingleChildNode(root->left ,root);
  printSingleChildNode(root->right,root);
}

TreeNode * removeLeaves(TreeNode * root) {
  if(root == NULL){
    return NULL;
  }
  if(root->left  == NULL && root->right == NULL){
        return NULL;
  }
  root->left = removeLeaves(root->left);
  root->right = removeLeaves(root->right);
  return root;

}

void solve()
{
    int n;
    cin >> n;
    vector<int> arr(n, 0);
    string ar[n];
    for(int i=0;i<n;i++){
      cin >> ar[i];
    }
    for (int i = 0; i < n; i++)
    {
      if(ar[i]=="n")
        arr[i]=-1;
      else {
        arr[i]=stoi(ar[i]);
      }
    }
    vector<int> IDX(1, 0);
    TreeNode *root = createTree(arr, IDX);
   // display(root); 
  // cout << size(root)<<endl;
  // cout << sum(root)<<endl;
  // cout << max(root)<<endl;
  // cout << height(root)<<endl;
   // traversal(root);
   //levelOrderTraversal(root);
  //  itertiveTraversals(root);
//   int target;
//   cin >> target;
//  if(nodeToRootPath(root,target))
//  cout << "true"<< endl;
//  else cout << "false" << endl;

// if(ans.size() > 0) {
// cout << "[";
//  for(int i=0;i<ans.size();i++) {
//    if(i==ans.size()-1)
//    cout << ans[i];
//    else
//    cout << ans[i] << ", ";
//  }
//  cout << "]";
// }
// else cout << "[]";
// int key ;
// cin >> key;
//  int k;
//  cin >> k;
// nodeToRootPath(root,key);
// // for(auto x : ans ){
// //   cout << x->data << endl;
// // }
// printKfaraway(root,k,key,ans);


// int lo;
// int hi;
// cin >> lo;
// cin >> hi;
// vector<int>s;
// printleaftorootinrange(root,s,0,lo,hi);

  root = removeLeaves(root);
  display(root);
}

int main()
{
    solve();
    return 0;
}


/*
19
50 25 12 -1 -1 37 30 -1 -1 -1 75 62 -1 70 -1 -1 87 -1 -1
*/