#include <iostream>
#include <vector>
#define X first
#define Y second
using namespace std;
typedef pair<int,int> pii;
int n,m,result=0;
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};
int graph[501][501];
bool visit[501][501];
vector<pii> v;

void dfs(int x,int y,int cnt){
    if(cnt==4){
        int ans = 0;
        for(int i=0;i<4;i++){
            int xx = v[i].X;
            int yy = v[i].Y;
            ans += graph[xx][yy];
        }
        result = max(result,ans);
        return;
    }
    for(int i=0;i<4;i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(0<=nx && nx<n && 0<=ny && ny<m){
            if(visit[nx][ny]) continue;
            if(cnt>0){
                int bx = v.front().X;
                if(nx>bx) continue;
            }
            visit[nx][ny] = true;
            v.push_back(make_pair(nx,ny));
            dfs(nx, ny, cnt+1);
            visit[nx][ny] = false;
            v.pop_back();
        }
    }
    return;
}

void dfs2(int x,int y,int cnt){
    if(cnt==3){
        int ans = 0;
        for(int i=0;i<3;i++){
            int ax = v[i].X;
            int ay = v[i].Y;
            ans += graph[ax][ay];
        }
        for(int i=0;i<4;i++){
            int xx = v[1].X + dx[i];
            int yy = v[1].Y + dy[i];
            if(0<=xx && xx<n && 0<=yy && yy<m){
                if(visit[xx][yy]) continue;
                else{
                    result = max(result,ans+graph[xx][yy]);
                }
            }
        }
        return;
    }
    for(int i=0;i<4;i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(0<=nx && nx<n && 0<=ny && ny<m){
            if(visit[nx][ny]) continue;
            if(cnt==1 || (cnt==2 && (nx==v[0].X && nx==v[1].X) || (ny==v[0].Y && ny==v[1].Y))){
                visit[nx][ny] = true;
                v.push_back(make_pair(nx,ny));
                dfs(nx, ny, cnt+1);
                visit[nx][ny] = false;
                v.pop_back();
            }
            else continue;
        }
    }
    return;
}

int main(){
    cin >> n >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> graph[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            v.push_back(make_pair(i,j));
            visit[i][j] = true;
            dfs(i,j,1);
            visit[i][j] = false;
            v.pop_back();
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            v.push_back(make_pair(i,j));
            visit[i][j] = true;
            dfs2(i,j,1);
            visit[i][j] = false;
            v.pop_back();
        }
    }
    cout << result << endl;
}