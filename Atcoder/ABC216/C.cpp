#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <stack>
#include <string>
#include <cmath>
#include <deque>
#include <list>
#define X first
#define Y second
#define NUM 100
#define INF 1000000
#define POW2(x) x*x
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
typedef pair<ll, int> pli;
ll n;
string answer = "";

void init() {
	cin >> n;
	while(n>0) {
		if(n % 2 == 0) {
			answer += 'B';
			n /= 2;
		}
		else {
			answer += 'A';
			n--;
		}
	}
	reverse(answer.begin(), answer.end());
	cout << answer << '\n';
}

int main() {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	init();
}