#include<bits/stdc++.h>//为什么一直是answer wrong 淦
using namespace std;
int N,K;//n is the number ,k is the number of *
long long res=0;//the result use long long to store
int a[21]={0};//at most number//what i change this ,and this is correct
long long dp[21][21]={0};//dp is for the first i element ,charu k ge *de jieguo .
int sum(int start,int end){
    int s=0;
    for(int i=start;i<=end;i++){
        s+=a[i];
    }
    return s;
}//求和
int main(){
    int m=0;cin>>m;
    while(m--){
        cin>>N>>K;
        for(int i=1;i<=N;i++)a[i]=0;
        for(int i=1;i<=N;i++){//the first is i=1;
            cin>>a[i];
        }
        for(int i=1;i<=N;i++){//wrong easily
            dp[i][0]=sum(1,i);
        }//without * then there is all sum;
        //the key part;
        for(int i=2;i<=N;i++){//i个数只能插入i-1个乘号。
            for(int j=1;j<=min(i-1,K);j++)//开始插入乘号，从插入一个乘号开始遍历，称号的个数不能大于i-1
                for(int k=2;k<=i;k++)//从1到i-1和从2到i的个数是相同的都是i-1；
                dp[i][j]=max(dp[i][j],dp[k-1][j-1]*sum(k,i));//其实就是在遍历所有乘号可以插入的位置
        }
      //  res=dp[N][K];
        cout<<dp[N][K]<<endl;
      // cout<<res<<endl;
    }
    return 0;
}