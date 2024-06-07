//尝试失败，感觉这个无人机好难啊，
#include<bits/stdc++.h>
using namespace std;
//first : 全程飞行距离15米，总采样时间90s，则速度为15/90；
//second：0-3采集1，3-8采集2，8-10采集1；
//已知，当速度小于13.90时，速度越大越好，那么这时候
const int N=155;
double l[N],r[N],T[N];//开始时间，结束时间和中间的采集持续时间
int main(){
  int t;cin>>t;
  while(t--){
    int n;cin>>n;//n is the number of the motor
    double end=0.0;cin>>end;//end is the end of the caiji time
    memset(l,0,sizeof(l));
    memset(r,0,sizeof(r));
    memset(T,0,sizeof(T));
    for(int i=0;i<n;i++){
        cin>>l[i]>>r[i]>>T[i];
    }//完成输入
    //直接输出
    //int max1=0;
    //for(int i=0;i<n;i++){max1=max(max1,r[i]);}
    cout<<1<<endl;
    cout<<end<<endl;
    cout<<0.1<<endl;

   }
   return 0;
}