#include<iostream>
#include<string>

using namespace std;

void permutate(string src, string op) {
	if (src.size() == 0) {
		cout << op << endl;
		return;
	}
	for (int i = 0; i < src.size(); i++) {
		permutate(src.substr(1), op + src[0]);
		cout << "substring"<<src.substr(1) << endl;
		cout << "src[0]" << src[0] << endl;
		rotate(src.begin(), src.begin() + 1, src.end());
	}
}

int main() {
	string str = "ABC";
	permutate(str, "");

	return 0;
}