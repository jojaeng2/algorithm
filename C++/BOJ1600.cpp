#include <iostream>
#include <queue>

using namespace std;
queue<pair<pair<int,int>,int> >q;
int graph[201][201];
int visit[201][201][31];
int dx[12] = {-1,1,0,0,-2,-2,2,2,-1,1,-1,1};
int dy[12] = {0,0,-1,1,-1,1,-1,1,-2,-2,2,2};

int main(){
    int k,w,h;
    cin >> k >> w >> h;
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            cin >> graph[i][j];
        }
    }
    visit[0][0][0] = 1;
    q.push(make_pair(make_pair(0,0),0));
    while(!q.empty()){
        int x = q.front().first.first;
        int y = q.front().first.second;
        int cnt = q.front().second;
        q.pop();
        for(int i=0;i<12;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(0 <= nx && nx < h && 0 <= ny && ny < w){
                if(i>=4){
                    if(graph[nx][ny] == 0 && cnt != k && visit[nx][ny][cnt+1] == 0){
                        visit[nx][ny][cnt+1] = visit[x][y][cnt] + 1;
                        q.push(make_pair(make_pair(nx,ny),cnt+1));
                    }
                }
                else{
                    if(graph[nx][ny] == 0 && visit[nx][ny][cnt] == 0){
                        visit[nx][ny][cnt] = visit[x][y][cnt] + 1;
                        q.push(make_pair(make_pair(nx,ny),cnt));
                    }
                }
            }
        }
    }
    int mx = 1000000000;
    for(int i=0;i<=k;i++){
        if(visit[h-1][w-1][i] != 0 && visit[h-1][w-1][i] < mx){
            mx = visit[h-1][w-1][i];
        }
    }
    if(mx==1000000000 || graph[0][0] == 1){
        cout << -1 << endl;
    }else{
        cout << mx-1 << endl;
    }
}