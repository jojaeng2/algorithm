#include <iostream>
#include <vector>

using namespace std;
typedef pair<int,int> pii;

vector<pii>graph[10001];
bool visit[10001];
int mx = 0;
int idx=0;

void init(int n){
    for(int i=0;i<n-1;i++){
        int a,b,c;
        cin >> a >> b >> c;
        graph[a].push_back(make_pair(b,c));
        graph[b].push_back(make_pair(a,c));
    }
}
void dfs(int start,int cnt){
    if(mx < cnt){
        mx = cnt;
        idx = start;
    }
    visit[start] = true;
    for(int i=0;i<graph[start].size();i++){
        int next = graph[start][i].first;
        int dist = cnt + graph[start][i].second;
        if(visit[next]){
            continue;
        }
        dfs(next,dist);
    }
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    init(n);
    dfs(1,0);
    mx = 0;
    fill(visit,visit+10001,false);
    dfs(idx,0);
    cout << mx << endl;
}