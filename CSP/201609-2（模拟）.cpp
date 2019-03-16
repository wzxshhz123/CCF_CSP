#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int seats[21] = {0};
int main() {
	int n = 0;
	vector<int> vec; 
	fill(seats, seats + 21, 5); 
	scanf("%d", &n); 
	for (int i = 0;i < n;++i) {
		int e = 0;
		scanf("%d", &e);
		vec.push_back(e);
	}
	for (int i = 0;i < vec.size();++i) {
		int num = vec[i];
		int flag = 0;
		for (int j = 1;j <= 20;++j) {
			if (seats[j] >= num) {
				flag = 1;
				int st = seats[j];
				seats[j] -= num;
				int z = 0;
				for (int k = 5 - st + 1;num != 0;++k, --num) {
					cout << (j - 1) * 5 + k;
					if (num != 1)
						cout << " ";
				}
			}
		}
		if (!flag) {
			int f = 0;
			for (int j = 1;j <= 20;++j) {
				if (seats[j] != 0) {
					for (int k = 5 - seats[j] + 1;seats[j] != 0 && num != 0;++k, --seats[j], --num) {
						if (f)
							cout << " ";
						f = 1;
						cout << (j - 1) * 5 + k;
					}
				}
				if (num == 0)
					break;
			}
		}
		cout << '\n';
	}
	return 0;
}
