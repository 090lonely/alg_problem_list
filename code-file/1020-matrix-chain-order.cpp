// //this is wrong code，and  i feel mad about this。
// #pragma GCC optimize(3,"Ofast","inline")
// #include <iostream>
// #include <vector>
// #include <climits>

// using namespace std;

// // 用于存储最优解的矩阵链乘的总代价
// vector<vector<long long>> m;
// vector<vector<int>> s;

// long long MatrixChainOrder(const vector<int>& p) {
//     int n = p.size() - 1;
//     m.resize(n + 1, vector<long long>(n + 1));
//     s.resize(n + 1, vector<int>(n + 1, 0));

//     // 动态规划填表
//     for (int l = 2; l <= n; ++l) { // l 是链的长度
//         for (int i = 1; i <= n - l + 1; ++i) {
//             int j = i + l - 1;
//             m[i][j] = LLONG_MAX;
//             for (int k = i; k <= j - 1; ++k) {
//                 long long q = m[i][k] + m[k + 1][j] + (long long)p[i - 1] * p[k] * p[j];
//                 if (q < m[i][j]) {
//                     m[i][j] = q;
//                     s[i][j] = k;
//                 }
//             }
//         }
//     }
//     return m[1][n];
// }

// int main() {
//     int M;
//     cin >> M; // 组数
//     while (M--) {
//         int N;
//         cin >> N; // 矩阵个数
//         vector<int> p(N + 1); // 存储矩阵链的维度
//         for (int i = 0; i < N; ++i) {
//             cin >> p[i];
//             if (i != N ) {
//                 cin >> p[i + 1];
//             }
//         }
//         long long result = MatrixChainOrder(p);
//         cout << result << endl;
//     }
//     return 0;
// }
#pragma GCC optimize(3,"Ofast","inline")//性能优化
#include <iostream>
using namespace std;
long long T, n, x[510], y[510];//x是行数，y是列数
long long f[510][510] = { 0 };
long long cal(int p, int q) {//记忆化搜索+剪枝
	if (p + 1 == q)return f[p][q] = x[p] * y[p] * y[q];
	long long m = 2147483647;
	for (int i = p; i < q; i++) {//这里i其实就是PPT当中的k也就是切割的位置。
		if (f[p][i]==-1)f[p][i] = cal(p, i);
		if (f[i + 1][q]==-1)f[i + 1][q] = cal(i + 1, q);
		if (m > f[p][i] + f[i + 1][q] + x[p] * y[i] * y[q])m = f[p][i] + f[i + 1][q] + x[p] * y[i] * y[q];
	}
	return f[p][q] = m;
}
int main() {

	cin >> T;
	while (T--) {
		cin >> n;
		for (int i = 0; i < n; i++)cin >> x[i]>>y[i];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				f[i][j] = -1;//f[i][j] 初始化
			}
			f[i][i] = 0;//自己称自己是0；
		}
		cout << cal(0, n - 1) << endl;//调用递归函数
	}
	return 0;
}
