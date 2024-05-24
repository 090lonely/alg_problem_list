#pragma GCC optimize(3,"Ofast","inline")
#include <iostream>
#include <vector>
#include <climits>

using namespace std;

// 用于存储最优解的矩阵链乘的总代价
vector<vector<long long>> m;
vector<vector<int>> s;

long long MatrixChainOrder(const vector<int>& p) {
    int n = p.size() - 1;
    m.resize(n + 1, vector<long long>(n + 1));
    s.resize(n + 1, vector<int>(n + 1, 0));

    // 动态规划填表
    for (int l = 2; l <= n; ++l) { // l 是链的长度
        for (int i = 1; i <= n - l + 1; ++i) {
            int j = i + l - 1;
            m[i][j] = LLONG_MAX;
            for (int k = i; k <= j - 1; ++k) {
                long long q = m[i][k] + m[k + 1][j] + (long long)p[i - 1] * p[k] * p[j];
                if (q < m[i][j]) {
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }
    return m[1][n];
}

int main() {
    int M;
    cin >> M; // 组数
    while (M--) {
        int N;
        cin >> N; // 矩阵个数
        vector<int> p(N + 1); // 存储矩阵链的维度
        for (int i = 0; i < N; ++i) {
            cin >> p[i];
            if (i != N ) {
                cin >> p[i + 1];
            }
        }
        long long result = MatrixChainOrder(p);
        cout << result << endl;
    }
    return 0;
}
