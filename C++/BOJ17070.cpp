#include <iostream>
#include <queue>
#define X first
#define Y second
using namespace std;
typedef pair<pair<int,int>,int> pii;
int n;
int dx[3] = {0,1,1};
int dy[3] = {1,0,1};
int graph[17][17];
int cnt[17][17];

void bfs(){
    queue<pii> q;
    q.push({{1,2},0});
    while(!q.empty()){
        int x = q.front().X.X;
        int y = q.front().X.Y;
        int before = q.front().Y;
        q.pop();

        for(int i=0;i<3;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(1<=nx && nx <=n && 1<=ny && ny<=n){
                if(graph[nx][ny]==1) continue;
                if(before==0 && i==1) continue;
                if(before==1 && i==0) continue;
                if(i==2){
                    if(graph[nx-1][ny]==1 || graph[nx][ny-1]==1) continue;
                }
                cnt[nx][ny] += 1;
                q.push({{nx,ny},i});
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin >> graph[i][j];
        }
    }
    bfs();
    
    cout << cnt[n][n] << endl;
}