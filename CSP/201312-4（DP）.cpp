#include <iostream>
using namespace std;
const long long mod = 1000000007;
long long sta[1024][6];
int main() {
  int n = 0;
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    sta[i][0] = 1;
    sta[i][1] = (sta[i - 1][0] + sta[i - 1][1] * 2) % mod;
    sta[i][2] = (sta[i - 1][0] + sta[i - 1][2]) % mod;
    sta[i][3] = (sta[i - 1][1] + sta[i - 1][3] * 2) % mod;
    sta[i][4] = (sta[i - 1][1] + sta[i - 1][2] + sta[i - 1][4] * 2) % mod;
    sta[i][5] = (sta[i - 1][3] + sta[i - 1][4] + sta[i - 1][5] * 2) % mod;
  }
  cout << sta[n][5];
  return 0;
}

