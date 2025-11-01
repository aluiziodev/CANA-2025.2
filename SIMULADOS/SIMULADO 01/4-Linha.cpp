#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pi;
typedef vector<pi> vii;
typedef vector<int> vi;



void mergeSort(vii &V, int i, int f){
    if(i!=f){
        int meio = (i+f)/2;
        mergeSort(V, i, meio);
        mergeSort(V, meio+1, f);

        int n = f-i+1;
        vii A(n);
        int l = 0;
        int it = i;
        int j = meio+1;
        while(it<=meio || j<=f){
            if(it>meio){
                A[l] = V[j];
                j++;
            }
            else if(j>f){
                A[l] = V[it];
                it++;
            }
            else if(V[it].first>V[j].first){
                A[l] = V[j];
                j++;
            }
            else{
                A[l] = V[it];
                it++;
            }
            l++;
        }

        l = 0;
        it = i;
        while(it<=f){
            V[it] = A[l];
            it++; l++;
        }
    }
}

int mergeCountAux(vi V, int i, int f){
    if(i==f) return 0;
    else{
        int meio = (i+f)/2;
        int c1 = mergeCountAux(V, i, meio);
        int c2 = mergeCountAux(V, meio+1, f);

        int n = f-i+1;
        vi A(n);
        int l = 0;
        int it = i;
        int j = meio+1;
        int k = 0;
        while(it<=meio || j<=f){
            if(it>meio){
                A[l] = V[j];
                j++;
            }
            else if(j>f){
                A[l] = V[it];
                it++;
            }
            else if(V[it]>=V[j]){
                k += meio-it+1;
                A[l] = V[j];
                j++;
            }
            else{
                A[l] = V[it];
                it++;
            }
            l++;
        }

        l = 0;
        it = i;
        while(it<=f){
            V[it] = A[l];
            it++; l++;
        }
        return c1 + c2 + k;
    }
    

} // O(n log(n))


int mergeCount(vii &V, int n){
    mergeSort(V, 0, n-1); // O(n log(n))
    vi A;
    for(auto x : V){ // O(n)
        A.push_back(x.second);
    }
    return mergeCountAux(A, 0, n-1); // O(n log(n))
} 
// O(n log(n))



int main(){
    vii V = {{1,2},{2,5},{7,8}, {3,3},{5,5}, {9,12}, {8,14}};
    cout << mergeCount(V, 7) << endl;

}