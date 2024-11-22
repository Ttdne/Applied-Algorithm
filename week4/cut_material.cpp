#include<bits/stdc++.h>
using namespace std;
int H, W;
int n;
vector<pair<int, int>> rectangles;
bool used[10][10] = {false};
bool canPlace(int x, int y, int h, int w){
    if(x + h >H || y + w > W){
        return false;
    }
    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++){
            if(used[x+i][y+j]) return false;
        }
    }
    return true;
}

void placeRectangle(int x, int y, int h, int w, bool true_false){
    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++){
            used[x+i][y+j] = true_false;
        }
    }
}
bool Try(int k){
    if (k == n) return true;
    int h = rectangles[k].first;
    int w = rectangles[k].second;

    for(int x=0; x<H; x++){
        for(int y=0; y<W; y++){
            if(canPlace(x,y,h,w)){
                placeRectangle(x,y,h,w,true);
                if(Try(k+1)) return true;
                placeRectangle(x,y,h,w,false);
            }
            if(canPlace(x,y,w,h)){
                placeRectangle(x,y,w,h,true);
                if(Try(k+1)) return true;
                placeRectangle(x,y,w,h,false);
            }
        }
    }
    return false;
}
int main(){
    cin>>H>>W>>n;
    for(int i=0; i<n; i++){
        int a,b;
        cin>>a>>b;
        pair<int, int> c = {a,b};
        rectangles.push_back(c);
    }
    if(Try(0)) cout<<1<<endl;
    else cout<<0<<endl;
}
