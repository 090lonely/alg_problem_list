//以下是GPT优化过的代码，貌似应该是只把我的二维数组换成了vector，但是都过了曹操
#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        string snum;
        cin >> snum;
        vector<vector<long long>> dp(n, vector<long long>(k + 1, LLONG_MIN));
        vector<vector<long long>> num(n, vector<long long>(n, 0));
        // 将字符串转换为数字，并预处理所有可能的子串数值
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                num[i][j] = stoll(snum.substr(i, j - i + 1));
            }
        }
        // 初始化dp数组
        for (int i = 0; i < n; i++) {
            dp[i][0] = num[0][i];
        }
        // 动态规划填表
        for (int i = 1; i < n; i++) {
            for (int j = 1; j <= k; j++) {
                for (int k1 = 0; k1 < i; k1++) {
                    dp[i][j] = max(dp[i][j],  num[k1 + 1][i]*dp[k1][j - 1]);
                }
            }
        }
        // 输出结果
        cout << dp[n - 1][k] << endl;
    }
    return 0;
}
//以下是我的没有过全部测试用例的代码
// #include<bits/stdc++.h>
// //#include<time.h>
// using namespace std;
// int main(){
//   //  clock_t start,end;
//    // start = clock();
// int t=0;int n=0,k=0;
// string snum; cin>>t;
// long long dp[41][7]; 
// 	//将dp的所有元素初始化为0
//     //dp[i][j]意思是对于前i个元素，一共有j个乘号的时候最大乘积
// 	memset(dp,0,sizeof(dp));
// 	//num[i][j]表示取角标i~j（包括i,j）之间的数字串
// 	long long num[41][41];
//     //将字符串转换为数字
// while(t--){
//     cin>>n>>k;
//     cin>>snum;//use the string to store the long number;

// 	for(int i=0;i<n;i++) 
// 	{
// 		int temp = 0;
// 		for(int j=i;j<n;j++)
// 		{
// 		string substring =snum.substr(i,j-i+1);//j-i的差是距离，加上一才是长度
//         num[i][j]=stoll(substring);
// 		}
//     }
//     for(int i=0;i<n;i++){
//         dp[i][0]=num[0][i];
//     }
// for(int i=0;i<n;i++)
//    for(int j=1;j<=k;j++)//问题在于一个乘号的时候j<k就不成立了，呜呼。
//        for(int k1=0;k1<i;k1++)
// 				dp[i][j] = max(dp[k1][j-1]*num[k1+1][i],dp[i][j]);

//  cout<<dp[n-1][k]<<endl;
// }

//      return 0;
// }

