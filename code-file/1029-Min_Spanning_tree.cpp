//warning: min spanning tree can be implemented by kruskal ,which use union and sort;
#include <iostream>
#include <vector>
#include <algorithm>
#include<bits/stdc++.h>
using namespace std;

struct Edge {
    int u, v, weight;
    Edge(int _u, int _v, int w) : u(_u), v(_v), weight(w) {}
};

// Union-Find (Disjoint Set) data structure
struct UnionFind {
    vector<int> parent, rank;
    //parent：存储每个节点的父节点。
    //rank：存储每个节点的秩（或者称为深度），用于优化合并操作。
    //find(int x)：查找节点 x 的根节点（代表元素）。
    //unite(int x, int y)：将节点 x 所在的集合与节点 y 所在的集合合并。
    
    UnionFind(int n) {
        parent.resize(n);
        rank.assign(n, 0);
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }
    
    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
    
    void unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX == rootY) return;
        
        if (rank[rootX] < rank[rootY]) {
            parent[rootX] = rootY;
        } else if (rank[rootX] > rank[rootY]) {
            parent[rootY] = rootX;
        } else {
            parent[rootY] = rootX;
            rank[rootX]++;
        }
    }
};
bool cmp(Edge a, Edge b) {
	if (a.weight < b.weight) return true;
	return false;
}

int kruskal(vector<Edge>& edges, int n) {
    sort(edges.begin(), edges.end(), cmp);//diy the way to sort;

    UnionFind uf(n);
    int minCost = 0;
    int final_num=0;
    for (Edge& edge : edges) {//这个东西不能有const，否则会出现一堆调用函数库的问题，tmd
        if (uf.find(edge.u) != uf.find(edge.v)) {//不是同一个祖先，那么就不会形成环
            uf.unite(edge.u, edge.v);//合并
            minCost += edge.weight;//加入权值
            final_num++;
        }
        if(final_num==n-1)break;//啊啊啊啊啊啊啊啊罪魁祸首竟然是这一步，因为
        //已经有了n个点，所以其余所有的判断都会浪费时间
    }   
   if(final_num!=n-1)return -1;

    return minCost;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int n, E;
        cin >> n >> E;

        vector<Edge> edges;
        // Read edge information
        for (int i = 0; i < E; ++i) {
            int u, v, weight;
            cin >> u >> v >> weight;
            edges.emplace_back(u - 1, v - 1, weight);
        }

        int minCost = kruskal(edges, n);
   
        
        cout << minCost << endl;
    }

    return 0;
}
