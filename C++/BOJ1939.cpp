#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;
typedef pair<int,ll> pil;
int n,m,starting,destination;
vector<pil> graph[10001];
bool visit[10001];
ll start,final,mid,result;

bool dfs(int num){
    visit[num] = true;
    if(num==destination) return true;
    for(int i=0;i<graph[num].size();i++){
        ll weight = graph[num][i].second;
        int node = graph[num][i].first;
        if(!visit[node] && mid <= weight){
            if(dfs(node)){
                return true;
            }
        }
    }
    return false;
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int a,b;
        ll c;
        cin >> a >> b >> c;
        graph[a].push_back(make_pair(b,c));
        graph[b].push_back(make_pair(a,c));
    }
    cin >> starting >> destination;
    start = 1;
    final = 1000000000;
    result = 0;
    while(start<=final){
        fill(visit,visit+10001,false);
        mid = (start + final)/2;
        if(dfs(starting)){
            result = max(result,mid);
            start = mid +1;
        } else {
            final = mid - 1;
        }
    }
    cout << result << endl;
}