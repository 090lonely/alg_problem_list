//created by yangjinbo
//2024.5.17
//黑白连线问题，需要用贪心，其中一个思路是维护两个栈。
//main idea;
//（1）维护一个黑点栈和白点栈；
//（2）按顺序遍历每一个点，如果遇到一个白点，就查看当前黑点栈是否为空，非空的话就将将该白点与黑点栈顶黑点连接（因为栈是先入先出，所以栈顶黑点就是离该白点最近的未连接的黑点）；遇到黑点也做类似的操作。
//这个思路时间复杂度较低、空间复杂度较高。
#include<bits/stdc++.h>
using namespace std;
int main(){
    int m=0;cin>>m;
    while(m--){
        //保证正常输入
        int n;
        cin>>n;
        //创建点数组存储
        int *points=new int[2*n];
        for(int i=0;i<2*n;i++){
            cin>>points[i];
        }
        //维护两个栈
        stack<int> whitePoints;
        stack<int> blackPoints;
        //define a variable to report the answer
        int result=0;
        //key part;
        for(int pi=0;pi<2*n;pi++){
            if(points[pi]==0){//if the point is white;
                if(blackPoints.empty())
                 whitePoints.push(pi);
                 else{
                    result+=(pi-blackPoints.top());
                    blackPoints.pop();
                 }
            }
            else{
                if(whitePoints.empty()){
                    blackPoints.push(pi);
                }
                else{
                    result+=(pi-whitePoints.top());
                    whitePoints.pop();
                }
            }
        }
        cout<<result<<endl;
    }
    return 0;
}