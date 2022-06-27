#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define X first
#define Y second
using namespace std;
typedef pair<int,int> pii;
int  dx[4] = {-1,1,0,0}, dy[4] = {0,0,-1,1};
int n,m;
queue<pii> q;
vector<pii> v[101][101];
int visit[101][101];
int result = 1;

void bfs(){
    while(!q.empty()){
        int x = q.front().X;
        int y = q.front().Y;
        q.pop();
        for(int i=0;i<v[x][y].size();i++){
            int switch_x = v[x][y][i].X;
            int switch_y = v[x][y][i].Y;
            if(visit[switch_x][switch_y]==0){
                visit[switch_x][switch_y] = 1;
                result++;
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                for(int p=0;p<4;p++){
                    int nx = i + dx[p];
                    int ny = j + dy[p];
                    if(visit[i][j]==1 && visit[nx][ny]==2){
                        visit[i][j]=2;
                        q.push(make_pair(i,j));
                    }
                }
            }
        }
    }
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for(int i=0;i<m;i++){
        int x,y,a,b;
        cin >> x >> y >> a >> b;
        v[x][y].push_back(make_pair(a,b));
    }
    q.push(make_pair(1,1));
    visit[1][1] = 2;

    bfs();
    
    cout << result << '\n';
}   