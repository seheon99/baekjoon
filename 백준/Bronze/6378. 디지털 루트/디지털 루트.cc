#include <string>
#include <iostream>
using namespace std;
int main(){
    while(1){
        string s;
        cin>>s;
        if(s=="0") break;
        int N=0;
        for(int i=0;i<s.size();i++){
            N+=s.at(i)-'0';
        }
        while(N>9){
            int N2=N;
            N=0;
            for(;N2!=0;N2/=10)
                N+=N2%10;
        }
        cout<<N<<"\n";
    }
}