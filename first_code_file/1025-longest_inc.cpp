// #include<bits/stdc++.h>
// #include<algorithm>
// using namespace std;
// const int N=10005;
// int a[N];
 // int lengthOfLIS(vector<int>& nums) {
        //     int len = nums.size();
        // if (len < 2) {
        //     return len;
        // }
        // vector<int> tail;
        // tail.push_back(nums[0]);
        // // tail 结尾的那个索引
        // int end = 0;

        // for (int i = 1; i < len; ++i) {
        //     if (nums[i] > tail[end]) {
        //         tail.push_back(nums[i]);
        //         end++;
        //     } else {
        //         int left = 0;
        //         int right = end;
        //         while (left < right) {
        //             int mid = (left + right) >> 1;
        //             if (tail[mid] < nums[i]) {
        //                 left = mid + 1;
        //             } else {
        //                 right = mid;
        //             }
        //         }
        //         tail[left] = nums[i];
        //     }
        // }
        // return end + 1;
   // }
// int main(){
//    int m=0;cin>>m;int n;
// //    while(m--){
// //      cin>>n;vector<int> a(n+1);int temp;
// //      for(int i=0;i<n;i++){
// //        cin>>temp;
// //        a.push_back(temp);
// //      }
// //     int res=lengthOfLIS(a);
//  //   cout<<res<<endl;
//  //  }
//    while(m--){
//      int n=0;cin>>n;
//      for(int i=0;i<n;i++){
//         cin>>a[i];
//      }
//      vector<int> dp(n,0);
//     if(n==0)cout<<0<<endl;//一眼看到问题，判断条件写错了，n=0和n==0
//     else{
//         for(int i=0;i<n;i++){
//             dp[i]=1;
//             for(int j=0;j<i;j++){
//                 if(a[j]<=a[i])dp[i]=max(dp[i],dp[j]+1);
//             }
//         }
//         int res=*max_element(dp.begin(),dp.end());
//         cout<<res<<endl;  
//     }
//    }
//     return 0;
//   // return 0;
// }

#include<bits/stdc++.h>
using namespace std;
 
int a[40005];
int d[40005];
 
int main()
{
    int m=0;cin>>m;
    while(m--){
    int n;
    scanf("%d",&n);
    for (int i=1;i<=n;i++) scanf("%d",&a[i]);
    if (n==0)  //0个元素特判一下 
    {
        printf("0\n");
        return 0;
    }
    d[1]=a[1];  //初始化 
    int len=1;
    for (int i=2;i<=n;i++)
    {
        if (a[i]>=d[len]) d[++len]=a[i];  //如果可以接在len后面就接上 
        else  //否则就找一个最该替换的替换掉 
        {
            int j=upper_bound(d+1,d+len+1,a[i])-d;  //找到第一个大于它的d的下标 
            d[j]=a[i]; //upeer_bound使用二分的方法查找的，所以复杂度是nlogn
        }
    }
    printf("%d\n",len);    
    }
    
}

//    while(m--){
//      int n=0;cin>>n;
//      for(int i=0;i<n;i++){
//         cin>>a[i];
//      }
//      vector<int> dp(n,0);
//     if(n==0)cout<<0<<endl;//一眼看到问题，判断条件写错了，n=0和n==0
//     else{
//         for(int i=0;i<n;i++){
//             dp[i]=1;
//             for(int j=0;j<i;j++){
//                 if(a[j]<=a[i])dp[i]=max(dp[i],dp[j]+1);
//             }
//         }
//         int res=*max_element(dp.begin(),dp.end());
//         cout<<res<<endl;  
//     }
//    }
//     return 0;