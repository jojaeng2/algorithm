#include <iostream>
#include <queue>
#include <vector>
#include <string>
#define INF 987654321
#define X first
#define Y second
using namespace std;

typedef pair<pair<int,int>,int> piii;
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};
int n;
int graph[51][51];
int visit[51][51];
void dijk(){
    priority_queue<piii, vector<piii>, greater<piii> > pq;
    pq.push({{0,0},0});
    visit[0][0]=0;
    while(!pq.empty()){
        int dist = -pq.top().X.X;
        int x = pq.top().X.Y;
        int y = pq.top().Y;
        pq.pop();
        if(visit[x][y]<dist) continue;
        
        for(int i=0;i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(0<=nx && nx<n && 0<=ny && ny<n){
                if(graph[nx][ny]==0){
                    int cost = dist + 1;
                    if(cost<visit[nx][ny]){
                        visit[nx][ny]=cost;
                        pq.push({{-cost,nx},ny});
                    }
                }
                else {
                    if(dist < visit[nx][ny]){
                        visit[nx][ny] = dist;
                        pq.push({{-dist,nx},ny});
                    }
                }
            }
        }
    }
}

int main(){
    cin >> n;
    for(int i=0;i<n;i++){
        string s;
        cin >> s;
        for(int j=0;j<n;j++){
            int a = s[j]-'0';
            graph[i][j] = a;
            visit[i][j]=INF;
        }
    }
    dijk();
    cout << visit[n-1][n-1] << endl;
}