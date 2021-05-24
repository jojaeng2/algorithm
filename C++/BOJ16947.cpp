#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
typedef pair<int,int> pii;
int n, start;
vector<int> graph[3001];
bool visit[3001] = {false}, flag = false;
bool vis[3001];

void bfs(int x) {
    queue<pii> q;
    q.push(make_pair(x, 0));
    memset(vis, false, sizeof(vis));
    vis[x] = true;
    while(!q.empty()) {
        int now = q.front().first, cnt = q.front().second;
        q.pop();
        if(visit[now]) {
            cout << cnt << " ";
            break;
        }
        for(int i=0; i<graph[now].size(); i++) {
            int next = graph[now][i];
            if(vis[next]) continue;
            vis[next] = true;
            q.push(make_pair(next, cnt+1));
        }
    }
}

void print() {
    for(int i=1; i<=n; i++) {
        if(visit[i]) cout << 0 << " ";
        else bfs(i);
    }
    cout << '\n';
}

void dfs(int now, int before) {
    for(int i=0; i<graph[now].size(); i++) {
        int next = graph[now][i];
        if(next == before) continue;
        if(visit[next] && next == start && before != 0) {
            flag = true;
            return;
        } 
        else if(visit[next]) continue;
        visit[next] = true;
        dfs(next, now);
        if(flag) return;
        visit[next] = false;
    }    
}

void init() {
    cin >> n;
    for(int i=0; i<n; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    for(int i=1; i<=n; i++) {
        start = i;
        visit[i] = true;
        dfs(i, 0);
        if(flag) break;
        visit[i] = false;
    }
}

int main() {
    init();
    print();
}