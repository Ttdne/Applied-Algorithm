#include<bits/stdc++.h>
#define MAX 100000
#define ll long long
using namespace std;
int toSec(string time){
    int hour = stoi(time.substr(0,2));
    int minute = stoi(time.substr(3,2));
    int sec = stoi(time.substr(6, 2));
    return (hour*60 + minute)*60 + sec;
}
int main(){
    freopen("test.txt", "r", stdin);
    int sum=0;
    string order;
    string time;
    vector<int> sortedArray;
    vector<int> prefixsum (86402,0);
    while( (cin>>order) && (order != "#")){
        cin>>time;
        int time_to_sec = toSec(time);
        sum++;
        sortedArray.push_back(time_to_sec);
    }
    sort(sortedArray.begin(), sortedArray.end());

    for (int i = 0; i < sortedArray.size(); i++) {
        if (sortedArray[i] >= 0 && sortedArray[i] < 86400) {
            prefixsum[sortedArray[i]]++;
        }
    }

    for(int i=1 ;i< 86400; i++){
        prefixsum[i] += prefixsum[i-1];
    }
    string cmd;
    while((cin>>cmd) && (cmd != "###")){
        if(cmd == "?number_orders"){
            cout<<sum<<endl;
        }
        else if(cmd == "?number_orders_in_period"){
            string from_time, to_time;
            cin>>from_time>>to_time;
            int from_time_sec = toSec(from_time);
            int to_time_sec = toSec(to_time);
            cout<<(prefixsum[to_time_sec] - prefixsum[from_time_sec-1])<<endl;  // dm loi ngu vl de y nha quy
        }
        else if( cmd == "?number_orders_at_time"){
           string time;
           cin>>time;
           int time_sec = toSec(time);
           cout<<(prefixsum[time_sec] - prefixsum[time_sec - 1])<<endl;
        }

    }
}
