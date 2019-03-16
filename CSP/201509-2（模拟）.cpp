#include <iostream>
using namespace std;
int main() {
	int month[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int year = 0;
	int day = 0;
	scanf("%d %d", &year, &day);
	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
		month[2] =  29;
	}
	int i = 1;
	while (day > month[i]){
		day -= month[i];
		++i;	
	}	
	cout << i << '\n' << day;
	return 0;
}
