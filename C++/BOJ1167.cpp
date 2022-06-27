#include <iostream>
#include <vector>
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;

vector<pii>graph[100001];
bool visit[100001];
ll mx =0;
int idx=0;

void init(int input){
    for(int i=0;i<input;i++){
        int d;
        cin >> d;
        while(1){
            int a;
            cin >> a;
            if(a==-1){
                break;
            } else {
                int b;
                cin >> b;
                graph[d].push_back(make_pair(a,b));
            }
        }
    }
}
void dfs(int x,ll cnt){
    visit[x] = true;
    if(mx < cnt){
        mx = cnt;
        idx = x;
    }
    for(int i=0;i<graph[x].size();i++){
        int next = graph[x][i].first;
        int dist = graph[x][i].second;
        if(visit[next]){
            continue;
        }
        dfs(next,cnt+dist);
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
    fill(visit,visit+100001,false);
    dfs(idx,0);
    cout << mx << '\n';
}