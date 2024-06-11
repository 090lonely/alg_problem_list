#include<bits/stdc++.h>
using namespace std;
const int N=50005;
int a[N];
int main(){
int m;cin>>m;int n;int x;
while(m--){
cin>>n>>x;bool exist=false;
for(int i=0;i<n;i++){
cin>>a[i];
}
unordered_map<int,int> hashtable;
for(int i=0;i<n;i++){
    auto it=hashtable.find(x-a[i]);//先去寻找是否存在
    if(it!=hashtable.end())exist=1;//如果存在target-a【i】，那么就将exist置为一
    hashtable[a[i]]=i;//将该元素放到哈希表中
}

if(exist==true)cout<<"yes"<<endl;
else if (exist==false)cout<<"no"<<endl;

}
return 0;    
}