#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

#define int long long int
#define double double_t
#define INF 1e18
using namespace __gnu_pbds;
using namespace std;
template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int mod = 1e9 + 7;

int GCD(int a, int b) {
    return b == 0 ? a : GCD(b, a % b);
}

int power(int x, int y, int MOD=mod) {
    if (y == 0) {
        return 1;
    }
    if (y % 2 == 0) {
        return power((x * x) % MOD, y / 2, MOD) % MOD;
    } else {
        return (x * power((x * x) % MOD, (y - 1) / 2, MOD) % MOD) % MOD;
    }
}
const int TOT = 200001;
int _148721 = 148721;
int fact148721[TOT];
void calculateFactorial148721(){
    fact148721[0] = 1;
    for (int i = 1; i <TOT; ++i) {
        fact148721[i] = (i * fact148721[i-1])%_148721;
    }
}
int _2 = 2;
int _41 = 41;
int _1681 = _41 * _41;
int fact1681[TOT];
int fact1681_p[TOT];
void calculateFactorial1681(){
    fact1681[0] = 1;
    fact1681_p[0]=0;
    for (int i = 1; i <TOT ; ++i) {
        fact1681_p[i] = fact1681_p[i-1];
        int y = i;
        while (y%41==0){
            fact1681_p[i]++;
            y/=41;
        }
        fact1681[i] = (y * fact1681[i-1])% _1681;
    }
}
int inverse(int n,int p){
    return power(n,p-2,p);
}
int inverse2(int n,int p){
    int i = 1;
    while (true){
        if ((n*i)%p==1){
            return i;
        }
        i++;
    }
}
int CRT(int rem1,int rem2,int rem3){
    int prod = _2 * _1681 * _148721;
    int num1 = prod/_2;
    int num2 = prod/_1681;
    int num3 = prod/_148721;

    return ((rem1 * num1 * inverse(num1,_2))%prod + (rem2 * num2 * inverse2(num2,_1681))%prod + (rem3 * num3 * inverse(num3,_148721))%prod)%prod;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t = 1;
    calculateFactorial148721();
    calculateFactorial1681();
    cin >> t;
    while (t--) {
        int a,b,n;
        cin >> a>>b>>n;
        if (b==0){
            cout<<"1";
        } else{
            int rem1 = !n;
            int rem2 = (((fact1681[2*n] * power(inverse2(fact1681[n],_1681),2,_1681))%_1681) * power(_41,fact1681_p[2*n] - 2*fact1681_p[n],_1681))%_1681;
            int rem3 = (fact148721[2*n] * power(inverse(fact148721[n],_148721),2,_148721))%_148721;
            int _2nCn = CRT(rem1,rem2,rem3);
            if (_2nCn == 0){
                _2nCn = _2 * _1681 * _148721;
            }
            int y = power(b,_2nCn,mod-1);
            int output = power(a,y);
            cout<<output;
        }
        cout << "\n";
    }
}