#include <iostream>
#include <vector>
#include <climits>
using namespace std;
int maxSubArraySum(const vector<int>& a) {
    int n = a.size();
    if (n == 0) return 0;

    vector<int> maxSums(n, 0);
    maxSums[0] = a[0];//chushihua
    int maxSum = a[0];

    for (int i = 1; i < n; i++) {//dp
        maxSums[i] = max(a[i], maxSums[i - 1] + a[i]);//如果自己够大，那就自己上，如果前一个人的maxSum//
        //加上自己更大，那就一起
        maxSum = max(maxSum, maxSums[i]);
    }

    return maxSum;
}

int main() {
    // 示例数组
    int t=0;cin>>t;
while(t--){
   vector<int> a;int n;cin>>n;
   for(int i=0;i<n;i++){
    int temp;cin>>temp;a.push_back(temp);
   }
    int maxSum = maxSubArraySum(a);
    cout << maxSum << endl;
}

    return 0;
}