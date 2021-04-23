#include <iostream>
#include <vector>
#include <queue>
#define F first
#define S second
using namespace std;
typedef pair<int,int> pii;
int n,m,k,t=0;
int sea[21][21];
int smell[21][21][2];
int dx[5] = {0,-1,1,0,0};
int dy[5] = {0,0,0,-1,1};
int direc[401][5][5];
int shark[401][3];

void find(){
    queue<pii>q;
    while(t<=1000){
        int cnt = 0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(sea[i][j]!=0) cnt++;
            }
        }
        if(cnt==1) break;
        t++;

        for(int i=1;i<=m;i++){
            bool move=false;
            int x = shark[i][0];
            int y = shark[i][1];
            int gaze = shark[i][2];
            if(x==0 || y==0) continue;
            for(int j=1;j<=4;j++){
                int nx = x + dx[direc[i][gaze][j]];
                int ny = y + dy[direc[i][gaze][j]];
                if(1<=nx && nx<=n && 1<=ny && ny<=n){
                    if(smell[nx][ny][0]==0){
                        shark[i][2] = direc[i][gaze][j];
                        q.push(make_pair(i,direc[i][gaze][j]));
                        move = true;
                        break;
                    }
                }
            }
            if(!move){
                for(int j=1;j<=4;j++){
                    int nx = x + dx[direc[i][gaze][j]];
                    int ny = y + dy[direc[i][gaze][j]];
                    if(1<=nx && nx<=n && 1<=ny && ny<=n){
                        if(smell[nx][ny][1]==i){
                            shark[i][2] = direc[i][gaze][j];
                            q.push(make_pair(i,direc[i][gaze][j]));
                            break;
                        }
                    }
                }
            }
        }

        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(smell[i][j][0]!=0){
                    smell[i][j][0] -= 1;
                    if(smell[i][j][0]==0) smell[i][j][1]=0;
                }
            }
        }

        while(!q.empty()){
            int now = q.front().F;
            int next = q.front().S;
            q.pop();
            int x = shark[now][0];
            int y = shark[now][1];
            int nx = x + dx[next];
            int ny = y + dy[next];
            sea[x][y] = 0;

            if(smell[nx][ny][0]==0){
                sea[nx][ny] = now;
                smell[nx][ny][0] = k;
                smell[nx][ny][1] = now;
                shark[now][0] = nx;
                shark[now][1] = ny;
            }
            else if(smell[nx][ny][1]==now){
                sea[nx][ny] = now;
                smell[nx][ny][0] = k;
                smell[nx][ny][1] = now;
                shark[now][0] = nx;
                shark[now][1] = ny;
            }
            else {
                shark[now][0] = 0;
                shark[now][1] = 0;
            }
        }
    }
}
int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m >> k;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            int a;
            cin >> a;
            sea[i][j] = a;
            if(a!=0){
                smell[i][j][0] = k;
                smell[i][j][1] = a;
                shark[a][0] = i;
                shark[a][1] = j;
            }
        }
    }
    for(int i=1;i<=m;i++){
        cin >> shark[i][2];
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=4;j++){
            int a,b,c,d;
            cin >> a >> b >> c >> d;
            direc[i][j][1] = a;
            direc[i][j][2] = b;
            direc[i][j][3] = c;
            direc[i][j][4] = d;
        }
    }
    find();
    if(t>1000) t = -1;
    cout << t << endl;
}