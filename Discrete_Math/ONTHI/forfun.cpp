#include<bits/stdc++.h>
using namespace std;
map<string, int> dem;

int main(){
    set<string> ngay;
    string day;
    string time;
    string name;
    string ques;
    while(cin>> day){
        if(day == "*") break;
        cin>>time>>name>>ques;
        dem[day]++;
        ngay.insert(day);
    }
    for(auto day: ngay){
        cout<<day<<" "<<dem[day]<<endl;
    }
}
