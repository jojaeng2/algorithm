#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct st {
    int x, y, dist;
};
int n, par[1025];
vector<st> tree;
vector<int> graph[1025];

void print() {
    for(int i=1; i<=n; i++) {
        sort(graph[i].begin(), graph[i].end());
        cout << graph[i].size() << " ";
        for(int j=0; j<graph[i].size(); j++) {
            cout << graph[i][j] << " ";
        }
        cout << '\n';
    }
}

int find(int start) {
    if(start == par[start]) return start;
    return par[start] = find(par[start]);
}

bool uni(int a, int b) {
    int aa = find(a), bb = find(b);
    if(aa == bb) return false;
    if(bb < aa) par[aa] = bb;
    else par[bb] = aa;
    return true;
}

void kruscal() {
    for(int i=0; i<tree.size(); i++) {
        int x = tree[i].x, y = tree[i].y;
        if(uni(x, y)) {
            graph[x].push_back(y);
            graph[y].push_back(x);
        }
    }
}

bool compare(st a, st b) {
    return a.dist < b.dist;
}

void init() {
    cin >> n;
    for(int i=1; i<n; i++) {
        for(int j=i+1; j<=n; j++) {
            int dist;
            cin >> dist;
            st s;
            s.x = i, s.y = j, s.dist = dist;
            tree.push_back(s);
        }
    }
    sort(tree.begin(), tree.end(), compare);
    for(int i=0; i<=n; i++) par[i] = i;
}

int main() {
    init();
    kruscal();
    print();
}