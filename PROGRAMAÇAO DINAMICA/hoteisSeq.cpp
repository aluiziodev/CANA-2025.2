#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;

/*
Hotel Stops Problem
Given a sequence of distances of hotels along a route, find the sequence of hotel stops 
that minimizes the total penalty. The penalty for stopping at a hotel is defined as the square 
of the difference between 200 miles and the distance traveled since the last stop.

*/

vi hoteisSeq(int V[], int n, int k){
    vector<vi> seqHoteis(n);
    int memo[n];
    memo[0] = 0;
    seqHoteis[0]= {0};

    for(int i =1;i<n;i++){
        vi cam = seqHoteis[0];
        int min = memo[0]+pow(200-(V[i]-V[0]), 2);
        for(int j =1;j<i;j++){
            int custo = memo[j]+pow(200-(V[i]-V[j]), 2);
            if(custo<min){
                min = custo;
                cam = seqHoteis[j];
            }
        } 
        memo[i] = min;
        cam.push_back(i);
        seqHoteis[i] = cam;
    }
    return seqHoteis[k];
    
}

int main(){
    int V[] = {0, 150, 350, 480, 600};
    int n = 5;
    int k = 4;
    vi seqHoteis = hoteisSeq(V, n, k);
    cout << "Hoteis a parar: ";
    for(int i =0;i< (int)seqHoteis.size();i++){
        cout << seqHoteis[i] << " ";
    }
    cout << endl;
    return 0;
}