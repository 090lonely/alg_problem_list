//尝试失败，感觉这个无人机好难啊，
#include<bits/stdc++.h>
using namespace std;
//first : 全程飞行距离15米，总采样时间90s，则速度为15/90；
//second：0-3采集1，3-8采集2，8-10采集1；
//已知，当速度小于13.90时，速度越大越好，那么这时候
const int N=155;
int l[N],r[N],T[N];//开始时间，结束时间和中间的采集持续时间
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
    //the output
    int num;//确定中间使用速度的次数
    vector<double> v;
//确定某一个区间的最佳速度。
    double sum=0;
    for(int i=0;i<n;i++){sum+=T[i];}
                      // for(int i=0;i<n;i++){
    //第一种情况，先考虑一些简单的情况再说
    int i=0;
    if((r[i]>=l[i+1])&&(r[i+1]>=r[i])){
     v.push_back(end/sum);
       cout<<v.size()<<endl;
    if(v.size()==1)cout<<end<<endl;
    for(int j=0;j<v.size();j++){cout<<v[j]<<" ";}
      }

 // }
    //第二种情况
     else if(r[i]>r[i+1]){
     v.clear();double temp_dis=r[i]-r[i+1]+l[i+1]-l[i];//这是给1的时间
      v.push_back(temp_dis/T[i]);
      v.push_back((double)(r[i+1]-l[i+1])/(double)T[i+1]);
         v.push_back(temp_dis/T[i]);
        cout<<v.size()<<endl;
    if(v.size()==1)cout<<end<<endl;
    else {cout<<l[i+1]<<" "<<r[i+1]<<" "<<r[i]<<endl;}
    for(int j=0;j<v.size();j++){cout<<v[j]<<" ";}
     }

    
   }
   return 0;
}