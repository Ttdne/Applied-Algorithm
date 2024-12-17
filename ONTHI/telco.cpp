#include<bits/stdc++.h>
using namespace std;
map<string, int> call;
map<string, int> duration;
int calDuration(string from, string to){
    int tu;
    int den;
    tu = (from[0]*10 + from[1])*3600 + (from[3]*10 + from[4])*60 + from[6]*10 + from[7];
    den = (to[0]*10 + to[1])*3600 + (to[3]*10 + to[4])*60 + to[6]*10 + to[7];
    return (den - tu);
}
bool checkPhone(string number){
    if(number.size() != 10) return false;
    for(int i=0; i<10; i++){
        if(!isdigit(number[i])) return false;
    }
    return true;
}
int main(){
    string c;
    string number1, number2;
    string day;
    string from_time;
    string to_time;
    int sum=0;
    int check=1;
    while(cin>>c){
        if(c == "#")    break;
        cin>>number1>>number2>>day>>from_time>>to_time;
        if((!checkPhone(number1)) || (!checkPhone(number2))){
            check = 0;
        }
        call[number1]++;
        duration[number1] += calDuration(from_time, to_time);
        sum++;
    }
    string query;
    while(cin>>query){
        if(query == "#")    break;
        if(query == "?check_phone_number")  cout<<check<<endl;
        else if(query == "?number_calls_from"){
            string phone;
            cin>>phone;
            cout<<call[phone]<<endl;
        }
        else if(query == "?number_total_calls") cout<<sum<<endl;
        else if(query == "?count_time_calls_from"){
            string phone;
            cin>>phone;
            cout<<duration[phone]<<endl;
        }
    }
}
