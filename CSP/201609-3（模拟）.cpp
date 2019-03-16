#include <iostream>
#include <list>
using namespace std;
struct Po {
	int hp = -1;
	int atk = -1;
	Po(int a, int h) : atk(a), hp(h) {
		
	}
};
struct Player {
	int hero = 30;
	list<Po>li;
};
int main() {
	Player player[2];
	int n = 0;
	cin >> n;
	int now = 0;
	for (int i = 0;i < n;++i) {
		string str;
		cin >> str;
		if (str == "summon") {
			int pos = -1;
			int a = -1;
			int h = -1;
			cin >> pos >> a >> h;
			int st = 1;
			auto temp = player[now].li.begin();
			while(temp != player[now].li.end()) {
				if (st == pos)
					break;
				++st;
				++temp;
			}
			player[now].li.insert(temp, Po(a, h));
		}
		else if (str == "attack") {
			int now_i = -1;
			int now_j = -1;
			int d = now;
			++d;
			d %= 2;
			cin >> now_i >> now_j;
			int st = 1; 
			auto temp = player[now].li.begin();
			while(temp != player[now].li.end()) {
				if (st == now_i)
					break;
				++st;
				++temp;
			}	
			if (now_j == 0) {
				player[d].hero -= temp->atk;
			}
			else {
				int st2 = 1;
				auto temp2 = player[d].li.begin();
				while(temp2 != player[d].li.end()) {
					if (st2 == now_j)
						break;
					++st2;
					++temp2;
				}
				temp2->hp -= temp->atk;
				temp->hp -= temp2->atk;
				if (temp->hp <= 0) {
					player[now].li.erase(temp);
				}
				if (temp2->hp <= 0) {
					player[d].li.erase(temp2);
				}
			}
		}
		else if (str == "end") {
			++now;
			now %= 2;
		}
	}
	if (player[0].hero <= 0) {
		cout << -1;
	}
	else if (player[1].hero <= 0) {
		cout << 1;
	}
	else {
		cout << 0;
	}
	cout << "\n";
	for (int i = 0;i < 2;++i) {
		cout << player[i].hero << "\n";
		cout << player[i].li.size();
		for (auto it = player[i].li.begin();it != player[i].li.end();++it) {
			cout << " " << it->hp;
		}
		cout << "\n";
	}
	return 0;
} 
