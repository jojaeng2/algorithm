#include <bits/stdc++.h>
#define MINF 0x7f7f7f7f
#define INF 1000000000
#define MOD 10000
#define NUM 200010
#define X first
#define Y second
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
typedef pair<ll, ll> pll;
int N, in[1010];
char graph[1010];
bool visited[510][1010];
vector<int> adj[1010];
queue<pii> Q;
void init() {
    while(true) {
        memset(visited, false, sizeof(visited));
        cin >> N;
        if(!N) break;
        for(int i=1; i<=N; i++) {
            cin >> graph[i] >> in[i];
            while(true) {
                int z;
                cin >> z;
                if(!z) break;
                adj[i].push_back(z);
            }
        }
        adj[0].push_back(1);
        Q.push(pii(0, 0));
        while(!Q.empty()) {
            auto curr = Q.front();
            Q.pop();
            for(auto next : adj[curr.X]) {
                if(graph[next] == 'E') {
                    if(visited[curr.Y][next]) continue;
                    visited[curr.Y][next] = true;
                    Q.push(pii(next, curr.Y));
                }
                if(graph[next] == 'L') {
                    int maxi = max(curr.Y, in[next]);
                    if(visited[maxi][next]) continue;
                    visited[maxi][next] = true;
                    Q.push(pii(next, maxi));
                }
                if(graph[next] == 'T') {
                    if(in[next] > curr.Y || visited[curr.Y - in[next]][next]) continue;
                    visited[curr.Y - in[next]][next] = true;
                    Q.push(pii(next, curr.Y - in[next]));
                }
            }
        }


        bool flag = false;
        for(int i=0; i<510; i++) if(visited[i][N]) flag = true;
        if(flag) cout << "Yes" << '\n';
        else cout << "No" << '\n';
        for(int i=1; i<=N; i++) adj[i].clear();

    }
}


int main() {    
    ios_base :: sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
   init();
}