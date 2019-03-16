#include <iostream>
#include <list>
#include <algorithm>
using namespace std;
int main() {
	int n = 0;
	scanf("%d", &n);
	list<int> l;
	for (int i = 1;i <= n;++i)
		l.push_back(i);
	int q = 0;
	scanf("%d", &q);
	for (int i = 0;i < q;++i) {
		int e = 0;
		int pos = 0;
		scanf("%d %d", &e, &pos);
		auto now = find(l.begin(), l.end(), e);
		int v = *now;
		if (pos > 0) {
			if (l.size() - distance(l.begin(), now) < pos) {
				l.erase(now);
				l.push_back(v);
			}
			else {
				auto temp = now;
				while (pos != 0) {
					++now;
					--pos;
				}
				++now;
				l.insert(now, v);
				l.erase(temp);
			} 
		}
		else {
			if (distance(l.begin(), now) < abs(pos)) {
				l.erase(now);
				l.push_front(v);
			}
			else {
				auto temp = now;
				while (pos != 0) {
					--now;
					++pos;
				}
				l.insert(now, v);
				l.erase(temp);
			} 	
		} 
		
	}
	int f = 0;
	for (auto iter = l.begin();iter != l.end();++iter) {
		if (f)
			cout << " ";
		f = 1;
		cout << *iter;
	}
	return 0; 
}
