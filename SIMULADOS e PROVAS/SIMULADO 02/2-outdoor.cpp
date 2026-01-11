#include <bits/stdc++.h>
#define Kmax 100

int memo[Kmax];

using namespace std;

void init(){
    for(int k=0; k<Kmax; k++)
        memo[k] = -1;
}

int outdoor(int n, int M[], int R[]){
    init();
    memo[0] = R[0];
    for(int k=1; k<n; k++){
        memo[k] = memo[k-1];
        for(int j=k-1; j>=0; j--){
            if(M[k]-M[j] > 5){
                memo[k] = max(memo[k], memo[j] + R[k]);
                break;
            }
        }
    }

    return memo[n-1];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);


    int n;
    cin >> n;
    int M[n], R[n];
    for(int i=0; i<n; i++){
        cin >> M[i] >> R[i];
    }

    cout << outdoor(n, M, R) << "\n";

    return 0;
}
