#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
struct students {
    int cnt, score, idx;
};
int n, m, k, visit[31];
vector<students> student;
vector<int> v[100010];

void update(int idx, int dif) {
    for(int i=0; i<student[idx].cnt; i++) visit[v[student[idx].idx][i]] += dif;
}

int check(int len) {
    int psum = 0;
    for(int i=1; i<=30; i++) {
        if(visit[i] == 0) continue;
        if(visit[i] != len) psum++;
    }
    return (psum) * len;
}

void solve() {
    int l = 0, r = 0, answer = 0;
    for(int i=0; i<student.front().cnt; i++) visit[v[student.front().idx][i]]++;
    while(l<=r) {
        if(student[r].score - student[l].score > k) update(l++, -1);
        else {
            answer = max(answer, check(r-l+1));
            if(r == n-1) {
                if(l == n-1) break;
                update(l++, -1);
            }
            else update(++r, 1);
        }
    }
    cout << answer << '\n';
}

bool compare(students a, students b) {
    return a.score < b.score;
}

void init() {
    ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    memset(visit, 0, sizeof(visit));
    cin >> n >> m >> k;
    for(int i=1; i<=n; i++) {
        students st;
        cin >> st.cnt >> st.score;
        st.idx = i;
        student.push_back(st);
        for(int j=0; j<st.cnt; j++) {
            int al;
            cin >> al;
            v[i].push_back(al);
        }
    }
    sort(student.begin(), student.end(), compare);
}

int main() {
    init();
    solve();
}