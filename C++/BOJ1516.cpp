#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int n,visit[501],dp[501];
vector<int> graph[501],connect[501];
queue<int> q;

void topological(){
    while(!q.empty()){
        int x = q.front();
        q.pop();
        for(int i=0;i<graph[x].size();i++){
            int next = graph[x][i];
            visit[next]--;
            if(visit[next]==0){
                int ans = 0;
                for(int j=0;j<connect[next].size();j++){
                    ans = max(ans,dp[connect[next][j]]);
                }
                dp[next] = ans + dp[next];
                q.push(next);
            }
        }
    }
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for(int i=1;i<=n;i++){
        int a;
        cin >> a;
        dp[i] = a;
        while(true){
            int b;
            cin >> b;
            if(b==-1) break;
            visit[i]++;
            graph[b].push_back(i);
            connect[i].push_back(b);
        }
    }
    for(int i=1;i<=n;i++){
        if(visit[i]==0) q.push(i);
    }
    topological();
    for(int i=1;i<=n;i++) cout << dp[i] << '\n';
}