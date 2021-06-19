    #include<bits/stdc++.h>
    using namespace std;

    class TreeNode {
        public : 
        // so that we dont need getters and setters
        int data;
        vector<TreeNode *> childrens;
        // vector <TreeNode * > childrens;
        // ye bhi chalega but   
        // we dont neccesarily need to tell the type of treenode pointer as it assumes already the typename T
        TreeNode (int data){
            this->data = data;
        }
    };
    int sizeoftree(TreeNode * root){
        int sz  = 1;
        for(auto x : root->childrens)
        sz+=sizeoftree(x);

        return sz;
    }
    int findMax(TreeNode *root){
        int ans = root->data;

        for(auto x : root->childrens ){
            ans = max(ans,findMax(x));
        }
        return ans;
    }

    int height(TreeNode * root){
        int hm=-1;
        for(auto x : root->childrens){
            hm = max(hm,height(x));
        }
        return hm+1;
    }
    void printTree(TreeNode *root){
        // idhar int dena padega coz template hai abhi node 
        // not already int node
        if(root == NULL){
            return;
        }
        cout << root->data << " -> ";
        for(int i=0;i<root->childrens.size();i++){
            cout <<root->childrens[i]->data << ", ";
        }
        cout << "." << endl;
        for(int i=0;i<root->childrens.size();i++){
            printTree(root->childrens[i]);
        }
        

    }
    void traverse(TreeNode * root){
        cout << "Node Pre " << root->data << endl;
        for(auto x : root -> childrens){
            cout << "Edge Pre " << root->data << "--" << x->data << endl;
            traverse(x);
            cout << "Edge Post " << root->data << "--" << x->data << endl;
        }
        cout << "Node Post " << root->data<< endl;
    }

    void levelorder(TreeNode * root){
        queue<TreeNode *>q;
        q.push(root);
        while(!q.empty()){
            TreeNode * temp = q.front();
            q.pop();
            cout << temp->data << " ";
            for(auto x : temp->childrens){
                q.push(x);
            }
        }
        cout << " .";
    }
    void levelorderlinewise(TreeNode * root){
        queue<TreeNode *>q;
        q.push(root);
        while(!q.empty()){

            int sz = q.size();
            queue<TreeNode *>cq;
            while (sz--)
            {
            TreeNode * temp = q.front();
            q.pop();
            cout << temp->data << " ";
            cq.push(temp);
            }
            cout << endl;
            while(!cq.empty()){
                TreeNode * tt = cq.front();
                for(auto  x : tt->childrens)
                q.push(x);
                cq.pop();
            }
        }
        
    }
    void levelorderzigzag(TreeNode * root){
        stack<TreeNode *>ms;
        ms.push(root);
        int level = 1;
        stack<TreeNode *>cs;
        while(!ms.empty()){
            TreeNode * temp  = ms.top();
            cout << ms.top()->data << " ";
    ms.pop();
            if(level % 2 == 1){
                for(int i=0;i<temp->childrens.size();i++){
                cs.push(temp->childrens[i]);
                }  
            }
            if(level % 2 == 0){
                for(int i=temp->childrens.size()-1;i>=0;i--){
                cs.push(temp->childrens[i]);
                }  
            }
            
            if(ms.empty()){
        ms = cs;
        level++;
        stack<TreeNode*>ttl;
        cs = ttl;
        cout << endl;
            }
        }
    }
    void mirror(TreeNode * root){
        for(auto x : root->childrens){
            mirror(x);
        }
    reverse(root->childrens.begin(),root->childrens.end());
        
    }

TreeNode * removeleaves(TreeNode * root){
    for(int i=root->childrens.size()-1;i>=0;i--){
            TreeNode * x = root->childrens[i];
            if(x->childrens.size()==0)
            root->childrens.erase(root->childrens.begin()+i);
    }
    for(auto x : root->childrens){
        removeleaves(x);
    }
    return root;
}
vector<TreeNode* >ans;
void linearizehelper(TreeNode * root ){
    ans.push_back(root);
    for(auto x : root->childrens)
    linearizehelper(x);
}
void linearizedumb(TreeNode * root){
    linearizehelper(root);
    TreeNode * newroot = ans[0];
    for(int i=1;i<ans.size();i++){
        cout << ans[i-1]->data << " -> "<<ans[i]->data<<", .";
        cout << endl;
    }
    cout << ans[ans.size()-1]->data << " -> ."<< endl;
    // for(auto x : ans){
    //     cout << x->data << " ";
    // }
}

// LINEARIZE KARNA ABHI TK NAHI AATA HAI BC
// CHUTIYA


// TreeNode * getTail(TreeNode* root){
//     while(root->childrens.size() == 1){
//         root=root->childrens[0];
//     }
//     return root;
// }
// TreeNode * LineraizeRec(TreeNode * root ){
//     for(auto  x : root->childrens){
//         LineraizeRec(x);
//     }
//     while(root->childrens.size()>1){
//         TreeNode * lastChild = root->childrens[root->childrens.size()-1];
//         root->childrens.erase(root->childrens.end()-1);
//         TreeNode * secondLastChild = root->childrens[root->childrens.size()-1];
//         TreeNode * secondLastTail = getTail(secondLastChild);
//         secondLastTail.push_back(lastChild);
//     }
// }

int maxSubtreeSum = INT_MIN;
TreeNode * maxSubtreesumnode;
int maxSumSubtree(TreeNode * root){
    int sum = 0;
    for(auto x : root->childrens){
        sum+=maxSumSubtree(x);
    }
    sum += root->data;
    if(sum > maxSubtreeSum){
        maxSubtreeSum = sum;
        maxSubtreesumnode = root;
    }
    return sum;
}

