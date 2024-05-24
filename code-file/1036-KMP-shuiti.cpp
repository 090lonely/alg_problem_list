#include<bits/stdc++.h>
using namespace std;
// 计算模式串的部分匹配表（前缀函数）
vector<int> computePrefixFunction(const string& pattern) {
    int m = pattern.length();
    vector<int> prefix(m);
    int k = 0;
    prefix[0] = 0;

    for (int q = 1; q < m; q++) {
        while (k > 0 && pattern[k] != pattern[q]) {
            k = prefix[k - 1];
        }
        if (pattern[k] == pattern[q]) {
            k++;
        }
        prefix[q] = k;
    }
    return prefix;
}

// KMP算法查找模式串在文本串中出现的次数
int KMPMatcher(const string& text, const string& pattern) {
    int n = text.length();
    int m = pattern.length();
    vector<int> prefix = computePrefixFunction(pattern);
    int q = 0;
    int count = 0;

    for (int i = 0; i < n; i++) {
        while (q > 0 && pattern[q] != text[i]) {
            q = prefix[q - 1];
        }
        if (pattern[q] == text[i]) {
            q++;
        }
        if (q == m) {
            count++;
            q = prefix[q - 1];
        }
    }
    return count;
}

int main(){
    int m=0;cin>>m;
    while(m--){
        int n,m;
        cin>>n>>m;
        string s,t;//s is the longstring,t is the target string
        cin>>s>>t;
        //now let us begin;
        cout<<KMPMatcher(s,t)<<endl;
    }



    return 0;
}