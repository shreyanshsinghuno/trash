#include<bits/stdc++.h>
using namespace std;

bool comp(pair<int,int>a,pair<int,int>b) {
    if(a.first == b.first) {
        return a.second < b.second;
    }
    return a.first < b.first;
}
int main() {
    int n;
    cin >> n;
    pair<int,int > ar[n];
    int dp[n];
    
    for(int i=0;i<n;i++){
        int a,b;
        cin >> a >> b;
        ar[i] = {a,b};
        dp[i]=0;
    }
    if(n==1) {
        cout << 1 ;
        return 1;
    }
    sort(ar,ar+n,comp);
    dp[0]=1;
    int ans =0;
    for(int i=0;i<n;i++){
       // cout<< ar[i].first << " " << ar[i].second << endl;
        int mx = 0;
        for(int j=0;j<i;j++){
            if(ar[i].second > ar[j].second && ar[i].first > ar[j].first ) { 
                mx = max(mx,dp[j]);
            }
        }
        dp[i] = mx+1;
        ans = max(ans,dp[i]);
    }
    cout <<   ans;
}
