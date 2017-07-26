#include<iostream>
#include<string>


//Question 1.5 from crack the code.

using namespace std;

bool one_away(string str1, string str2) {
	bool found_diff = false;
	int index_small = 0, index_large = 0;

	if ((str1.length() - str2.length()) > 1)
		return false;

	string str_s = str1.length() < str2.length() ? str1 : str2;
	string str_l = str1.length() < str2.length() ? str2 : str1;

	while (index_small < str_s.length() && index_large < str_l.length()) {
		if (str_s[index_small] != str_l[index_large]) {
			if (found_diff)
				return false;
			found_diff = true;
			if (str_s.length() == str_l.length())
				index_small++;
		}
		else
			index_small++;
		index_large++;
	}
	return true;
}

int main() {

	string s1 = "pales";
	string s2 = "bale";
	cout << one_away(s1, s2) << endl;

	return 0;
}
