#include<iostream>//已经重新
#include<bits/stdc++.h>
using namespace std;
const int N=100010;
int q[N],t[N],n;
long long res;
void merge_sort(int l,int r){
 if(l>=r) return;
    
    int mid=l+r>>1;//速度比除法要快；
    merge_sort(l,mid),merge_sort(mid+1,r);//  “分”
    
    int k=0,i=l,j=mid+1;
    while(i<=mid&&j<=r)
    {
        if(q[i]<=q[j]) t[k++]=q[i++];
        else
        {
            t[k++]=q[j++];
            res+=mid-i+1;//  “治”//其实这一步就是在统计逆序对的数量
        }    
    }
    while(i<=mid) t[k++]=q[i++];//收尾：假如左端或者右端先填完了，得把另一端的数都加上。
    while(j<=r) t[k++]=q[j++];
    
    for(i=l,j=0;i<=r;i++,j++) q[i]=t[j];
}
int main(){
    int t=0;cin>>t;
    while(t--){
        res=0;//清空以前的逆序对数据******
    int n=0;cin>>n;
for(int i=0;i<n;i++)cin>>q[i];
merge_sort(0,n-1);
cout<<res<<endl;
for(int i=0;i<n;i++)q[i]=0;
    }
   return 0;
}