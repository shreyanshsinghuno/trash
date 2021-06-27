#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int ar[n];
    int dp[n];
    for(int i=0;i<n;i++){
        cin >> ar[i];
        dp[i]=0;
    }
    dp[0]=1;
    int ans =1;
    for(int i=1;i<n;i++){
        int mx = 0;
        for(int j=0;j<i;j++){
            if(ar[i] > ar[j]) {
                mx = max(mx,dp[j]);
            }
        }
        dp[i] = mx+1;
        ans = max(ans,dp[i]);
    }
    cout << ans << endl;
    
}