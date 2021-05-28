#include <iostream>
using namespace std;
int calculateSum(int x){
    return (x*(x+1)*(2*x+1))/6;
}
int main(){
    int a,b;
    cin>>a>>b;
    cout<<calculateSum(b) - calculateSum(a-1)<<"\n";
}
