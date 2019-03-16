#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
struct Ball {
	int pos = -1;
	int dir = 0;
};
int main() {
	int n = 0;
	int L = 0;
	int t = 0;
	cin >> n >> L >> t;
	vector<Ball> vec;
	Ball ins;
	ins.dir = 1; 
	unordered_map<int, int> mp;
	for (int i = 0;i < n;++i) {
		int e = 0;
		cin >> e;
		ins.pos = e;
		vec.push_back(ins);
		mp[e] = i;
	}
	while (t--) {
		for (int i = 0;i < vec.size();++i) {
			int pre = vec[i].pos;
			if (vec[i].dir > 0)
				++vec[i].pos;
			else 
				--vec[i].pos;
			if (vec[i].pos > L) {
				vec[i].dir = -vec[i].dir;
				vec[i].pos = L - 1;
			}
			else if (vec[i].pos < 0) {
				vec[i].dir = -vec[i].dir;
				vec[i].pos = 1;
			}
			if (mp.count(vec[i].pos) != 0) {
					if (mp[vec[i].pos] != -1 && mp[vec[i].pos] != i) {
						vec[i].dir = -vec[i].dir;
						vec[mp[vec[i].pos]].dir = -vec[mp[vec[i].pos]].dir;
				}
			}
			mp[pre] = -1;
			mp[vec[i].pos] = i;
		}
	}
	for (int i = 0;i < vec.size();++i) {
		cout << vec[i].pos;
		if (i != n - 1) 
			cout << " ";
	}
} 
