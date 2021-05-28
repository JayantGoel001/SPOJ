#include<iostream>
#include <valarray>
#define int unsigned long long int
using namespace std;
int MOD = pow(10,9);
int ar[16];
int **multiply(int **A,int **B,int n,int m){
    int **output = new int*[n];
    for (int i = 0; i < n; ++i) {
        output[i] = new int[n];
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            output[i][j] = 0;
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            for (int k = 0; k < n; ++k) {
                output[i][j] = (output[i][j] + A[i][k]%MOD *B[k][j]%MOD)%MOD;
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        ar[i] += output[0][i];
    }
    return output;
}
int **power(int **TF,int n,int k){
    if (n==0){
        int **I = new int*[k];
        for (int i = 0; i < k; ++i) {
            I[i] =new int [k];
        }
        for (int i = 0; i < k; ++i) {
            for (int j = 0; j < k; ++j) {
                if (i==j){
                    I[i][j] = 1;
                } else{
                    I[i][j] = 0;
                }
            }
        }
        return I;
    }
    if (n==1){
        return TF;
    }
    if (n%2==0){
        return power(multiply(TF,TF,k,k),n/2,k);
    } else{
        return multiply(TF,power(multiply(TF,TF,k,k),(n-1)/2,k),k,k);
    }

}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while (t--){
        int k;
        cin>>k;
        int b[k],c[k];
        for (int i = 0; i < k; ++i) {
            cin>>b[i];
        }
        for (int i = 0; i < k; ++i) {
            cin>>c[i];
        }
        int m,n;
        cin>>m>>n>>MOD;
        int **TF = new int *[k];
        for (int i = 0; i < k; ++i) {
            TF[i] = new int[k];
        }
        for (int i = 0; i < k; ++i) {
            for (int j = 0; j < k; ++j) {
                if (i + 1 == j && i != k - 1) {
                    TF[i][j] = 1;
                } else if (i == k - 1) {
                    TF[i][j] = c[k - j - 1] % MOD;
                } else {
                    TF[i][j] = 0;
                }
            }
        }
        int arM[k];
        int **TFm = power(TF, m - 2, k);
        for (int i = 0; i < k; ++i) {
            arM[i] = ar[i];
        }
        int **TFn = power(TF,n - 1,k);
        int output = 0;
        for (int i = 0; i < k; ++i) {
            cout<<arM[i]<<" "<<ar[i]<<"\n";
            output = (output + ((ar[i] - arM[i])%MOD) * b[i])%MOD;
        }
        cout <<output%MOD<< "\n";
    }
}
