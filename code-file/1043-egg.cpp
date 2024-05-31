#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int eggDrop(int k, int n) {//dp[k][n]代表K个鸡蛋n层楼的最小移动长度。
    vector<vector<int>> dp(k + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= k; ++i) {
        dp[i][0] = 0;
        dp[i][1] = 1;
    }//完成初始化

    for (int j = 1; j <= n; ++j) {
        dp[1][j] = j;
    }

    for (int i = 2; i <= k; ++i) {
        for (int j = 2; j <= n; ++j) {
            int low = 1, high = j;
            while (low + 1 < high) {
                int mid = (low + high) / 2;
                int breakCount = dp[i - 1][mid - 1];
                int noBreakCount = dp[i][j - mid];

                if (breakCount > noBreakCount) {
                    high = mid;
                } else {
                    low = mid;
                }
            }
            //这一步是啥意思，最大值的最小值
// 我们可以考虑使用动态规划来做这道题，状态可以表示成 (k,n)，其中 k 为鸡蛋数，n 为楼层数。
//当我们从第 x 楼扔鸡蛋的时候：

// 如果鸡蛋不碎，那么状态变成 (k,n−x)即我们鸡蛋的数目不变，但答案只可能在上方的 n−x 层楼了。也就是说，我们把原问题缩小成了一个规模为 (k,n−x)(k, n-x)(k,n−x) 的子问题；

// 如果鸡蛋碎了，那么状态变成 (k−1,x−1)即我们少了一个鸡蛋，但我们知道答案只可能在第 x 楼下方的 x−1 层楼中了。也就是说，我们把原问题缩小成了一个规模为 (k−1,x−1)(k-1, x-1)(k−1,x−1) 的子问题。

            dp[i][j] = 1 + min(max(dp[i - 1][low - 1], dp[i][j - low]),
                               max(dp[i - 1][high - 1], dp[i][j - high]));
        }
    }

    return dp[k][n];
}

int main() {
    int nums;
    cin >> nums;
    vector<pair<int, int>> testCases(nums);

    for (int i = 0; i < nums; ++i) {
        cin >> testCases[i].first >> testCases[i].second;
    }//虽然使用pair对，但其实没有什么卵用。

    for (const auto &testCase : testCases) {
        int k = testCase.first;
        int n = testCase.second;
        cout << eggDrop(k, n) << endl;
    }

    return 0;
}
