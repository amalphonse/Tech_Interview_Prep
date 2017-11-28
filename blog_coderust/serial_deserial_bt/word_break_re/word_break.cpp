#include<iostream>

using namespace std;

int dictContains(string word) {
	string dict[] = { "mobile","samsung","sam","sung",
		"man","mango","icecream","and",
		"go","i","like","ice","cream" };

	int size = sizeof(dict) / sizeof(dict[0]);
	for (int i = 0; i < size; i++) {
		if (dict[i].compare(word) == 0)
			return true;

	}
	return false;
}

bool word_break(string str) {
	int size = str.size();
	if (size == 0)
		return true;
	for (int i = 0; i < size; i++) {
		if (dictContains(str.substr(0, i)) &&
			(word_break(str.substr(i, size - i))))
			return true;
	}
	return false;
}

int main()
{
	word_break("ilikesamsung") ? cout << "Yes" << endl : cout << "No" << endl;
	word_break("iiiiiiii") ? cout << "Yes" << endl : cout << "No" << endl;
	word_break("") ? cout << "Yes" << endl : cout << "No" << endl;
	word_break("ilikelikeimangoiii") ? cout << "Yes" << endl : cout << "No" << endl;
	word_break("samsungandmango") ? cout << "Yes" << endl : cout << "No" << endl;
	word_break("samsungandmangok") ? cout << "Yes" << endl : cout << "No" << endl;
	return 0;
}