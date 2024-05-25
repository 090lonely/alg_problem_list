//i dont understand why my code is not allowed f***
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 定义钢条长度和对应价格的价格表
vector<pair<int, int>> price_table;

// 计算最大总收益
int maxProfit(int n) {
    // dp[i]表示长度为i的钢条所能获得的最大总收益
    vector<int> dp(n + 1, 0);

    // 计算每个长度的最大总收益
    for (int i = 1; i <= n; ++i) {
        for (auto& p : price_table) {
            int len = p.first;
            int price = p.second;
            if (len <= i) {
                dp[i] = max(dp[i], dp[i - len] + price);
            }
        }
    }

    return dp[n];
}

int main() {
    int m;
    cin >> m;
    while (m--) {
        int n, k;
        cin >> n >> k;
        price_table.clear();
        for (int i = 0; i < k; ++i) {
            int len, price;
            cin >> len >> price;
            price_table.push_back({len, price});
        }
        cout << maxProfit(n) << endl;
    }
    return 0;
}
// #include<bits/stdc++.h>
// using namespace std;
// //破题说不清楚，就是这道题不同于书上的给定一个数组，1，2，3，4对应长度的价格是1，6，7，9
// //这题是说输入k个键值对，（长度，价格）
// const int N=10005;
// int l[N],v[N];//l is the length,v is the price;
// //the recursive code
//      int n;//length
//         int k;//k is the number of the key-value;
// int cut_rod(int len, int price_arr[])
// {
//     if (len == 0||len<0)
//         return 0;
 
//     int best_profit = -100;
//     for (int i = 0; i <= k-1; i++)//注意你读进来的数起始下标
//     {
//         if(len>=l[i])//druntime error#####
//         best_profit = max(best_profit, price_arr[i] + cut_rod(len-l[i], price_arr));//the length is not linear,special
//         else continue;
//     }
//     return best_profit==-100?0:best_profit;
// }
// int main(){
//     int m=0;cin>>m;
//     while(m--){
//         cin>>n>>k;
//         for(int i=0;i<k;i++){
//            cin>>l[i]>>v[i];
//         }int max_val=0;
//     int profit = cut_rod(n, v);
//     cout  << profit << endl;
//        //  vector<vector<int>> dp(k + 1, vector<int>(n + 1, 0)); // 定义状态
//     }
//     return 0;
// }
//     //    int dp[N][N];
//     //      for(int i=1;i<=k;i++)
//     //        for(int j=1;j<=n;j++)
//     //             if(j<l[i-1])dp[i][j]=dp[i-1][j];//the condition should be j<s[j-1] unless you forget the s[0];
//     //             else{
//     //                 dp[i][j]=max(dp[i-1][j],dp[i][j-l[i-1]]+v[i-1]);//the difference is in the second item about i-1;
//     //                 }
//     //                  max_val=dp[k][n];
//     //                  cout<<max_val<<endl;