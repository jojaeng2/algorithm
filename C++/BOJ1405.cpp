#include <iostream>

using namespace std;
double direc[4];
bool visit[101][101] = {false};
double result = 0;
int n,a,b,c,d;
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

void dfs(int x,int y,double num,int cnt){
    if(cnt == a){
        if(visit[x][y] == false){
            result += num;
        }
        return;
    }
    visit[x][y] = true;
    for(int i=0;i<4;i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        double sum = num * ((double) direc[i]/100);
        if(visit[nx][ny] == true){
            continue;
        }
        dfs(nx,ny,sum,cnt+1);
        visit[nx][ny] = false;
    }
}

int main(){
    cin >> a;
    for(int i=0;i<4;i++){
        cin >> direc[i];
    }
    dfs(40,40,1,0);
    cout.precision(11);
    cout << result << endl;
}