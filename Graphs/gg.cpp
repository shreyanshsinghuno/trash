#include<bits/stdc++.h>
using namespace std;

vector<pair<int,int>>adj(100000);

bool hasPath(int src , int dest , vector<int>vis , vector<pair<int,int>>adj[] ) {
    if(src == dest ){
        return true;
    }

    vis[src] = 1;
    for(auto x : adj[src] ) {
        if(vis[x.first] ==0 ){
            if(hasPath(x.first,dest,vis,adj)){
                return true;
            }
        }
    }
    return false;
}

vector<string>ans;
void allPaths(int src , int dest , vector<int>vis , vector<pair<int,int>>adj[] , string psf){
    if(src == dest){
        ans.push_back(psf);
    }
    vis[src] = 1;
    for(auto x : adj[src]) {
        if(vis[x.first] == 0) {
            allPaths(x.first,dest,vis,adj,psf+to_string(x.first));
        }
    }
}

void dfsConnectedComponents(int node ,vector<int>&vis ,vector<pair<int,int>>adj[] , vector<int>&comp) {

    vis[node]=1;
    comp.push_back(node);

    for(auto x : adj[node]) {
        if(vis[x.first] == 0){
            dfsConnectedComponents(x.first,vis,adj,comp);
        }
    }

    return;
}


int main()  {

    int n,m;
    cin >> n >> m;
    vector<pair<int,int>>adj[n+5];
    for(int i=0;i<m;i++){
        int src,nbr,wt;
        cin >> src >> nbr >> wt ;
        adj[src].push_back({nbr,wt});
        adj[nbr].push_back({src,wt});
    }
    // int src,dest;
    // cin >> src >>dest ;
    vector<int>vis(n+1,0);
    // allPaths(src,dest,vis,adj,to_string(src));
    // for(auto x : ans ) {
    //     cout << x<< endl;
    // }
    vector<vector<int>>ass;
    
    int ans=0;
    for(int i=0;i<n;i++){
        if(vis[i] == 0 ){
            vector<int>comp;
            ans++;
            dfsConnectedComponents(i,vis,adj,comp);
            ass.push_back(comp);
        }
    }
    cout << '[';
    for(int k=0;k<ass.size()-1;k++) {
        cout << "[";
        for(int i=0;i<ass[k].size()-1;i++) {
            cout << ass[k][i] << ", ";
        }
        cout << ass[k][ass[k].size()-1]<<"], ";
    }
    cout << "[";
    int k = ass.size()-1;
    for(int i=0;i<ass[k].size()-1;i++) {
            cout << ass[k][i] << " ,";
        }

    cout << ass[k][ass[k].size()-1]<<']';
    cout << ']';
}



