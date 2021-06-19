#include <bits/stdc++.h>
using namespace std;
# define int long long 
     
  
bool comp(vector<int>a,vector<int>b) {
    if(a[0] == b[0]) {
        if(a[1]!=b[1]){
            return(a[1]>b[1]);
        }
        else if(a[1]==b[1]) {
            return (a[2]>b[2]);
        }
    }

    return (a[0]<b[0]);
}
int func(vector<int>v1,vector<int>v2,vector<int>v3) {
    int mn=INT_MAX;
        int cnt=0;
        for(int i=0;i<v1.size();i++){
            int temp1=lower_bound(v2.begin(),v2.end(),v1[i])-v2.begin();
            int temp2=lower_bound(v3.begin(),v3.end(),v1[i])-v3.begin();
 
            if(temp1==v2.size()||temp2==v3.size()) break;
 
            int temp=max(v2[temp1],v3[temp2]);
            cnt=temp-v1[i]+1;
            mn=min(mn,cnt);
        }
        return mn;
}
int32_t main() {
	int tt;
    cin >> tt;
    while(tt--) {
        string s;
        cin >> s;
        vector<int>v1,v2,v3;
        for(int i=0;i<s.length();i++){
            if(s[i] == '1') {
                v1.push_back(i);
            }
            else if(s[i] == '2') {
                v2.push_back(i);
            }
            else {
                v3.push_back(i);
            }
        }
                if(v1.size() ==0 || v2.size()==0 || v3.size()==0){
            cout<<0<<endl;
            continue;
        }
        int temp1=func(v1,v2,v3);
        int temp2=func(v1,v3,v2);
        int temp3=func(v2,v1,v3);
        int temp4=func(v2,v3,v1);
        int temp5=func(v3,v1,v2);
        int temp6=func(v3,v2,v1);
        cout<<min({temp1,temp2,temp3,temp4,temp5,temp6})<<endl;
    }
}

   
