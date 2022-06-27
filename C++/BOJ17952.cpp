#include <iostream>
#include <stack>
using namespace std;
typedef pair<int, int> pii;
int n, answer = 0;
stack<pii> st;

void init() {
    cin >> n;
    while(n--) {
        int x;
        cin >> x;
        if(x == 1) {
            int y, z;
            cin >> y >> z;
            if(z == 1) answer += y;
            else st.push(make_pair(y, z-1));
        }
        else {
            if(st.size()==0) continue;
            st.top().second--;
            if(st.top().second == 0) {
                answer += st.top().first;
                st.pop();
            }
        }
    }
    cout << answer << '\n';
}

int main() {
    init();
}