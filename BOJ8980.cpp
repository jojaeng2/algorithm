#include <iostream>
#include <vector>
using namespace std;
int n, max_weight, m;
struct trucks {
	int start, destination, weight;
};
vector<trucks> v;



bool compare(trucks a, trucks b) {
	if(a.destination == b.destination) {
		return a.start < b.start;
	}
	else return a.destination < b.destination;
}

void init() {
	cin >> n >> max_weight >> m;
	for(int i=0; i<m; i++) {
		trucks truck;
		cin >> truck.start >> truck.destination >> truck.weight;
		v.push_back(truck);
	}
	sort(v.begin(), v.end(), compare);

	int ans = 0;
	int city[n+1];
	fill(city, city+n+1, 0);
	for(int i=0; i<m; i++) {
		int maxi = 0;
		for(int j=v[i].start; j<v[i].destination; j++) maxi = max(maxi, city[j]);
		int left = min(v[i].weight, max_weight-maxi);
		ans += left;
		for(int j=v[i].start; j<v[i].destination; j++) city[j] += left;
	}
	cout << ans << '\n';
}

int main() {
	init();
}