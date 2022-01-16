#include <string>
#include <vector>
#include <cstring>
#include <iostream>
using namespace std;
bool visit[(1<<18)][20];
int answer = 0;
vector<int> adj[20];

void dfs(int sh, int wo, int curr, int psum, vector<int> infos) {
    answer = max(answer, sh);
    for(int next : adj[curr]) {
        if(visit[psum | (1<<next)][next]) continue;
        visit[psum|(1<<next)][next] = true;
        if(infos[next] == 1) {
            if((psum & (1<<next)) == 0) {
                if(sh > wo+1) dfs(sh, wo+1, next, psum | (1<<next), infos);
            }
            else dfs(sh, wo, next, psum | (1<<next), infos);            
        }
        else dfs(sh+((psum & (1<<next)) == 0 ? 1 : 0), wo, next, psum|(1<<next), infos);
    }
}

int solution(vector<int> info, vector<vector<int>> edges) {
    for(auto edge : edges) {
        int x = edge[0], y = edge[1];
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    memset(visit, false, sizeof(visit));
    visit[1][0] = true;
    dfs(1, 0, 0, 1, info);
    
    return answer;
}