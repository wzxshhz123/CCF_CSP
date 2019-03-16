#include <iostream>
#include <queue>
#include <list>
#include <algorithm> 
using namespace std;
struct Tea {
	int need = -1;
	int time = -1;
	int type = -1;
	
	Tea(int ne_, int ti_, int ty_) : need(ne_), time(ti_), type(ty_) {
		
	}
	 
}; 
constexpr int max_n = 1005;
int box[max_n] = {0};
int pos[max_n] = {0};
int main() {
	int n = 0;
	int k = 0;
	auto Cmp = [](const Tea &lhs, const Tea &rhs) {
		if (lhs.time != rhs.time)
			return lhs.time > rhs.time;
		else if (lhs.type != rhs.type) 
			return lhs.type > rhs.type;
		else
			return lhs.need > rhs.need;
	};
	priority_queue<Tea, vector<Tea>, decltype(Cmp)> que(Cmp);
	cin >> n >> k;
	for (int i = 1;i <= n;++i) {
		box[i] = i;
		pos[i] = i;
	}
	for (int i = 0;i < k;++i) {
		int st = -1;
		int ed = -1;
		int ne = -1;
		cin >> ne >> st >> ed;
		que.emplace(ne, st, 1);
		que.emplace(ne, st + ed, -1);
	}
	list<int> l;
	while (!que.empty()) {
		auto temp = que.top();
		que.pop();
//		cout << temp.need << " " << temp.time << " " << temp.type << '\n'; 
		if (temp.type > 0) {
			box[pos[temp.need]] = 0;
			l.push_back(pos[temp.need]);
			pos[temp.need] = -1;
		} 
		else if (temp.type < 0) {
			auto min = min_element(l.begin(), l.end());
			box[*min] = temp.need;
			pos[temp.need] = *min;
			l.erase(min);
		}
	}
	for (int i = 1;i <= n;++i) {
		cout << box[i];
		if (i != n)
			cout << " ";
	}
	
	return 0;
	
}
