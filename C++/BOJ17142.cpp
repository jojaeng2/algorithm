#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>
#define X first
#define Y second
using namespace std;
typedef pair<int,int> pii;
int n,m,kk=0,result=987654321;
int graph[51][51], dx[4] = {-1,1,0,0}, dy[4] = {0,0,-1,1};
int visit[51][51];
queue<pii> q;
vector<pii> virus;
bool virus_visit[11];

void bfs(){
    for(int i=0;i<virus.size();i++){
        if(virus_visit[i]){
            visit[virus[i].X][virus[i].Y] = 0;
            q.push(make_pair(virus[i].X,virus[i].Y));
        } 
    }
    int p=0,time=0;
    while(!q.empty()){
        int x = q.front().X;
        int y = q.front().Y;
        q.pop();
        for(int i=0;i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(0<=nx && nx<n && 0<=ny && ny<n){
                if(graph[nx][ny]!=1 && visit[nx][ny]==-1){
                    visit[nx][ny] = visit[x][y]+1;
                    q.push(make_pair(nx,ny));
                    if(graph[nx][ny]==0){
                        p++;
                        time = visit[nx][ny];
                    }
                }
            }
        }
    }
    if(p==kk && result>time) result = time;
}

void dfs(int index,int cnt){
    if(cnt==m){
        memset(visit,-1,sizeof(visit));
        bfs();
        return;
    }
    for(int i=index;i<virus.size();i++){
        if(virus_visit[i]) continue;
        virus_visit[i] = true;
        dfs(i+1,cnt+1);
        virus_visit[i] = false;
    }
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> graph[i][j];
            if(graph[i][j]==2) virus.push_back(make_pair(i,j));
            if(graph[i][j]==0) kk++;
        }
    }
    dfs(0,0);
    if(result==987654321) result=-1;
    cout << result << endl;
}