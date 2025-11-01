#include <bits/stdc++.h>

using namespace std;


int buscaQuartenaria(int V[], int i, int f, int k){
    if(i>f) return -1;
    else{
        int meio = (i+f)/2;
        int q1 = (meio+i)/2;
        int q3 = (meio+f)/2;
        if(V[meio]==k) return meio;
        else if(V[q1]==k) return q1;
        else if(V[q3]==k) return q3;
        else{
            if(V[i]<=k<V[q1]) return buscaQuartenaria(V, i, q1-1, k);
            else if(V[q1]<k<V[meio]) return buscaQuartenaria(V, q1+1, meio-1, k);
            else if(V[meio]<k<V[q3]) return buscaQuartenaria(V,meio+1, q3-1, k);
            else return buscaQuartenaria(V, q3+1, f, k);
        }
    }
}


int main(){
    int V[] = {7, 6, 2, 4, 1};
    cout << buscaQuartenaria(V, 0, 4, 7) << endl;

}
