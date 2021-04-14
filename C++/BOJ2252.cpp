#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int n,m;
int visit[32001];
vector<int> graph[32001];
priority_queue<int> pq;
int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int a,b;
        cin >> a >> b;
        visit[b]++;
        graph[a].push_back(b);
    }
    for(int i=1;i<=n;i++){
        if(visit[i]==0) pq.push(-i);
    }
    while(!pq.empty()){
        int x = -pq.top();
        pq.pop();
        cout << x << " ";
        for(int i=0;i<graph[x].size();i++){
            int next = graph[x][i];
            visit[next]--;
            if(visit[next]==0) pq.push(-next);
        }
    }

}