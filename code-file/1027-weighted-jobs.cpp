//核心策略：
//***贪心+动态规划***
#include<bits/stdc++.h>
using namespace std;
struct Party{
	int st;
	int ed;
	int vl;
	int id;
}party[10001];//每一个活动的结构体

int frt[10001],dp[10001];//frt数组记录每一个活动的前一个不冲突的活动，dp是记录动态规划结果的数组
bool cmp(Party p1,Party p2){
	return p1.ed<p2.ed;
}

int main(){
    int m;
	int n;
	cin>>m;
	while(m--){
		cin>>n;
		memset(frt,0,sizeof(frt));//每一次循环开始前都要清零
		memset(dp,0,sizeof(dp));
		for(int i=1;i<=n;++i){
			cin>>party[i].st>>party[i].ed>>party[i].vl;
		}
        //key
		sort(party+1,party+n+1,cmp);//按照结束时间大小排序
		for(int i=1;i<=n;++i) party[i].id=i;
		for(int i=n;i>=1;--i){
			for(int j=n-1;j>=1;--j){
				if(party[j].ed<=party[i].st){
					frt[i]=party[j].id;break;
				}
			}
		}
		
		for(int i=1;i<=n;++i){
			dp[i]=max(dp[i-1],dp[frt[i]]+party[i].vl);//要么不选择当前活动，要么选当前活动
		}
		cout<<dp[n]<<endl;
	}

  return 0;
}
   
