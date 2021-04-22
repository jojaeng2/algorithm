#include <iostream>
#include <queue>
#include <vector>
#define INF 987654321 
using namespace std;
int n,k,m,result;
vector<int> station[101001];
int visit[101001];

void bfs(){
    queue<int>q;
    q.push(1);
    visit[1] = 1;
    while(!q.empty()){
        int x = q.front();
        q.pop();
        for(int i=0;i<station[x].size();i++){
            int next = station[x][i];
            if(next >= 100001 && visit[next]==INF){
                visit[next] = visit[x];
                q.push(next);
            }
            else {
                if(visit[next]==INF){
                    visit[next] = visit[x]+1;
                    q.push(next);
                }
            }
        }
    }
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> k >> m;
    for(int i=1;i<= m;i++){
        for(int j=1;j<=k;j++){
            int a;
            cin >> a;
            station[a].push_back(100000+i);
            station[100000+i].push_back(a);
        }
    }
    fill(visit,visit+101001,INF);
    bfs();
    result = visit[n];
    if(visit[n]==INF) result = -1;
    cout << result << endl;
}