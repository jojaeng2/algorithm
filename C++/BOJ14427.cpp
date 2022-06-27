#include <iostream>
#define NUM 100000
using namespace std;
typedef pair<int,int> pii;
int n, m, number[NUM+10];
pii tree[4*NUM+10];


pii segment(int start, int end, int node){
    if(start==end) {
        tree[node].first = number[start];
        tree[node].second = start;
        return tree[node];
    }
    int mid = (start+end)/2;
    pii a = segment(start, mid, node*2), b = segment(mid+1, end, node*2+1);
    if(a<=b) {
        tree[node] = a;
        return tree[node];
    }
    else {
        tree[node] = b;
        return tree[node];
    }
}

pii update(int start, int end, int node, int idx) {
    if(idx<start || idx>end) return tree[node];
    if(start == end) {
        tree[node].first = number[start];
        tree[node].second = start;
        return tree[node];
    }
    int mid = (start+end)/2;
    pii a = update(start, mid, node*2, idx), b = update(mid+1, end, node*2+1, idx);
    if(a<=b) {
        tree[node] = a;
        return tree[node];
    }
    else {
        tree[node] = b;
        return tree[node];
    }
}

void init() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for(int i=1; i<=n; i++) {
        cin >> number[i];
    }
    segment(1, n, 1);
    cin >> m;
    for(int i=0; i<m; i++) {
        int order;
        cin >> order;
        if(order == 1) {
            int a, b;
            cin >> a >> b;
            number[a] = b;
            update(1, n, 1, a);
        }
        else {
            cout << tree[1].second << '\n';
        }
    }
}

int main() {
    init();
}