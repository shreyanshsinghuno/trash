#include<bits/stdc++.h>
using namespace std;

int main() {
    string s1,s2;
    cin >> s1 >> s2;
    int n=s1.length()+1;
    int m=s2.length()+1;
    int dp[n+2][m+2];
    memset(dp, 0, sizeof(dp));
    for(int i=n-2;i>=0;i--){
        for(int j=m-2;j>=0;j--){
            char c1 = s1[i];
            char c2 = s2[j];
            
            if(c1 == c2 ){
                dp[i][j] = dp[i+1][j+1]+1;
            }
            else {
                dp[i][j] = max(dp[i+1][j] , dp[i][j+1]);
            }
        }
    }
    cout << dp[0][0];
}