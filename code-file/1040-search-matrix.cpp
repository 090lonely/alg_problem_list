#include<bits/stdc++.h>
using namespace std;
//第一种做法：直接暴力搜索，因为复杂度只是O（mn），注意题目中mn的取值范围即可
  bool searchMatrix1(vector<vector<int>>& matrix, int target) {
        for (const auto& row: matrix) {
            for (int element: row) {
                if (element == target) {
                    return true;
                }
            }
        }
        return false;
    }
    //第二种方法：使用上确界函数，时间复杂度降低为O（mlogn）；
bool searchMatrix2(vector<vector<int>>& matrix, int target) {
           for (const auto& row: matrix) {
            auto it = lower_bound(row.begin(), row.end(), target);
            if (it != row.end() && *it == target) {
                return true;
            }
        }
        return false;
    }
int main(){
    int nums;cin >> nums;
    int m,n,target;
    while(nums--){
        cin>>m>>n>>target;
        vector<vector<int>> matrix(m+1,vector<int>(n+1));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                cin>>matrix[i][j];
            }
        }
        bool t=searchMatrix1(matrix,target);
        if(t){cout<<"true"<<endl;}
            else{cout<<"false"<<endl;}

    }



    return 0;
}