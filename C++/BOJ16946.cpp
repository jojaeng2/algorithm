#include <iostream>
#include <queue>
#include <string>
#include <set>
#define X first
#define Y second
using namespace std;
typedef pair<int,int> pii;
int graph[1001][1001], visit[1001][1001], dx[4]={-1,1,0,0}, dy[4]={0,0,-1,1};
int divide[1000001];
int n,m,number=0;

void bfs(int a,int b,int num){
    queue<pii>q;
    int cnt = 1;
    q.push(make_pair(a,b));
    visit[a][b]=num;
    while(!q.empty()){
        int x = q.front().X;
        int y = q.front().Y;
        q.pop();
        for(int i=0;i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(0<=nx && nx<n && 0<=ny && ny<m){
                if(graph[nx][ny]==0 && visit[nx][ny]==0){
                    visit[nx][ny] = num;
                    cnt += 1;
                    q.push(make_pair(nx,ny));
                }
            }
        }
    }
    divide[num] = cnt;
}

void find(int x,int y){
    graph[x][y] = 1;
    set<int> s;
    s.clear();
    for(int i=0;i<4;i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(0<=nx && nx<n && 0<=ny && ny<m){        
            if(graph[nx][ny]==0 && s.find(visit[nx][ny])==s.end()){
                graph[x][y] += divide[visit[nx][ny]];
                s.insert(visit[nx][ny]);
            }
        }
    }
    graph[x][y] %= 10;
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    for(int i=0;i<n;i++){
        string s;
        cin >> s;
        for(int j=0;j<m;j++){
            graph[i][j] = (int)s[j]-'0';
        }
    }
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(graph[i][j]==0 && visit[i][j]==0){
                number++;
                bfs(i,j,number);
            }
        }
    }
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(graph[i][j]==1){
                find(i,j);
            }
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout << graph[i][j];
        }
        cout << '\n';
    }
}