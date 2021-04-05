#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int graph[1001][1001];
bool visit[1001][1001];
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};

void bfs(int a,int b){
    queue<pair<int,int> >q;
    q.push(make_pair(a,b));
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(0 <= nx && nx < 1001 && 0 <= ny && ny < 1001){
                if(graph[nx][ny] == 1 && visit[nx][ny] == false){
                    visit[nx][ny] = true;
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

    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        int x1,y1,x2,y2;
        cin >> x1 >> y1 >> x2 >> y2;
        x1 += 500;
        y1 += 500;
        x2 += 500;
        y2 += 500;
        for(int j=x1;j<x2+1;j++){
            if(j == x1 || j == x2){
                for(int p=y1;p<y2+1;p++){
                    graph[j][p] = 1;
                }
            }
            else{
                graph[j][y1] = 1;
                graph[j][y2] = 1;
            }
        }
    }
    
    int cnt = 0;
    for(int i=0;i<1001;i++){
        for(int j=0;j<1001;j++){
            if(graph[i][j] == 1 && visit[i][j] == false){
                cnt += 1;
                bfs(i,j);
            }
        }
    }
    if(graph[500][500] == 1){
        cnt -= 1;
    }
    cout << cnt << endl;
}