#include <bits/stdc++.h>
#define X first
#define Y second
#define NUM 100010
#define INF 10000000
#define MOD 1000000007
#define LOG 22
#define POW2(x) x*x
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef pair<int, ll> pil;
typedef pair<pii, int> piii;
typedef pair<piii, int> piiii;
typedef pair<ll, ll> pll;
typedef pair<pll, ll> plll;
ll vis[1010], n, m, state[1010];
vector<pll> adj[1010];


void init() {
	vector<int> ans, nums;
	int target = 6;
	nums.push_back(3);
	nums.push_back(3);
	for(int i=0; i<nums.size(); i++) {
		int num = nums[i];
		int idx = lower_bound(nums.begin()+i+1, nums.end(), target-num) - nums.begin();
		cout << idx << " " << num << "  "<< nums[idx] << '\n';
		if(num + nums[idx] == target) {
			ans.push_back(i);
			ans.push_back(idx);
			break;
		}
	}
}		

int main() {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	init();
}