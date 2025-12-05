#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;


int hastes(int P[], int n){
    int memo[n+1];
    memo[0] = 0;
    for(int i = 1;i<=n;i++){
        memo[i]  = 0;
        for(int j = 1; j<=i; j++){
            memo[i] = max(memo[i-j]+P[j], memo[i]);
        }
    }
    return memo[n];
}

int main(){
    int n;
    cin >> n;
    int P[n+1];
    P[0] = 0;
    for(int i =1;i<=n;i++) cin >> P[i];
    cout << "Preço Max: " << hastes(P,n) << "\n";
    return 0;
}

