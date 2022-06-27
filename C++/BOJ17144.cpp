#include <iostream>
#include <queue>
#include <vector>
#define X first
#define Y second
using namespace std;
typedef pair<int,int> pii;
typedef pair<pair<int,int>,int> piii;
int r,c,t;
int dx[4] = {-1,0,1,0},dy[4] = {0,1,0,-1};

int graph[51][51];
vector<pii> filter;
queue<piii> air;

void difusion(){
    for(int x=0;x<r;x++) for(int y=0;y<c;y++){
        if(graph[x][y]!=0 && graph[x][y]!=-1){
            int cnt=0;
            for(int i=0;i<4;i++){
                int nx = x+dx[i], ny = y+dy[i];
                if(0<=nx && nx<r && 0<=ny && ny<c && graph[nx][ny]!=-1){
                    air.push(make_pair(make_pair(nx,ny),graph[x][y]/5));
                    cnt++;
                }
            }
            graph[x][y] -= graph[x][y]/5 * cnt;
        }
    }
    while(!air.empty()){
        int x = air.front().X.X;
        int y = air.front().X.Y;
        int cost = air.front().Y;
        air.pop();
        graph[x][y] += cost;
    }
}
void remove(int x,int y,int now,int start,int end){
    int curve=0;
    if(now==1){
        dx[0] = 1, dx[2] = -1;
    }
    else{
        dx[0] = -1, dx[2] = 1;
    }
    while(true){
        int nx = x + dx[curve], ny = y + dy[curve];
        if(nx==filter[now].X && ny==filter[now].Y) break;
        if(graph[x][y]==-1) graph[nx][ny]=0;
        else if(start<=nx && nx<=end && 0<=ny && ny<c){
            graph[x][y] = graph[nx][ny];
            graph[nx][ny] = 0;
        } else {
            curve++;
            nx = x+dx[curve];
            ny = y+dy[curve];
            graph[x][y] = graph[nx][ny];
            graph[nx][ny] = 0;
        }
        x = nx;
        y = ny;
    }
}
int main(){
    cin >> r >> c >> t;
    for(int i=0;i<r;i++) for(int j=0;j<c;j++){
        cin >> graph[i][j];
        if(graph[i][j]==-1) filter.push_back(make_pair(i,j));
    }
    int x1 = filter[0].X, y1=filter[0].Y, x2=filter[1].X, y2=filter[1].Y;
    while(t--){
        if(t==-1) break;
        difusion();
        remove(x1,y1,0,0,x1);
        remove(x2,y2,1,x2,r-1);
    }

    int result = 0;
    for(int i=0;i<r;i++) for(int j=0;j<c;j++){
        if(graph[i][j]!=0 && graph[i][j]!=-1){
            result += graph[i][j];
        }
    }
    cout << result << endl;
}