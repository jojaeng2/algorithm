#include <iostream>
#include <queue>
#include <vector>

using namespace std;
vector<vector<int> > graph(501);
int visit[501]={0};
queue<int>q;

int main(){
    int n,m;
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int a,b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    visit[1] = 1;
    q.push(1);
    while(!q.empty()){
        int x;
        x = q.front();
        q.pop();
        for(int i=0;i<graph[x].size();i++){
            if(visit[graph[x][i]] == 0){
                visit[graph[x][i]] = visit[x] + 1;
                q.push(graph[x][i]);
            }
        }
    }
    int result = 0;
    for(int i=0;i<=n;i++){
        if(visit[i] == 3 || visit[i] == 2){
            result += 1;
        }
    }
    cout << result << endl;
}