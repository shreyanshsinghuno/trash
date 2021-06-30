#include<bits/stdc++.h>
using namespace std;


class e {
    public :
    int x;
    int y;
    string psf;
    // e(int x,int y,string psf){
    //     x=x ;
    //     y=y;
    //     psf=psf;
    // }
};
int main(){
    int n,m;
    cin >> n >> m;
    int ar[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> ar[i][j];
        }
    }
    
    int dp[n][m];
    memset(dp,0,sizeof(dp));
    
    for(int i=n-1;i>=0;i--){
        for(int j=m-1;j>=0;j--){
            if(i == n-1 && j == m-1){
                dp[i][j] = ar[i][j]; 
            }
            else if(i==n-1){
                dp[i][j] = dp[i][j+1]+ar[i][j];
            }
            else if(j==m-1){
                dp[i][j] = ar[i][j]+dp[i+1][j];
            }
            else{
                dp[i][j] = min(dp[i+1][j],dp[i][j+1])+ar[i][j];
            }
        }
    }
    cout << dp[0][0] << endl;
    queue<e>q;
    e first;
    first.x = 0;
    first.y=0;
    first.psf="H";
   // cout << first.psf;
    q.push(first);
    while(!q.empty()){
            //cout << q.size();
            e tmp = q.front();
            q.pop();

            string psff = tmp.psf;
            if(tmp.x == n-1 && tmp.y == m-1){
                cout << tmp.psf << endl;
            }
            else if(tmp.x==n-1){
                e ff;
                ff.x = tmp.x+1;
                ff.y = tmp.y;
                ff.psf = psff+'H';
                q.push(ff);
            }
            else if(tmp.y==m-1){
                e ff;
                ff.x = tmp.x;
                ff.y = tmp.y+1;
                ff.psf = psff+'V';
                q.push(ff);
            }
            else{
                if(dp[tmp.x+1][tmp.y] < dp[tmp.x][tmp.y+1]){
                e ff;
                ff.x = tmp.x+1;
                ff.y = tmp.y;
                ff.psf = psff+'H';
                q.push(ff);
                }
                else if(dp[tmp.x+1][tmp.y] > dp[tmp.x][tmp.y+1]){
                e ff;
                ff.x = tmp.x;
                ff.y = tmp.y+1;
                ff.psf = psff+'V';
                q.push(ff);
                }
                else {
                    
                    
                e ffb;
                ffb.x = tmp.x+1;
                ffb.y = tmp.y;
                ffb.psf = psff+'H';
                q.push(ffb);
                 e ff;
                ff.x = tmp.x;
                ff.y = tmp.y+1;
                ff.psf = psff+'V';
                q.push(ff);
                
                q.push(ff);   
                }
            }
    
     }  
    
}