/*
Determine if a string can be segmented into valid dictionary words.
*/

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
	bool wb[100];
	memset(wb, 0, sizeof(wb));

	//check the substr and add it into the dynamic array.

	for (int i = 1; i <= size; i++) {
		if (wb[i] == false && dictContains(str.substr(0, i))) {
			wb[i] = true;
		}
		if (wb[i] == true) {
			if (i == size)
				return true;
			for (int j = i + 1; j <= size; j++) {
				if (wb[j]==false && dictContains(str.substr(i, j - i)))
					wb[j] = true;
				//coming to last character.
				if (j == size && wb[j] == true)
					return true;
			}
		}
	}
	return false;
}

int main()
{
	word_break("ilikesamsung") ? cout << "Yes"<<endl : cout << "No"<<endl;
	word_break("iiiiiiii") ? cout << "Yes" << endl : cout << "No" << endl;
	word_break("") ? cout << "Yes" << endl : cout << "No" << endl;
	word_break("ilikelikeimangoiii") ? cout << "Yes" << endl : cout << "No" << endl;
	word_break("samsungandmango") ? cout << "Yes" << endl : cout << "No" << endl;
	word_break("samsungandmangok") ? cout << "Yes" << endl : cout << "No" << endl;
	return 0;
}

