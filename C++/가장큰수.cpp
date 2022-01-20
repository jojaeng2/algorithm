#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
vector<string> v;

bool compare(string a, string b) {
    if(a + b > b + a) return true;
    return false;
}

string solution(vector<int> numbers) {
    string answer = "";
    for(int num : numbers) v.push_back(to_string(num));
    sort(v.begin(), v.end(), compare);
    for(string num : v) answer += num;
    if(answer[0] == '0') answer = "0";
    return answer;
}