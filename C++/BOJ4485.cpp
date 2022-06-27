#include <iostream>
#include <queue>
#define INF 10e9

using namespace std;
typedef pair<pair<int,int>,int> pii;
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};
int graph[126][126];
int visit[126][126];
int n;

void dijk(){
    priority_queue<pii>pq;
    pq.push({{-graph[0][0],0},0});
    visit[0][0] = graph[0][0];
    while(!pq.empty()){
        int dist = -pq.top().first.first;
        int x = pq.top().first.second;
        int y = pq.top().second;
        pq.pop();
        if(visit[x][y] < dist){
            continue;
        }
        for(int i=0;i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(0<=nx && nx <n && 0<=ny && ny<n){
                int cost = dist + graph[nx][ny];
                if(cost<visit[nx][ny]){
                    visit[nx][ny] = cost;
                    pq.push({{-visit[nx][ny],nx},ny});
                }
            }
        }
    }
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int cnt=0;
    while(1){
        cin >> n;
        if(n==0) break;
        cnt += 1;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cin >> graph[i][j];
                visit[i][j] = INF;
            }
        }
        dijk();
        cout << "Problem " << cnt << ": " << visit[n-1][n-1] << '\n';
    }
}