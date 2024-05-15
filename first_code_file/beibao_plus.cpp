// #include<bits/stdc++.h>
// using namespace std;
// const int N=505;//***i think its a good habit to write code annotation in english***
// const int C=105;
// int max_val=0;
// int s[N],v[N];//s is the weight of each gem,v is the value of gem; 
// bool bag_is_full[N];
// int now=0;//now is for record of the current weight of the bag;
// // const int INF=0x3f3f3f3f;
// // const int NINF=-INF-1;
// int main(){
//     int m=0;cin>>m;int n,c;//n is number of the gem,c is capacity of the backpack; 
//     while(m--){
//         cin>>n>>c;
//         for(int i=0;i<n;i++){
//             cin>>s[i]>>v[i];
//         }
//          //vector<vector<int>> dp(n + 1, vector<int>(c + 1, 0)); // 定义状态
//          int dp[N+1][C+1];
//        //  memset(dp,NINF,sizeof(dp));
//          for(int i=1;i<=n;i++){
//             dp[i][0]=0;
//             for(int j=1;j<=c;j++){
// if(bag_is_full[j-s[i-1]]==1){
//  if(j<s[i-1])dp[i][j]=dp[i-1][j];//the condition should be j<s[j-1] unless you forget the s[0];
//                 else{
//                     dp[i][j]=max(dp[i-1][j],dp[i-1][j-s[i-1]]+v[i-1]);
//                     bag_is_full[j]==1;
//                        }
// }

 

//             }
              
//                  //   if(dp[i-1][j]<dp[i-1][j-s[i-1]]+v[i-1]){item[i-1]=true;}
//                     //this way is wrong
//                   //  if(dp[i-1][j]<dp[i-1][j-s[i-1]]+v[i-1])now+=s[i-1];
//                     }
//         // if(dp[n][c]<0)max_val=0;
//         //else {max_val=dp[n][c];}
//           if(bag_is_full[n]==0)max_val=0;
//         else {max_val=dp[n][c];}
//         cout<<max_val<<endl;
//     }
//     return 0;
// }
//01背包--恰好装满
#include <iostream>
using namespace std;
#define max(N1,N2) N1>N2?N1:N2
#define INF 0x80000000
int main()
{
    int m=0;cin>>m;
	int V, N;
	while (m--)//输入背包容量和物体数
	{
        cin>>N>>V;
		int v[1000], w[1000];
		int f[10000] ;
		//下面是初始化所有的无效状态
		for (int i = 0; i < 10000; i++)
		{
			f[i] = INF;
		}
		//f[0]是有效状态
		f[0] = 0;
		//输入每个物体的体积和价值
		for (int i = 1; i <= N; i++)
		{
			cin >> v[i] >> w[i];
		}
		//动态规划过程
		for (int i = 1; i <= N; i++)
		{
			for (int j = V; j >= v[i]; j--)
			{
				f[j] = max(f[j], f[j - v[i]] + w[i]);
				if (f[j] < 0)
					f[j] = INF;
			}
		}
		//判断能否恰好装满背包
		if (f[V] > 0)
		{
			cout << f[V] << endl;//背包恰好装满了，输出结果
		}
		else
		{
			cout << 0 << endl;//背包不能恰好装满
		}
	}
	return 0;
}