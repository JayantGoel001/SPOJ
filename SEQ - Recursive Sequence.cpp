#include<iostream>
#include <valarray>
#define int long long int
using namespace std;
const int MOD = pow(10,9);
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
    return output;
}
int **power(int **TF,int n,int k){
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
        int n;
        cin>>n;
        if (n<=k){
            cout<<b[n-1]<<"\n";
        } else {
            int **TF = new int *[k];
            for (int i = 0; i < k; ++i) {
                TF[i] = new int[k];
            }
            int **F1 = new int *[k];
            for (int i = 0; i < k; ++i) {
                F1[i] = new int[1];
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
            for (int i = 0; i < k; ++i) {
                F1[i][0] = b[i] % MOD;
            }
            int **TFn = power(TF, n - 1, k);
            int **result = multiply(TFn, F1, k, 1);
            cout << result[0][0] % MOD << "\n";
        }
    }
}
