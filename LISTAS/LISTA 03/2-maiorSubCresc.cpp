#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;

pii maiorSubCresc(vi &V){
    int n = (int) V.size();
    vi memo(n, 1);
    int max = 0;
    for(int i = 1; i<n;i++){
        if(V[i]>V[i-1]){
            memo[i] = memo[i-1] +1;
            if(memo[i]>memo[max]) max = i;
        }
    }
    return {max-memo[max]+1, max};
}


int main(){
    int n; cin >> n;
    vi V(n);
    for(int i =0;i<n;i++) cin >> V[i];
    pii res = maiorSubCresc(V);
    cout << "O maior subvetor crescente inicia em " << res.first << " e termina em " << res.second << endl;
    return 0;
}