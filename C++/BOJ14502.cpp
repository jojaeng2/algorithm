#include <iostream>
#include <queue>

using namespace std;

int graph[9][9];
int cgraph[9][9];
bool visit[9][9];
bool lab[9][9];
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};
int n,m;
int result = 0;
queue<pair<int,int> >q;
void copy(){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cgraph[i][j] = graph[i][j];
        }
    }
}

void bfs(){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            visit[i][j] = false;
        }
    }
    copy();
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(cgraph[i][j]==2){
                q.push(make_pair(i,j));
                visit[i][j] = true;
            } 
        }
    }
    
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int j=0;j<4;j++){
            int nx = x + dx[j];
            int ny = y + dy[j];
            if(0<=nx && nx<n && 0<=ny && ny<m){
                if(cgraph[nx][ny]==0 && visit[nx][ny]==false){
                    cgraph[nx][ny]=2;
                    visit[nx][ny]=true;
                    q.push(make_pair(nx,ny));
                }
            }
        }
    }
    int dat=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(cgraph[i][j]==0){
                dat +=1;
            }
        }
    }
    result = max(result,dat);
}

void dfs(int cnt){
    if(cnt == 3){
        bfs();
        return;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(graph[i][j]==0 && lab[i][j]==false){
                graph[i][j]=1;
                lab[i][j]=true;
                dfs(cnt+1);
                graph[i][j]=0;
                lab[i][j]=false;
            }
        }
    }
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> graph[i][j];
        }
    }
    dfs(0);
    
    cout << result << endl;
}