    class Solution {
public:
    bool isMatch(string s, string p) {
    int m=p.length();
    int n=s.length();
    int dp [n+1][m+1];
    dp[0][0]=1;
    for(int i=1; i<n+1; i++)
        dp[i][0]=0;

    
    for(int i=1; i<m+1; i++)
        if(p[i-1]=='*')
            dp[0][i]=dp[0][i-1] ;
        else
            dp[0][i]=0;

    for(int i=1; i<n+1; i++)
        for(int j=1; j<m+1; j++)
        {
            if(s[i-1]==p[j-1])
                dp[i][j]=dp[i-1][j-1];
            else
                dp[i][j]=0;

            if(p[j-1]=='?')
                dp[i][j]=dp[i-1][j-1];
            else if(p[j-1]=='*')
                dp[i][j]=dp[i][j-1]||dp[i-1][j];
        }
    return dp[n][m];

}

  };