//  IMPORTANT CHEEJJJ

void Iterative(TreeNode* node){
    stack<pair<TreeNode*,int>>st;
    pair<TreeNode*,int>p={node,-1};
    st.push(p);
    string pre="";
    string post="";
    while(st.size()>0){
        pair<TreeNode*,int>t=make_pair(st.top().first,st.top().second);
        if(st.top().second==-1){
            pre+=to_string(t.first->data);
            pre+=" ";
            st.top().second++;
        }
        else if(st.top().second==st.top().first->childrens.size()){
            post+=to_string(st.top().first->data);
            post+=" ";
            st.pop();
        }
        else{
            pair<TreeNode*,int>pr;
            st.top().second++;
            pr=make_pair(st.top().first->childrens[st.top().second-1],-1);
            st.push(pr);
        }
        
    }
    cout<<pre<<"\n";
    cout<<post<<"\n";
    
}

bool findanelement(TreeNode * root , int target){
    if(root->data == target){
        return true;
    }
    for(auto x : root->childrens){
        if(findanelement(x,target))
        return true;
    }
    return false;
}

vector <int> nodeToRootPath(TreeNode *root ,int target){
    if(root->data == target){
        vector<int>ans;
        ans.push_back(root->data);
        return ans;
    }
    for(auto x : root->childrens){
        vector<int> vec  = nodeToRootPath(x,target);
        if(vec.size()!=0){
            vec.push_back(root->data);
            return vec;
        }
    }
    vector<int> vec;
    return vec;
 }

int lowestCommonAncestor(TreeNode * root , int a ,int b){
    vector<int>v1 = nodeToRootPath(root,a);
    vector<int>v2 = nodeToRootPath(root,b);
    reverse(v1.begin(),v1.end());
    reverse(v2.begin(),v2.end());
    int ans = -1;
    for(int i=0;i<min(v1.size(),v2.size());i++){
        if(v1[i]==v2[i]){
            ans = v1[i];
        }
        else
        break;
    } 
    return ans;
 }
 int distanceBetweenNodes(TreeNode * root , int a ,int b ){
     vector<int>v1 = nodeToRootPath(root,a);
    vector<int>v2 = nodeToRootPath(root,b);
    int ans = 0;
    int i = v1.size();
    int j = v2.size();
    while(i-- >=0 && j-- >=0){
        if(v1[i] == v2[j]){
            continue;
        }

        i++;
        j++;
        break;
    }
    return i+j; 
 }
bool areSimilar(TreeNode * root1 , TreeNode * root2){
    if(root1->childrens.size() != root2->childrens.size()){
        return false;
    }
    for(int i=0;i<root1->childrens.size();i++){
        if(!areSimilar(root1->childrens[i],root2->childrens[i])){
            return false;
        }
    }
    return true;
}
bool areMirror(TreeNode * root1 , TreeNode * root2){
      if(root1->childrens.size() != root2->childrens.size()){
        return false;
    }
    for(int i=0;i<root1->childrens.size();i++){
        if(!areMirror(root1->childrens[i],root2->childrens[root2->childrens.size()-1-i])){
            return false;
        }
    }
    return true;
}

bool isSymmetric(TreeNode * root){
    int n = root->childrens.size();
    for(int i=0;i<n/2;i++){
        if(root->childrens[i]->childrens.size()!=root->childrens[n-1-i]->childrens.size())
        return false;
    }
    for(int i=0;i<n;i++){
        if(!isSymmetric(root->childrens[i]))
        return false;
    }
    return true;
}
    int main(){
        int n;
        cin >> n;
        int ar[n];
        for(int i=0;i<n;i++){
            cin >> ar[i];
        }
        TreeNode* root;
        stack<TreeNode *>st;
        for(int i=0;i<n;i++){
            if(ar[i] == -1)
            {
                st.pop();
            }
            else{
                TreeNode* temp = new TreeNode(ar[i]);
                if(st.empty()){
                root = temp;
                }
                else{
                    st.top()->childrens.push_back(temp);
                }
                st.push(temp);
            }
            
        }
        //printTree(root);
       // cout <<  endl;
        //linearizedumb(root);
        //printTree(root);
       // maxSumSubtree(root);
      //  cout << maxSubtreesumnode->data <<'@'<<maxSubtreeSum;
    //   int target;
    //   cin >> target;
    //   vector<int>anss = nodeToRootPath(root,target);
    //   for(int i=0;i<anss.size();i++){
    //       if(i==0){
    //           cout << '[' << anss[i];
    //       }
    //       else if(i==anss.size()-1){
    //           cout << ',' << anss[i] <<']';
    //       }
    //       else {
    //           cout << ","<<anss[i];
    //       }
    //   }

    //SECOND TREE

    // int m;
    // cin >> m;
    // int ar1[m];
    //     for(int i=0;i<m;i++){
    //         cin >> ar1[i];
    //     }
    //     TreeNode* root1;
    //     stack<TreeNode *>st1;
    //     for(int i=0;i<m;i++){
    //         if(ar1[i] == -1)
    //         {
    //             st1.pop();
    //         }
    //         else{
    //             TreeNode* temp = new TreeNode(ar1[i]);
    //             if(st1.empty()){
    //             root1 = temp;
    //             }
    //             else{
    //                 st1.top()->childrens.push_back(temp);
    //             }
    //             st1.push(temp);
    //         }
            
    //     }
    // if(areSimilar(root,root1))
    // cout << "true";
    // else cout << "false";

    if(isSymmetric(root))
    cout << "true";
    else cout << "false";


    return 0;
    }