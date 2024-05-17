#include<iostream>
#include<cstring>
#include<bits/stdc++.h>
using namespace std;
const int N=105;
//this question can be solved in the same way of the longest increase sequence;
int main(){
    int m=0;cin>>m;
    while(m--){
        int n=0;cin>>n;int a[N];
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        int dp[N];
        for (int i = 0; i < n; i++) {
            dp[i] = 1;
    }
        //memset(dp,1,sizeof(dp));以下是这一行代码测试用例的结果。
        //7 300 250 275 252 200 138 245
        //16843013
        //7 1 2 3 4 5 6 7 
        //16843009
        for(int i=0;i<n;i++){//有时候初始化还是这种稳妥的要更好。
            for(int j=0;j<i;j++){
                if(a[j]>=a[i])dp[i]=max(dp[i],dp[j]+1);
            }
        }
        int max=0;
        for(int i=0;i<n;i++){
            if(dp[i]>=max)max=dp[i];
        }
        cout<<max<<endl;
    }

    return 0;
}
//创建一个数组dp，其中dp[i]表示以第i个导弹为结尾的最长非升子序列的长度。
//初始化dp数组：所有dp[i]初始为1，因为每个导弹单独一个序列长度至少为1。
//对于每个导弹i，检查所有在它之前的导弹j，如果heights[j] >= heights[i]，则更新dp[i]：dp[i] = max(dp[i], dp[j] + 1)。
//最后，数组dp中的最大值就是最长非升子序列的长度。