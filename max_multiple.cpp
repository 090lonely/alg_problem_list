#include<bits/stdc++.h>
//#include<time.h>
using namespace std;
int main(){
  //  clock_t start,end;
   // start = clock();
int t=0;int n=0,k=0;
string snum; cin>>t;
long long dp[41][7]; 
	//将dp的所有元素初始化为0
	memset(dp,0,sizeof(dp));
	//num[i][j]表示取角标i~j（包括i,j）之间的数字串
	long long num[41][41];
    //将字符串转换为数字
while(t--){
    cin>>n>>k;
    cin>>snum;

	for(int i=0;i<n;i++) 
	{
		int temp = 0;
		for(int j=i;j<n;j++)
		{
		string substring =snum.substr(i,j-i+1);//j-i的差是距离，加上一才是长度
        num[i][j]=stoll(substring);
		}
    }
    for(int i=0;i<n;i++){
        dp[i][0]=num[0][i];
    }
for(int i=0;i<n;i++)
   for(int j=1;j<=k;j++)//问题在于一个乘号的时候j<k就不成立了，呜呼。
       for(int k1=0;k1<i;k1++)
				dp[i][j] = max(dp[k1][j-1]*num[k1+1][i],dp[i][j]);

 cout<<dp[n-1][k]<<endl;
}

     return 0;
}
// #include <bits/stdc++.h>
// #include <time.h>
// using namespace std;

// int main() {
//    // clock_t start, end;
//   //  start = clock();

//     int t;
//     cin >> t;

//     while (t--) {
//         int n, k;
//         string snum;
//         cin >> n >> k >> snum;

//         // 将字符串转换为数字
//         vector<vector<long long>> nums[41][41];
//   	for(int i=0;i<n;i++) 
// 	{
// 		int temp = 0;
// 		for(int j=i;j<n;j++)
// 		{
// 		string substring =snum.substr(i,j-i+1);//j-i的差是距离，加上一才是长度
//         nums[i][j] = stoll(substring);
// 		}
//     }

//         // dp[i][j] 表示在 nums[0:i] 中插入 j 个乘号能得到的最大乘积
//         vector<vector<long long>> dp(n, vector<long long>(k + 1, 0));

//         // 初始化 dp 数组
//         for (int i = 0; i < n; ++i) {
//             dp[i][0] = nums[0][i];
//         }

//         // 计算 dp 数组
//         for (int j = 1; j <= k; ++j) {
//             for (int i = 0; i < n; ++i) {
//                 for (int k1 = 0; k1 < i; ++k1) {
//                     dp[i][j] = max(dp[i][j], dp[k1][j - 1] * accumulate(nums.begin() + k1 + 1, nums.begin() + i + 1, 1LL));
//                 }
//             }
//         }

//         cout << dp[n - 1][k] << endl;
//     }

//    // end = clock();
//   //  cout << "time = " << double(end - start) / CLOCKS_PER_SEC << "s" << endl;
// //
//     return 0;
// }
