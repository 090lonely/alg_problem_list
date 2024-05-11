// #include<bits/stdc++.h>//为什么一直是answer wrong 淦
// using namespace std;
// int N,K;//n is the number ,k is the number of *
// long long res=0;//the result use long long to store
// int a[21]={0};//at most number//what i change this ,and this is correct
// long long dp[21][21]={0};//dp is for the first i element ,charu k ge *de jieguo .
// long long sum(int start,int end){
//     long long  s=0;
//     for(int i=start;i<=end;i++){
//         s+=a[i];
//     }
//     return s;
// }//求和
// int main(){
//     int m=0;cin>>m;
//     while(m--){
//         cin>>N>>K;
//         for(int i=1;i<=N;i++)a[i]=0;
//         for(int i=1;i<=N;i++){//the first is i=1;
//             cin>>a[i];
//         }
//         for(int i=1;i<=N;i++){//wrong easily
//             dp[i][0]=sum(1,i);
//         }//without * then there is all sum;
//         //the key part;
//         for(int i=2;i<=N;i++){//i个数只能插入i-1个乘号。
//             for(int j=1;j<=min(i-1,K);j++)//开始插入乘号，从插入一个乘号开始遍历，称号的个数不能大于i-1
//                 for(int k=2;k<=i;k++)//从1到i-1和从2到i的个数是相同的都是i-1；
//                 dp[i][j]=max(dp[i][j],dp[k-1][j-1]*sum(k,i));//其实就是在遍历所有乘号可以插入的位置
//         }
//       //  res=dp[N][K];
//         cout<<dp[N][K]<<endl;
//       // cout<<res<<endl;
//     }
//     return 0;
// }
#include<algorithm>
#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<string>
#include<stack>
#include<cmath>
#include<set>
using namespace std;
long long dp[25][25];
int num[25];
long long sum(int i,int j){
	long long a=0;
	for(int k=i;k<=j;k++){
		a+=num[k];
	}
	return a;
	
}
int main(){
	int t;
	cin>>t;
	while(t--){
		for(int i=0;i<25;i++)
			for(int j=0;j<25;j++)
				dp[i][j]=0;
		int n,k;
		cin>>n>>k;
		for(int i=1;i<=n;i++){
			cin>>num[i];
		}
		dp[1][0]=num[1];
		for(int i=2;i<=n;i++)
			dp[i][0]=dp[i-1][0]+num[i];
		for(int i=2;i<=n;i++){
			for(int j=1;j<=min(i-1,k);j++){
				for(int l=2;l<=n;l++){
					dp[i][j]=max(dp[i][j],dp[l-1][j-1]*sum(l,i));
				}
				
			}
		}
		cout<<dp[n][k]<<endl;
	}
	return 0;
} 