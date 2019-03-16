#include <iostream>
#include <list>
using namespace std;
struct Win {
	int x1 = -1;
	int x2 = -1;
	int y1 = -1;
	int y2 = -1;
	int id = -1;
	Win(int x1_, int y1_, int x2_, int y2_, int id_) : x1(x1_), y1(y1_), x2(x2_), y2(y2_), id(id_){
		
	}
};
bool Judge(const Win &lhs, int x, int y) {
	if (x >= lhs.x1 && x <= lhs.x2 && y >= lhs.y1 && y <= lhs.y2)
		return true;
	return false;
}
int main() {
	int n = 0;
	int m = 0;
	scanf("%d %d", &n, &m);
	list<Win> l;
	for (int i = 1;i <= n;++i) {
		int x1 = 0;
		int x2 = 0;
		int y1 = 0;
		int y2 = 0;
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		Win ins(x1, y1, x2, y2, i);
		l.push_front(ins);
	}
	for (int i = 0;i < m;++i) {
		int x = 0;
		int y = 0;
		scanf("%d %d", &x, &y);
		int j = 0;
		int f = 0;
		list<Win> not_in;
		for (auto iter = l.begin();iter != l.end();++iter) {
			if (Judge(*iter, x, y)) {
				printf("%d\n", iter->id);
				f = 1;
				l.push_front(*iter);
				l.erase(iter);
				break;
			}
		}
		if (!f) {
			printf("IGNORED\n");
		}
	}
	return 0;
} 
