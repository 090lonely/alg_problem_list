#include<iostream>
#include<string>
using namespace std;
int main(){//这段代码绝壁有问题meibanfa  ac
   int n;int count=0;
   cin>>n;
    cin.ignore(); //!!! 忽略之前cin留下的换行符  缓冲区问题
   string s;
   for(int i=0;i<n;i++){
     getline(cin,s);cin.ignore();
     int m=s.size();
     for(int j=0;j<m;j++){//!!!j
        if(s[i]>='0'&&s[i]<='9'){count++;}//s[i]>="0"&&s[i]<="9"
     }
      cout<<count<<endl;
   }
    return 0;
}