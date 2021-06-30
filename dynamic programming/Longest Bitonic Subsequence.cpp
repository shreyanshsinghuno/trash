#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
 
    int ar[n];
    int dp[n];
    int dp2[n];
    
    for(int i=0;i<n;i++){
        cin >> ar[i];
        dp[i]=0;
        dp2[i]=0;
    }
       if(n==1){
        cout << 0;
        return 0;
    }
    dp[0]=1;
    int ans =0;
    for(int i=1;i<n;i++){
        int mx = 0;
        for(int j=0;j<i;j++){
            if(ar[i] > ar[j]) { 
                mx = max(mx,dp[j]);
            }
        }
        dp[i] = mx+1;
    
    }
    reverse(ar,ar+n);
    dp2[0]=1;
    for(int i=1;i<n;i++){
        int mx = 0;
        for(int j=0;j<i;j++){
            if(ar[i] > ar[j]) { 
                mx = max(mx,dp2[j]);
            }
        }
        dp2[i] = mx+1;
    
    }
    
    reverse(dp2,dp2+n);
    for(int i=0;i<n;i++){
        ans = max(ans , dp[i]+dp2[i]-1);
    }
    cout <<   ans;
}