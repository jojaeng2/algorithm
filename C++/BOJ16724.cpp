#include <iostream>
#include <vector>
#include <string>

using namespace std;
typedef pair<int,int> pii;
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};
char direction[4] = {'U','D','L','R'};

char graph[1001][1001];
int visit[1001][1001];
vector<pii> stack;
int cnt = 0;

void dfs(int x,int y){
    if(visit[x][y] != 0){
        if(visit[x][y] == -1){
            cnt -= 1;
        }
        while(!stack.empty()){
            int nx = stack.back().first;
            int ny = stack.back().second;
            stack.pop_back();
            visit[nx][ny] = -1;
        }
        return;
    }
    visit[x][y] = 2;
    stack.push_back(make_pair(x,y);
    for(int i=0;i<4;i++){
        if(graph[x][y] == direction[i]){
            dfs(x+dx[i],y+dy[i]);
        }
    }
}

int main(){
    int n,m;
    cin >> n >> m;
    for(int i=0;i<n;i++){
        string alpha;
        cin >> alpha;
        for(int j=0;j<m;j++){
            graph[i][j] = alpha[j];
        }
    }
    if(n==1 && m == 1){
        cout << 1 << '\n';
    }
    else {
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(visit[i][j] == 0){
                    cnt += 1;
                    dfs(i,j);
                }
            }
        }
        cout << cnt << '\n';
    }

}