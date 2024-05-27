//拓扑排序有两种解法：
//kahn也就是入度为零的节点，dfs解决。
//*****这段代码是维护一个入度为0的队列；
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
//maybe  bacause i used the wrong compiler
bool topologicalSort(int n, vector<vector<int>>& adjList, vector<int>& result) {
    vector<int> inDegree(n + 1, 0);
    
    // Calculate in-degrees of all nodes
    for (int i = 1; i <= n; ++i) {
        for (int j : adjList[i]) {
            inDegree[j]++;
        }
    }
    
    queue<int> q;
    
    // Enqueue all nodes with in-degree 0
    for (int i = 1; i <= n; ++i) {
        if (inDegree[i] == 0) {
            q.push(i);
        }
    }
    
    int count = 0;
    
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        result.push_back(node);
        count++;
        
        // Reduce in-degree of adjacent nodes
        for (int adj : adjList[node]) {
            inDegree[adj]--;
            if (inDegree[adj] == 0) {
                q.push(adj);
            }
        }
    }
    
    // If count of visited nodes is not equal to the number of nodes, there is a cycle
    return (count == n);
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n, m;
        cin >> n >> m;
        
        vector<vector<int>> adjList(n + 1);
        
        for (int i = 0; i < m; ++i) {
            int x, y;
            cin >> x >> y;
            adjList[x].push_back(y);
        }
        
        vector<int> result;
        if (topologicalSort(n, adjList, result)) {
            for (int i = 0; i < result.size(); ++i) {
                if (i > 0) cout << " ";
                cout << result[i];
            }
            cout << endl;
        } else {
            cout << "0" << endl;
        }
    }
    
    return 0;
}
