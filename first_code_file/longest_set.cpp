#include<bits/stdc++.h>
using namespace std;
 int longestCommonSubsequence(string text1, string text2) {
        int m = text1.length(), n = text2.length();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        for (int i = 1; i <= m; i++) {
            char c1 = text1.at(i - 1);
            for (int j = 1; j <= n; j++) {
                char c2 = text2.at(j - 1);
                if (c1 == c2) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;//状态转移方程至关重要，事关你两个for循环在干什么
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[m][n];
    }
int main(){
int m=0;cin>>m;
while(m--){
    string t1,t2;
    cin>>t1>>t2;
    int res=longestCommonSubsequence(t1,t2);//你真笨，写代码，传参数都能有问题。
    cout<<res<<endl;
}
    return 0;
}