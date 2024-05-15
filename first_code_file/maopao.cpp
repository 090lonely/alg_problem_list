#include<iostream>
using namespace std;
int main(){
    int m;int n;cin>>m;
 while(m--){
    cin>>n;int a[1005];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
  for(int i=0;i<n-1;i++){
    if(a[i]>a[i+1]){
        int temp=a[i];a[i]=a[i+1];
        a[i+1]=temp;
    }
  }
  for(int i=0;i<n;i++){
    cout<<a[i]<<" ";
  }
  cout<<endl;
 }
    return 0;
}
// #include<iostream>
// #include<vector>
// #include<algorithm>
// using namespace std;
// int main(){
//     int m;int n;cin>>m;
//     vector<int> v[1005];
//     int num=0;
//  while(m--){
//     cin>>n;int t;
//     for(int i=0;i<n;i++){
//         cin>>t;v[num].push_back(t);
//     }
//   for(int i=0;i<n-1;i++){
//     if(v[num][i]>v[num][i+1]){
//         int temp=v[num][i];v[num][i]=v[num][i+1];
//        v[num][i+1]=temp;
//     }
//   }
//    num++;
//  }
//   for(int i=0;i<m;i++){
//     for(int j=0;j<v[i].size();j++){
//         cout<<v[i][j]<<" ";
//     }
//     cout<<endl;
//   }
//     return 0;
// }