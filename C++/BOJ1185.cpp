#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
typedef pair<pair<int,int>,int> piii;
int n,m,result;
int node[10001];
int visit[10001];
vector<piii> graph;

int find(int start){
    if(start==visit[start]) return start;
    visit[start]=find(visit[start]);
    return visit[start];
}
bool uni(int a,int b){
    int fa = find(a);
    int fb = find(b);
    if(fa==fb) return false;
    if(fa<fb){
        visit[fb]=fa;
    } else {
        visit[fa]=fb;
    }
    return true;
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        int num;
        cin >> num;
        node[i] = num;
    }
    for(int i=0;i<m;i++){
        int a,b,c;
        cin >> a >> b >> c;
        int cost = 2*c + node[a] + node[b];
        graph.push_back(make_pair(make_pair(cost,a),b));
    }

    sort(graph.begin(),graph.end());

    for(int i=0;i<=n;i++){
        visit[i]=i;
    }
    
    for(int i=0;i<graph.size();i++){
        int cost = graph[i].first.first;
        int x = graph[i].first.second;
        int y = graph[i].second;
        if(uni(x,y)){
            result += cost;
        }
    }
    int minnum = node[1];
    for(int i=1;i<=n;i++){
        minnum = min(minnum,node[i]);
    }
    cout << result + minnum << endl;
}