#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;


int maxSubStr(string S, string L, int m, int n){
    int memo[m+1][n+1];
    for(int i = 0; i<=m; i++) memo[i][0] = 0;
    for(int j = 0; j<=n; j++) memo[0][j] = 0;
    int max = 0;
    for(int i = 1; i<=m; i++){
        for(int j = 1; j<=n; j++){
            if(S[i-1] == L[j-1]){
                memo[i][j] = memo[i-1][j-1] + 1;
                if(memo[i][j] > max) max = memo[i][j];
            } else {
                memo[i][j] = 0;
            }
        }
    }
    return max;
}

int main(){
    string S, L;
    cin >> S >> L;
    int m = (int) S.size();
    int n = (int) L.size();
    int res = maxSubStr(S, L, m, n);
    cout << "O tamanho da maior subsequencia comum eh " << res << endl;
    return 0;
}
