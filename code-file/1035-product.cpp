#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
//这个题黑美国测试用例，一个都没有草
using namespace std;

int main() {
    int T;
    cin >> T;
    
    while (T--) {
        int n;
        cin >> n;
        
        vector<int> c(n);
        vector<int> y(n);
        
        for (int i = 0; i < n; ++i) {
            cin >> c[i];
        }
        
        for (int i = 0; i < n; ++i) {
            cin >> y[i];
        }
        
        vector<long long> dp(n + 1, LLONG_MAX);
        dp[0] = 0;  // 初始条件，0个月的成本为0
        
        for (int i = 1; i <= n; ++i) {
            long long cost = 0;
            for (int j = i; j > 0; --j) {
                cost += c[j-1] * y[i-1];
                if (j < i) {
                    cost += (i - j) * y[i-1];
                }
                dp[i] = min(dp[i], dp[j-1] + cost);
            }
        }
        
        cout << dp[n] << endl;
    }
    
    return 0;
}
