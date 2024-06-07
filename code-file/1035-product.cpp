//注意输入输出都有较大的值：
#include<iostream>
#include<algorithm>
#include<cstring>
#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
long long int c[N], y[N];

int main()
{
    int m;
    cin >> m;
    while (m--)
    {
        int n;//非常精妙的一个算法。
        cin >> n;
        memset(c, 0, sizeof c);
        memset(y, 0, sizeof y);
        for (int i = 0; i < n; i++)
        {
            cin >> c[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin >> y[i];
        }
        long long int ans = 0;//注意long long
        long long int tem = 1e9;//存储附加比较成本
        for (int i = 0; i < n; i++)
        {
            tem = min(tem, c[i]);//这里会进行计算，也就是上个月生产成本+1之后如果更小，那么就选择用上个月去进行生产
            ans+= tem * y[i];//ans加上代价
            tem++;//成本+1，因为这个月到下个月会加上存储成本去和下个月的生产成本去比较。
        }
        cout << ans << endl;
    }
    return 0;
}