#include <iostream>
#include <queue>
#include <string>

using namespace std;
int graph[1001][1001];
int visit[1001][1001][11] = {0};
queue<pair<pair<pair<int,int>,int>,int> >q;
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,m,k;
    cin >> n >> m >> k;
    for(int i=0;i<n;i++){
        string s;
        cin >> s;
        for(int j=0;j<s.length();j++){
            graph[i][j] = s[j]-'0';
        }
    }
    q.push(make_pair(make_pair(make_pair(0,0),0),0));
    visit[0][0][0] = 1;
    while(!q.empty()){
        int x = q.front().first.first.first;
        int y = q.front().first.first.second;
        int breaked = q.front().first.second;
        int cnt = q.front().second;
        q.pop();
        if(cnt == 0){
            for(int i=0;i<4;i++){
                int nx = x + dx[i];
                int ny = y + dy[i];
                if(0<=nx && nx < n && 0<=ny && ny<m){
                    if(graph[nx][ny] == 0 && visit[nx][ny][breaked] == 0){
                        visit[nx][ny][breaked] = visit[x][y][breaked] + 1;
                        q.push(make_pair(make_pair(make_pair(nx,ny),breaked),1));
                    }
                    else if(graph[nx][ny] == 1 && breaked != k && visit[nx][ny][breaked+1] == 0){
                        visit[nx][ny][breaked+1] = visit[x][y][breaked] + 1;
                        q.push(make_pair(make_pair(make_pair(nx,ny),breaked+1),1));
                    }
                }
            }
        } else {
            
            for(int i=0;i<4;i++){
                int nx = x + dx[i];
                int ny = y + dy[i];
                if(0<=nx && nx < n && 0<=ny && ny<m){
                    if(graph[nx][ny] == 0 && visit[nx][ny][breaked] == 0){
                        visit[nx][ny][breaked] = visit[x][y][breaked] + 1;
                        q.push(make_pair(make_pair(make_pair(nx,ny),breaked),0));
                    }
                }
            }
            if(x != n-1 || y != m-1){
                visit[x][y][breaked] += 1;
                q.push(make_pair(make_pair(make_pair(x,y),breaked),0));
            }
        }
    }
    int mx = 100000001;
    for(int i=0;i<=k;i++){
        if(visit[n-1][m-1][i] != 0 && visit[n-1][m-1][i] < mx){
            mx = visit[n-1][m-1][i];
        }
    }
    if(mx == 100000001){
        cout << -1 << endl;
    } else {
        cout << mx << endl;
    }
}