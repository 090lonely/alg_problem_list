#include<bits/stdc++.h>
using namespace std;
const int N=505;//***i think its a good habit to write code annotation in english***
int max_val=0;
int s[N],v[N];//s is the weight of each gem,v is the value of gem; 
bool item[N];
int now=0;//now is for record of the current weight of the bag;
int main(){
    int m=0;cin>>m;int n,c;//n is number of the gem,c is capacity of the backpack; 
    while(m--){
        cin>>n>>c;
        for(int i=0;i<n;i++){
            cin>>s[i]>>v[i];
        }
         vector<vector<int>> dp(n + 1, vector<int>(c + 1, 0)); // 定义状态
         for(int i=1;i<=n;i++)
           for(int j=1;j<=c;j++)
                if(j<s[i-1])dp[i][j]=dp[i-1][j];//the condition should be j<s[j-1] unless you forget the s[0];
                else{
                    dp[i][j]=max(dp[i-1][j],dp[i-1][j-s[i-1]]+v[i-1]);
                    //if(dp[i-1][j]<dp[i-1][j-s[i-1]]+v[i-1]){item[i-1]=true;}
                    //this way is wrong
                  //  if(dp[i-1][j]<dp[i-1][j-s[i-1]]+v[i-1])now+=s[i-1];
                    }
            //max version:if the capacity os not full,then we shoule output 0;
            // for(int i=0;i<n;i++){
            //     if(item[i]==true)now+=s[i];//if the i item is in the bag,we add its value to now;
            // }
         // if(now!=c)max_val=0;//the changed line
        max_val=dp[n][c];
        cout<<max_val<<endl;
    }
    return 0;
}