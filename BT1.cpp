#include<iostream>
#include<cctype>
#include<string>
using namespace std;


bool checkNumber(string s) {
	for (char ch : s) {
		if (isdigit(ch))
			return true;
	}
	return false;;
}


bool checkSpace(string s) {
	if(isspace(s[0]) || isspace(s[s.length() - 1]))
		return true;
	return false;
}


void deleteSpace(string &s) {
	for (int i = 0; i < s.length(); i++) {
		if (isspace(s[i]))
			s.erase(i,1);
	}
	cout << s;
}

void deleteChar(string& s, char x) {
	string temp;
	for (char ch : s) {
		if (ch == x) {
			if (temp != "") {
				cout << temp << endl;
				temp = "";
			}
		}
		else {
			if (isspace(ch) == false)
				temp += ch;
		}
			
	}
	if (temp != "")
		cout << temp << endl;
}





int main() {
	string s;
	getline(cin, s);
	if (checkNumber(s))
		cout << "Co so" << endl;
	else
		cout << "Khong co so" << endl;
	if (checkSpace(s))
		cout << "Co khoang trang" << endl;
	else
		cout << "Khong co khoang trang" << endl;
	string sTrimmed = s;
	deleteSpace(sTrimmed);
	deleteChar(s, ',');
	return 0;
}