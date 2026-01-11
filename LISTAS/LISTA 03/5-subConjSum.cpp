#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;

int subConjSum(vi &V, int n, int S){
    bool memo[S+1][n+1];
    for(int i = 0; i<=n; i++) memo[0][i] = true;
    for(int j = 1; j<=S; j++) memo[j][0] = false;
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=S; j++){
            if(V[i-1] <= j){
                memo[j][i] = memo[j][i-1] || memo[j - V[i-1]][i-1];
            } else {
                memo[j][i] = memo[j][i-1];
            }
        }
    }
    return memo[S][n];
}

int main(){
    int n, S; cin >> n >> S;
    vi V(n);
    for(int i =0;i<n;i++) cin >> V[i];
    bool res = subConjSum(V, n, S);
    if(res) cout << "Existe um subconjunto com soma igual a " << S << endl;
    else cout << "Nao existe um subconjunto com soma igual a " << S << endl;
    return 0;
}