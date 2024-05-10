#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main(){
   int m=0;
   cin>>m;
   while(m--){
    int n;int x;//数组个数和待查找元素
    cin>>n>>x;vector<int> v;int temp;
    for(int i=0;i<n;i++){
       cin>>temp;v.push_back(temp);
    }
    int l=0;int r=v.size()-1;int pre_mid=0;int mid=0;
   // int father=0;
    //bool ret=binarysearch(x,v,father);
		while(l <= r) {//mid是当前节点索引
			pre_mid = mid;    //记录父节点索引
			mid = l + (r - l)/2;
			if(v[mid]==x) {
				break;//这里忘记break会一直循环
			} else if(v[mid] > x) {
				r = mid - 1;
			} else {
				l = mid +1;
			}

		}
		if(v[mid] == x) cout<<"success, father is "<<v[pre_mid]<<endl;
		else cout<<"not found, father is "<<v[mid]<<endl;
   }
    return 0;
}