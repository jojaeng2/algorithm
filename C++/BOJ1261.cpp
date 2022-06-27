#include <iostream>
#include <queue>
#include <string>

#define INF 987654321

using namespace std;
typedef pair<int,int> pii;

int n,m;
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};
int graph[101][101];
int visit[101][101];
int result = 0;

void bfs(){
    queue<pii>q;
    visit[1][1]=0;
    q.push(make_pair(1,1));
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(1 <= nx && nx <= n && 1<= ny && ny <= m){
                if(graph[nx][ny]==0 && visit[nx][ny]>visit[x][y]){
                    visit[nx][ny]= visit[x][y];
                    q.push(make_pair(nx,ny));
                }
                else if(graph[nx][ny]==1 && visit[nx][ny]>visit[x][y]+1){
                    visit[nx][ny] = visit[x][y]+1;
                    q.push(make_pair(nx,ny));
                }
            }
        }
    }
    
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> m >> n;
    for(int i=1;i<=n;i++){
        string s;
        cin >> s;
        for(int j=1;j<=m;j++){
            graph[i][j] = s[j-1]-'0';
            visit[i][j] = INF;   
        }
    }
    
    bfs();
    int result = visit[n][m];
    cout << result << endl;
}