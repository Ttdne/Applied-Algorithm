#include<bits/stdc++.h>
#define MOD 1000000007
using namespace std;
unsigned long long a, b;
unsigned long long expMOD(unsigned long long a, unsigned long long b){
    if(b == 0){
        return 1;
    }
    if(b == 1){
        return a%MOD;
    }
    unsigned long long mid = b/2;
    unsigned long long halfExp = expMOD(a,mid);
    unsigned long long result = (halfExp * halfExp) % MOD;
    if(b % 2 == 1){
        result =  (result * a) % MOD;
    }
    return result;

}
int main(){
    cin>>a>>b;
    cout<<expMOD(a,b);
}
