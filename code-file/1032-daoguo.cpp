//for 3 30 50 if one country,p is 35%,two is 50%,3 is 15%;
//i hear someone say we can use contribution,
#include<bits/stdc++.h>
using namespace std;
double countries(vector<double>& country,int n){
double ans=0;


return ans;
}
int main(){
    int m=0;cin>>m;
    while(m--){
        double ans=0;
		vector<double>table;
		int n;
		double p;
		cin >> n;
		table.push_back(0);//table[0]=0;table[1]=0.5;
		for (int j = 1; j < n; j++)
		{
			cin >> p;
			table.push_back(p / 100);
		}

		ans=countries(table, n - 1);

		cout << fixed << setprecision(6) << ans << endl;//设置精度为六位小数点
	
    }






    return 0;
}