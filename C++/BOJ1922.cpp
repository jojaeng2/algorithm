#include <iostream>
#include <vector>
#include <algorithm>
#define X first
#define Y second
using namespace std;
typedef pair<pair<int,int>,int> piii;
vector<piii> graph;
int visit[1001];
int n,m,result=0;

int find(int start){
    if(start==visit[start]){
        return start;
    }
    visit[start] = find(visit[start]);
    return visit[start];
}

bool uni(int a,int b){
    int aa = find(a);
    int bb = find(b);
    if(aa==bb) return false;
    visit[bb]=aa;
    return true;
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for(int i=1;i<=n;i++){
        visit[i]=i;
    }
    for(int i=0;i<m;i++){
        int a,b,c;
        cin >> a >> b >> c;
        graph.push_back(make_pair(make_pair(c,a),b));
    }
    sort(graph.begin(),graph.end());

    for(int i=0;i<graph.size();i++){
        int cost = graph[i].X.X;
        int a = graph[i].X.Y;
        int b = graph[i].Y;
        if(uni(a,b)) result += cost;
    }
    cout << result << endl;
}