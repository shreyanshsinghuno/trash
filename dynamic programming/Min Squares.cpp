#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int dp[n+1]={0};
    dp[0] =0;
    dp[1] =1;
    int ans =0;
    for(int i=2;i<=n;i++){
        int k=1;
        int mn = 1e9;
        while( i - k*k >=0)  {
            mn = min(mn,dp[i-(k*k)]);
            k++;
        }
        dp[i]=mn+1;
    }
    cout <<dp[n];
}
