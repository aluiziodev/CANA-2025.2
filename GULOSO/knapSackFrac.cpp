#include <bits/stdc++.h>
using namespace std;
typedef long long int int64;
typedef vector<int> vi;


/* Fractional Knapsack Problem
Given weights and values of n items, put these items in a knapsack of capacity W
to get the maximum total value in the knapsack. In this problem,
we can break items for maximizing the total value of knapsack.
*/

vi pesos;
vi valor;

double knapSackFrac(int W, int n) {
    vector<pair<double, int>> densidade; 
    for (int i = 0; i < n; i++) {
        double r = valor[i] / pesos[i];
        densidade.push_back({r, i});
    }
    sort(densidade.rbegin(), densidade.rend()); 

    double totalValue = 0;
    for (int i = 0; i < n; i++) {
        if (W == 0) break;
        int idx = densidade[i].second;
        if (pesos[idx] <= W) {
            W -= pesos[idx];
            totalValue += valor[idx];
        } else {
            totalValue += densidade[i].first * W; 
            W = 0;
        }
    }
    return totalValue;
}

int main() {
    int n; cin >> n;
    int aux, aux2;
    pesos.assign(n, 0); valor.assign(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> aux >> aux2;
        pesos[i] = aux;
        valor[i] = aux2;
    }
    int W; cin >> W;
    cout << knapSackFrac(W, n) << endl;
}  

