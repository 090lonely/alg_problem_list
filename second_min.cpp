#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int N=1005;
int main(){
    int m=0;int n=0;
    cin>>m;int a[N];
   
    for(int i=0;i<m;i++){
     cin>>n; vector<int> v;
     for(int j=0;j<n;j++){
        cin>>a[j];v.push_back(a[j]);
     }
     sort(v.begin(),v.end());
     if(n<2||v[0]==v[1]) cout<<0<<endl;
     else cout<<v[1]<<endl;
    }
     return 0;
}