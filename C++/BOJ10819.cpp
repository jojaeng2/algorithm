#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int num[8] = {0,};
bool visit[8] ={false};
int result,n;
vector<int> v;

void dfs(int cnt){
    if(cnt==n){
        int dat = 0;
        for(int j=0;j<n-1;j++){
            dat += abs(v[j]-v[j+1]);
        }
        if(result<dat){
            result = dat;
        }
        return;
    }
    for(int i =0;i<n;i++){
        if(visit[i] == true){
            continue;
        }
        visit[i] = true;
        v.push_back(num[i]);
        dfs(cnt+1);
        visit[i] = false;
        v.pop_back();
    }
}
int main(){
    cin >> n;
    for(int i=0;i<n;i++)
        cin >> num[i];
    dfs(0);
    cout << result << '\n';
}