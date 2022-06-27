#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#define NUM 500010
using namespace std;
typedef long long ll;
int n, m, num[NUM];
ll tree[4*NUM];

void update(int s, int e, int node, int idx, int dif) {
    if(s > idx || e < idx) return;
    tree[node] += dif;
    if(s == e) return;
    int mid = (s + e)/2;
    update(s, mid, node*2, idx, dif);
    update(mid+1, e, node*2+1, idx, dif);
}

ll init_tree(int s, int e, int node) {
    if(s == e) return tree[node] = num[s];
    int mid = (s+e)/2;
    return tree[node] = init_tree(s, mid, node*2) + init_tree(mid+1, e, node*2+1);
}

int query(int s, int e, int node, int psum) {
    if(psum == tree[node] ||s == e) return e;
    int mid = (s+e)/2;
    if(tree[node*2] >= psum) return query(s, mid, node*2, psum);
    else return query(mid+1, e, node*2+1, psum-tree[node*2]);
}



void init() {
    memset(num, 0, sizeof(num));
    memset(tree, 0, sizeof(tree));
    cin >> n;
    for(int i=1; i<=n; i++) cin >> num[i];
    init_tree(1, n, 1);
    cin >> m;
    for(int i=0; i<m; i++) {
        int x, y, z;
        cin >> x;
        if(x == 1) {
            cin >> y >> z;
            update(1, n, 1, y, z);
        }
        else {
            cin >> y;
            cout << query(1, n, 1, y) << '\n';
        }
    
    }
    

}

int main()
{
    init();
}