#include<bits/stdc++.h>
using namespace std;
int n;
int check = 0;
int ab[100];
void schedule(int sum, deque<int> a){
    if(a.empty()){
        check++;
        return;
    }
    if( sum + a.back() <=6){
        sum += a.back();
        a.pop_back();
        schedule(sum, a);
    }
    else{
        check++;
        int j = a.front();
        a.pop_front();
        schedule(j, a);
    }
}
// 4 3 3 2 2
int main(){
    deque<int> a;
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>ab[i];
    }
    sort(ab, ab+n);
    for(int i=0; i<n; i++)  a.push_front(ab[i]);
    int i = a.front();
    a.pop_front();
    schedule(i, a);
    cout<<check;
}

