#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vector<int>> Matriz;
typedef pair<int,int> pii;


int pontes(Matriz custo, int n){
    int memo[n+1][n+1];
    for(int i = 1; i<=n; i++) memo[i][0] = 1e9;
    for(int j = 0; j<=n; j++) memo[0][j] = 0;
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=n; j++){
            memo[i][j] = min(memo[i][j-1], memo[i-1][j-1] + custo[i-1][j-1]);
        }
    }
    return memo[n][n];
}

int main(){
    int n; cin >> n;
    Matriz custo(n, vi(n));
    for(int i =0;i<n;i++){
        for(int j =0;j<n;j++){
            cin >> custo[i][j];
        }
    }
    int res = pontes(custo, n);
    cout << "O custo minimo para construir as pontes eh " << res << endl;
    return 0;
}