#include<bits/stdc++.h>
#define MAX 40
using namespace std;
int A[MAX][MAX]={0};
int B[MAX][MAX]={0};
int n1, m1, n2, m2;
bool checkIsomorphism(vector<int> perm){
    for(int i=0; i<n1; i++){
        for(int j=0; j<n1; j++){
            if(A[perm[i]][perm[j]] != B[i][j])  return false;
        }
    }
    return true;
}

bool areIsomorphic(vector<int> perm){
    if(n1 != n2 || m1 != m2) return false;
    do{
        if(checkIsomorphism(perm)){
            return true;
        }
    } while (next_permutation(perm.begin(), perm.end()));
    return false;
}
int main(){
    cin>>n1>>m1;
    int a,b;
    for(int i=0; i<m1; i++){
        cin>>a>>b;
        a--; b--;
        A[a][b] = 1;
        A[b][a] = 1;
    }
    cin>>n2>>m2;
    for(int i=0; i<m2; i++){
        cin>>a>>b;
        a--; b--;
        B[a][b] = 1;
        B[b][a] = 1;
    }
    vector<int> perm(n1);
    for(int i=0; i<n1; i++){
        perm[i] = i;
    }
    if(areIsomorphic(perm)) cout<<1;
    else cout<<0;
}
