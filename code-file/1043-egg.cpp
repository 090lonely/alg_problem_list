#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int eggDrop(int k, int n) {
    vector<vector<int>> dp(k + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= k; ++i) {
        dp[i][0] = 0;
        dp[i][1] = 1;
    }

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
    }

    for (const auto &testCase : testCases) {
        int k = testCase.first;
        int n = testCase.second;
        cout << eggDrop(k, n) << endl;
    }

    return 0;
}
