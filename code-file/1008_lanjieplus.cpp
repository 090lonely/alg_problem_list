//这个问题其实就是问你这个序列一共有多少个最长非升子序列
//例如第一个测试用例300 250 275 252 200 138 245
//1.300 275 252 200 138 
//2.250 245；
#include<bits/stdc++.h>
using namespace std;
const int N=105;
//the first function to calculat the longest non-increasing sequece
//n^2 time complexity
int longestNonIncreasingSubsequence(const vector<int>& heights) {
    int n = heights.size();
    vector<int> dp(n, 1);
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (heights[j] >= heights[i]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
    return *max_element(dp.begin(), dp.end());
}
//the second function to calculate the number of the interrupt missile
//nlogn time complexity
int minSystemsToInterceptAll(const vector<int>& heights) {
    // vector<int> ends;
    // for (int h : heights) {
    //     auto it = upper_bound(ends.begin(), ends.end(), h, greater<int>());//关键就是这个寻找上确界的函数使用
    //     if (it == ends.end()) {
    //         ends.push_back(h);//如果新元素更大，直接插入
    //     } else {//如果小，那么就会更换他的上确界，从而达到计算序列个数的目的。
    //         *it = h;
    //     }
    // }
    // return ends.size();
      vector<int> ends;
    for (int h : heights) {
        bool found = false;
        for (int &end : ends) {
            if (end >= h) {
                end = h;
                found = true;
                break;
            }
        }
        if (!found) {
            ends.push_back(h);
        }
    }
    return ends.size();
}
int main() {
    int m;
    cin >> m;
    while (m--) {
        int n;
        cin >> n;
        vector<int> heights(n);
        for (int i = 0; i < n; ++i) {
            cin >> heights[i];
        }
        int longestSubseqLength = longestNonIncreasingSubsequence(heights);
        int minSystems = minSystemsToInterceptAll(heights);
        cout << longestSubseqLength << " " << minSystems << endl;
    }
    return 0;
}