#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
using namespace std;
string str[1001][1001];
int cnt[1001][1001];

void init() {
    memset(cnt, 0, sizeof(cnt));
    string s1, s2;
    cin >> s1 >> s2;
    for(int i=0; i<s1.size(); i++) {
        for(int j=0; j<s2.size(); j++) {
            if(s1[i] == s2[j]) {
                cnt[i+1][j+1] = cnt[i][j] + 1;
                str[i+1][j+1] = str[i][j] + s1[i];
            }
            else if(cnt[i][j+1] <= cnt[i+1][j]) {
                cnt[i+1][j+1] = cnt[i+1][j];
                str[i+1][j+1] = str[i+1][j];
            }
            else if(cnt[i][j+1] > cnt[i+1][j]) {
                cnt[i+1][j+1] = cnt[i][j+1];
                str[i+1][j+1] = str[i][j+1];
            }
        }
    }
    cout << cnt[s1.size()][s2.size()] << '\n';
    if(cnt[s1.size()][s2.size()] != 0) cout << str[s1.size()][s2.size()] << '\n'; 
}

int main() {
    init();
}