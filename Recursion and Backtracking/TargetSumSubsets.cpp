/*
1. You are given a number n, representing the count of elements.
2. You are given n numbers.
3. You are given a number "tar".
4. Complete the body of printTargetSumSubsets function - without changing signature -
 to calculate and print all subsets of given elements, the contents of which sum to "tar".
*/


#include<bits/stdc++.h>
using namespace std;
bool vis[100][100];
int ar[100];
void sss1(int ar[100],int n,int idx,int m,string s,int sos) {
    
    // agr negative element nahi hai tb sos>m bhi lgani padegi
    // varna tle ayega

    if(idx==n|| sos>m ){
            if(sos==m)
            cout << s << "." << endl;
        return ;
    }
    
    // basically , hr element ke paas do option hain, ya to vo subset mmein ayega,ya nahi aayega!!
    //dono cases aese handle honge, aur index ko as a parameter rkhna zaroori hai

    sss1(ar,n,idx+1,m,s+to_string(ar[idx])+", ",sos+ar[idx]);
    sss1(ar,n,idx+1,m,s,sos);
}
void sss2(vector<int> &A,vector<vector<int>> &sol,vector<int> curr,int B,int sum)
{   if(sum>B) return;
    if(sum==B)
    {
        sort(curr.begin(),curr.end());
        for(auto x:sol)
        {
            if(x==curr) return;
        }
        sol.push_back(curr);
        return;
    }
    
    for(int i=0;i<A.size();i++)
    {
        if(sum+A[i]<=B)
        {
            curr.push_back(A[i]);
            sss2(A,sol,curr,B,sum+A[i]);
            curr.pop_back();
        }
    }
    return;
}

int32_t main() 

{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n;
    int ar[n];
    for(int i=0;i<n;i++)
        cin >> ar[i];
    cin >> m;
    sss1(ar,n,0,m,"",0);

}