// #include<bits/stdc++.h>
// #include<iostream>
// using namespace std;
// const int N=505;
// #define INF 0x3f3f3f3f
// //const int N2=10005;
// int d[N]={0};//report the min distance  d is distance
// int g[N][N]={0};//report the egdes
// bool v[N]={false};//make sure if one onde is determinitic   v is visited
// int main(){
// //只过了三个测试用例，淦
//    int T=0;
//    cin>>T;//T is the number of the example
//    while(T--){memset(g,INF,sizeof(g));//每次循环都需要更新******
//      int n;int E;int s;int t;//n is the number nodes,E is edges ,s is start,t is target;
//      cin>>n>>E>>s>>t;int x1,y1,z1;
//      for(int i=0;i<E;i++){
//         cin>>x1>>y1>>z1;
//         g[x1][y1]=min(g[x1][y1],z1);//debug出错了，这里g[x][y]默认应该是无穷大。
//      }//finish all input;
//      memset(v,0,sizeof(v));
//      for(int i=1;i<=n;i++){//所有的循环都是错的
//       d[i]=(i==1?0:INF);
//      }
//      v[1]=1;
//      for(int i=0;i<n;i++){
//       int x,m=INF;
//       for(int y=1;y<=n;y++)if(!v[y]&&g[s][y]<=m){x=y;d[y]=min(d[y],g[s][y]);m=d[y];}
//       v[x]=1;
//       for(int y=1;y<=n;y++)d[y]=min(d[y],d[x]+g[x][y]);
//      }
//     if(d[t]!=INF)cout<<d[t]<<endl;
//     else{cout<<"-1"<<endl;}
// }
// }
#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max();//这一行感觉很多地方都会用到

struct Edge {
    int to;
    int weight;
    Edge(int _to, int _weight) : to(_to), weight(_weight) {}
};

typedef vector<vector<Edge>> Graph;//图使用邻接表的方式实现

vector<int> dijkstra(const Graph& graph, int source, int destination) {
    int n = graph.size();
    vector<int> dist(n, INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    dist[source] = 0;
    pq.push(make_pair(0, source));

    while (!pq.empty()) {
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();

        if (u == destination) {
            break; // 如果已经到达目标顶点，就不需要再继续搜索了
        }

        if (d > dist[u]) {
            continue; // 如果当前距离大于已知最短距离，就跳过
        }

        for (const auto& edge : graph[u]) {
            int v = edge.to;
            int weight = edge.weight;
            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push(make_pair(dist[v], v));
            }
        }
    }

    return dist;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int n, E, s, t;
        cin >> n >> E >> s >> t;

        Graph graph(n);
        for (int i = 0; i < E; ++i) {
            int u, v, w;
            cin >> u >> v >> w;
            graph[u - 1].push_back(Edge(v - 1, w));
            graph[v - 1].push_back(Edge(u - 1, w)); // 无向图，需双向添加边
        }

        vector<int> dist = dijkstra(graph, s - 1, t - 1);

        if (dist[t - 1] == INF) {
            cout << -1 << endl;
        } else {
            cout << dist[t - 1] << endl;
        }
    }

    return 0;
}
