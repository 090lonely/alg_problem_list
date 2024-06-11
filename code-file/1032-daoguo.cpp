// //for 3 30 50 if one country,p is 35%,two is 50%,3 is 15%;
// //i hear someone say we can use contribution,
// #include<bits/stdc++.h>
// using namespace std;
// int main(){
//     int m=0;cin>>m;
//     while(m--){
//         double ans=0;
// 		vector<double>table;
// 		int n;
// 		double p;
// 		cin >> n;
// 		table.push_back(0);//table[0]=0;table[1]=0.5;
// 		for (int j = 1; j < n; j++)
// 		{
// 			cin >> p;
// 			table.push_back(p / 100);
// 		}

// 		ans=countries(table, n - 1);

// 		cout << fixed << setprecision(6) << ans << endl;//设置精度为六位小数点
	
//     }

//     return 0;
// }
#include<iostream>
#include<cstdio>
using namespace std;
int main() {
	int T,t,n; cin >> T;
	while (T--) {
		cin >> n;int ans = 100;
		for (int i = 0; i <n-1;i++) {
			cin >> t;
			ans += t;
		}
		printf("%.6lf\n", ans / 100.0);
    }
	return 0;
}