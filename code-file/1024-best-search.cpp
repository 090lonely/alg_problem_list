//最优二叉搜索树
//搜索关键字有成功概率和失败概率。
//c(i,j)表示第 i+1 到 j 个key构造的最优二叉树的代价(平均搜索长度)，则C(0,n)是最后结果
//w(i,j)表示第 i+1 到 j 个key权值及第i到j个空隙权值和 
//w(i,j) = (qi+…+qj) + (pi+1+…+ pj)

// #include<bits/stdc++.h>
// using namespace std;
// const int N=505;
// double p[N];//p is the success probability
// double q[N];//q is the error probability
// int c[N][N];//c is the cost of the average search length
// int w[N][N];//w is the sum of the weight from i to j;
// int a[N];//a是用来记录关键字的；
// void solve(int n){
// //n is the number;
// memset(c, 0, sizeof(c));
// memset(w, 0, sizeof(w));
// for(int i=0;i<n;i++){
//     c[i][i]=0;
//     w[i][i]=q[i];
// }
// for(int x=1;x<n;x++){
//     for(int i=0;i<n-x;i++){
//         int j=i+x;
//         c[i][j]=INT_MAX;
//         w[i][j]=w[i][j-1]+q[j]+p[j];//this is the code which AI help me,but he miss something.
//         for(int k=i;k<j;k++){
//             int t=c[i][k]+c[k+1][j]+w[i][j];
//             if(t<c[i][j]){
//                 c[i][j]=t;
//             }
//         }
    
// }
// //cout<<c[0][n]<<endl;
// int ans=c[0][n];
// cout << fixed << setprecision(6) << ans << endl;//设置精度为六位小数点

// }
// }
// int main(){

//     int m=0;cin>>m;
//     while(m--){
//         int n=0;cin>>n;
//         memset(p,0,n);
//         memset(q,0,n+1);
//             for(int i=0;i<n;i++){
//             cin>>a[i];
//          }
//         for(int i=0;i<n;i++){
//             cin>>p[i];
//          }
//               for(int i=0;i<n+1;i++){
//             cin>>q[i];
//          }
//         solve(n);
        
//     }


//     return 0;
// }
//this is the code from my dude.
#include<iostream>
#include<iomanip>
#include<algorithm>
using namespace std;
double f[510][510];
double a[510], b[510], s1[510], s2[510];
double search(int p, int q) {
	if (p > q)return f[p][q] = 0;
	if (p == q)return f[p][q] = a[p] + b[p] + b[p + 1];//如果pq相等，说明只需要都将概率都加起来
	double ans = 1000000, ss;
	for (int i = p; i <= q; i++) {
		if (f[p][i - 1] < 0)f[p][i - 1] = search(p, i - 1);//记忆化搜索
		if (f[i + 1][q] < 0)f[i + 1][q] = search(i + 1, q);
		ss = s1[q] - s1[p - 1] + s2[q + 1] - s2[p - 1] + f[p][i - 1] + f[i + 1][q];
		if (ans > ss)ans = ss;
	}
	f[p][q] = ans;
	return ans;
}

int main() {
	int T, n, k;
	cin >> T;
	while (T--) {

		cin >> n;
		for (int i = 1; i <= n; i++) cin >> a[i];
		for (int i = 1; i <= n; i++) cin >> a[i];
		for (int i = 1; i <= n + 1; i++) cin >> b[i];

		for (int i = 0; i <= n + 1; i++)
			for (int j = 0; j <= n + 1; j++)
				f[i][j] = -1.0;

		s1[0] = s2[0] = 0;
		for (int i = 1; i <= n; i++) {
			s1[i] = s1[i - 1] + a[i];//s1是成功概率的前缀和
			s2[i] = s2[i - 1] + b[i];//s2是失败概率的前缀和
		}
		s2[n + 1] = s2[n] + b[n + 1];//最后一个单独算

		cout << fixed << setprecision(6) << search(1, n) << endl;

	}
	return 0;
}


