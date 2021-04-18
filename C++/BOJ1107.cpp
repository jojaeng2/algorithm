#include <iostream>
#include <vector>
#include <string>
using namespace std;
int n,m,result;
bool visit[10];
vector<int> v;

void count(int cnt){
    string s;
    for(int i=0;i<cnt;i++){
        s += to_string(v[i]);
    }
    int num = stoi(s);
    result = min(result,cnt+abs(num-n));
}

void dfs(int cnt){
    if(cnt>0){
        count(cnt);
    }
    if(cnt==6) return;
    for(int i=0;i<10;i++){
        if(visit[i]) continue;
        if(cnt==0 && i==0) continue;
        v.push_back(i);
        dfs(cnt+1);
        v.pop_back();
    }
}

int main(){
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int a;
        cin >> a;
        visit[a] = true;
    }
    if(!visit[0]){
        result = min(n+1,abs(n-100));
    } else {
        result = abs(n-100);
    }
    dfs(0);
    cout << result << endl;
}