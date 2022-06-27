#include <iostream>

using namespace std;
int n,m;
int graph[500001];
int find(int start){
    if(start==graph[start]) return start;
    graph[start] = find(graph[start]);
    return graph[start];
}
bool uni(int x,int y){
    int a = find(x);
    int b = find(y);
    if(a==b) return true;
    graph[b] = a;
    return false;
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;

    for(int i=0;i<n;i++){
        graph[i] = i;
    }
    bool flag = false;
    int result = 0;
    for(int i=0;i<m;i++){
        int a,b;
        cin >> a >> b;
        if(flag==true) continue;
        if(uni(a,b)){
            flag = true;
            result = i+1;
        }
    }
    cout << result << '\n';
}