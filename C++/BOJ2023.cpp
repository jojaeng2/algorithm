#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <cmath>

using namespace std;
vector<int>v;
int n;

bool sosu(int num){
    for(int j=n;j>0;j--){
        int dat = num / (int)pow(10,j-1);
        if(dat==0 || dat==2 || dat==3 || dat==5 || dat==7){
            continue;
        }
        for(int i=2;i<sqrt(dat)+1;i++){
            if(dat%i == 0){
                return false;
            }
        }
    }
    return true;
}

void dfs(int cnt){
    if(cnt != 0){
        string s;
        for(int i=0;i<cnt;i++){
            s += to_string(v[i]);
        }
        int checknum = stoi(s);
        if(!sosu(checknum)){
            return;
        }
    }
    if(cnt == n){
        string s;
        for(int i=0;i<cnt;i++){
            s += to_string(v[i]);
        }
        cout << s << '\n';
        return;
    }
    for(int i=1;i<10;i++){
        if(cnt == 0){
            if(i==1 || i==4 || i==6 || i==8 || i==9){
                continue;
            }
        }
        v.push_back(i);
        dfs(cnt+1);
        v.pop_back();
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    dfs(0);
}