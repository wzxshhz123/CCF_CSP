#include <iostream>
#include <cmath>
#include <set>
using namespace std;
int main(){
	int n = 0;
	set<int> s;
	scanf("%d", &n);
	for (int i = 0;i < n;++i) {
		int e = 0;
		scanf("%d", &e);
		s.insert(e);
	}
	int st = -1;
	int num = 0; 
	for (auto iter = s.begin();iter != s.end();++iter) {
		if (abs(*iter - st) == 1) {
			++num;
		}
		st = *iter;
	}
	cout << num;
}
