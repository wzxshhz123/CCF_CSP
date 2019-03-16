#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
struct Record {
  int type;
  long long s = -1;
  double p = 1;
  bool flag = false;
};
vector<Record> records;
bool Cmp(const Record &lhs, const Record &rhs) {
  if (!lhs.flag || !rhs.flag)
    return lhs.flag > rhs.flag;
  else if (lhs.type != rhs.type)
    return lhs.type > rhs.type;
  else
    return lhs.p > rhs.p;
};
int main() {
  string str;
  double p;
  int s;
  while (cin >> str) {//读取每行数据
    if (str == "cancel") {
      cin >> s;
      records[s - 1].flag = false;
      Record ins;
      records.push_back(ins);
    }
    else {
      cin >> p >> s;
      Record ins;
      ins.flag = true;
      ins.p = p;
      ins.s = s;
      if (str == "buy")
        ins.type = 1;
      else
        ins.type = 0;
      records.push_back(ins);
    }
  }
  long long buyS = 0;
  long long ansS = 0;
  double ansP = 0;
  sort(records.begin(), records.end(), Cmp);
  for (int i = 0; i < records.size() && records[i].flag == true && records[i].type == 1; ++i) {
    buyS += records[i].s;
    long long sellS = 0;
    for (int j = 0; j < records.size(); ++j) {
    	if (records[j].p <= records[i].p && records[j].flag == true && records[j].type == 0)
    		sellS += records[j].s;
		}
    if (min(buyS, sellS) > ansS) {
      ansS = min(buyS, sellS);
      ansP = records[i].p;
    }
  }
  printf("%.2f %lld", ansP, ansS);//输出
  return 0;
}
