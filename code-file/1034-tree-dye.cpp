
#include <bits/stdc++.h>
#include <vector>
#include <cstring>
using namespace std;

// 最大节点数
const int MAX_N = 50005;//generally,we will use more than the number ;

// 动态规划数组
// dp[i][0]代表了第i个节点涂成黑色时，以其为根节点的子树的最大黑色节点数
// dp[i][1]代表了第i个节点涂成白色时，以其为根节点的子树的最大黑色节点数
int dp[MAX_N + 1][2];

// 记录每个节点是否有父节点
int hasP[MAX_N + 1];

// 邻接表（也就是每个节点的子节点）
vector<int>* chi;

// 递归形式的动态规划
void solve(int root) {
    // 如果root涂成黑色，则目前这棵树的黑色节点数为1
    dp[root][0] = 1;
    // 如果root涂成白色，则目前这棵树的黑色节点数为0
    dp[root][1] = 0;
    
    // 对该节点的子节点进行动态规划
    for(int i = 0; i < chi[root].size(); ++i) {
        // 动态规划
        solve(chi[root][i]);
        
        // 如果root涂成黑色，那么子节点只能涂成白色
        dp[root][0] += dp[chi[root][i]][1];
        // 如果root涂成白色，那么子节点可以涂成白色也可以涂成黑色
        dp[root][1] += max(dp[chi[root][i]][0], dp[chi[root][i]][1]);
    }
}

int main(int argc, const char * argv[]) {
    // 有T组测试数据
    int T;
    cin >> T;
    while((T--) > 0) {
        // 输入节点数量N
        int N;
        cin >> N;
        
        // 初始化邻接表，注意节点编号是从1开始的
        chi = new vector<int>[N + 1];
        
        // 初始化记录是否有父节点的数组
        memset(hasP, 0, sizeof(hasP));
        
        // 输入边
        for(int Ni = 0; Ni < N - 1; ++Ni) {
            // u到v有一条边
            int u, v;
            cin >> u >> v;
            chi[u].push_back(v);
            
            // 记录存在父节点
            hasP[v] = 1;
        }
        
        // 寻找根节点，从根节点向下动态规划
        // root随便赋了个值防止编译器报错
        int root = 0;
        for(int Ni = 1; Ni <= N; ++Ni) {
            if(hasP[Ni] == 0) {
                root = Ni;
                break;
            }
        }
        
        // 初始化动态规划数组
        memset(dp, 0, sizeof(dp));
        
        // 开始动态规划
        solve(root);
        
        // 输出结果并释放资源
        cout << max(dp[root][0], dp[root][1]) << endl;
        delete [] chi;
    }
    return 0;
}

