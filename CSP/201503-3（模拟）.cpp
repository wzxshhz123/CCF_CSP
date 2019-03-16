#include <bits/stdc++.h>
using namespace std;
int table[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
bool IsPrimeYear(int y) {
	if (!(y % 400) || ((y % 4 == 0) && y % 100 != 0))
		return true;
	return false;
}
int main() {
	int a = 0;
	int b = 0;
	int c = 0;
	int y1 = 0;
	int y2 = 0;
	cin >> a >> b >> c >> y1 >> y2;
	c = c % 7;
	int now = 1850;
	int sum = 2;
	int flag = 0;
	while (now != y2 + 1) {
		if (now < y1) {
//			cout << now << " " << sum << "\n";
			if (IsPrimeYear(now))
				sum += 366;
			else
				sum += 365;
			sum %= 7;
			++now;
			continue;
		}
		if (IsPrimeYear(now)) {
			table[2] = 29;	
			flag = 1;
		}
		int temp = sum;
		int month = 1;
		while (month != a) {
			temp += table[month];
			temp %= 7;
			++month;
		}
		int day = 1;
		int num = 0;
		int has = 0;
		while (day != table[a] + 1) {
			if (temp % 7 == c)
				++num;
			if (num == b) {
				printf("%04d/%02d/%02d\n", now, month, day);
				has = 1;
				break;
			}
			++day;
			++temp;
		}
		if (!has) {
			cout << "none" << "\n";
		}
		if (flag) {
			table[2] = 28;
			flag = 0;
		}
		if (IsPrimeYear(now))
			sum += 366;
		else
			sum += 365;
		sum %= 7;
		++now;
	}
	return 0;
} 
