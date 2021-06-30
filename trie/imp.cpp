#include<bits/stdc++.h>
using namespace std;

class Node {
    public :
    vector<Node*>childs;
    bool isEnd;
    
    Node(){
        isEnd = false;
        childs.resize(26,NULL);
    }
};

class Trie {
public:
    /** Initialize your data structure here. */
    Node * root;
    Trie() {
        root= new Node();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Node * n = root;
        for(auto x : word) {
            if(n->childs[x-'a'] == NULL){
                n->childs[x-'a'] = new Node();
            }
            n=n->childs[x-'a'];
        }
        n->isEnd = true;
        
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Node* n = root;
        for(auto x: word) {
            if(n->childs[x-'a']!=NULL){
                n=n->childs[x-'a'];
            }
            else {
                return false;
            }
        }
        if(n->isEnd)
        return true;
        else return false;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
         Node* n = root;
        for(auto x: prefix) {
            if(n->childs[x-'a']!=NULL){
                n=n->childs[x-'a'];
            }
            else {
                return false;
            }
        }
        return true;
    }
};

int main()  {
    string a,b;
    vector<pair<string,string>>vec;
    Trie * root = new Trie();
    while(cin >> a >> b) {
        vec.push_back({a,b});
    }
    for(auto x : vec){
        if(x.first == "insert"){
            root->insert(x.second);
        }
        else if(x.first == "search"){
            if(root->search(x.second))
            cout << "true";
            else {
                cout << "false";
            }
            cout << endl;
        }
        else{
            if(root->startsWith(x.second)){
                cout << "true";
            }
            else{
                cout << "false";
            }
            cout << endl;
        }
    }
}



