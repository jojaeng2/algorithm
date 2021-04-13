#include <iostream>
#include <string>
#include <queue>

using namespace std;

typedef pair<int,int>pii;
char graph[10001][501];
int r,c,cnt=0;
int dx[4] = {-1,0,1};
int dy[4] = {1,1,1};
queue<pii>v;

bool dfs(int x,int y){
    if(y==c-1) return true;
    for(int i=0;i<3;i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(0<=nx && nx<r && 0<=ny && ny<c){
            if(graph[nx][ny] == '.'){
                v.push(make_pair(x,y));
                graph[nx][ny] = 'x';
                if(dfs(nx,ny)) return true;
                else{
                    v.pop();
                }        
            }
        }
    }
    return false;
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> r >> c;
    for(int i=0;i<r;i++){
        string s;
        cin >> s;
        for(int j=0;j<c;j++){
            graph[i][j] = s[j];
        }
    }
    for(int i=0;i<r;i++){
        if(dfs(i,0)){
            graph[i][0] = 'x';
            cnt += 1;
        } 
    }
    cout << cnt << endl;
}