#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <regex>
using namespace std;
ofstream os;
//#define cout os
string sl("\\[([^\\]]+)\\]\\(([^\\)]+)\\)");
regex sl_re(sl);
string sl_replace("<a href=\"$2\">$1</a>");
string qd("_([^_]+)_");
regex qd_re(qd);
string qd_replace("<em>$1</em>");
void LineInside(string &str) {
	auto temp = regex_replace(str, qd_re, qd_replace);
	cout << regex_replace(temp, sl_re, sl_replace);
}
int main() {
	os.open("t.txt");
	string line;
	int p_flag = 0;
	int u_flag = 0;
	while (getline(cin, line)) {
		if (line[0] != '*' && u_flag) {
			cout << "</ul>" << "\n";
			u_flag = 0;
		}
		if ((line[0] == '#' || line[0] == '*' || line == "") && p_flag) {
			p_flag = 0;
			cout << "</p>" << "\n";
		}
		if (line[0] != '#' && line[0] != '*' && line != "") {
			if (!p_flag) {
				cout << "<p>";
				p_flag = 1;
			}
			else {
				cout << "\n";
			}
			LineInside(line);
		} 
		else if (line[0] == '#') {
			int num = 1;
			int space_num = 1;
			for (int i = 1;i < line.length();++i) {
				if (line[i] == '#') {
					++num;	
					++space_num;
				}	
				else if (line[i] == ' ') {
					++space_num;
				}
				else {
					break;
				}
			}
			cout << "<h" << num << ">";
			line = line.substr(space_num, line.length() - space_num);
			LineInside(line);
			cout << "</h" << num << ">" << "\n";
		}
		else if (line[0] == '*') {
			if (!u_flag) {
				u_flag = 1;
				cout << "<ul>" << "\n";
			}
			cout << "<li>";
			int space_num = 1;
			for (int i = 1;i < line.length();++i) {
				if (line[i] == ' ')
					++space_num;
				else
					break;
			}
			line = line.substr(space_num, line.length() - space_num);
			LineInside(line);
			cout << "</li>\n";
		}
	}
	if (u_flag) {
		cout << "</ul>" << "\n";
		u_flag = 0;
	}
	if (p_flag) {
		p_flag = 0;
		cout << "</p>" << "\n";
	}
	return 0;
} 
