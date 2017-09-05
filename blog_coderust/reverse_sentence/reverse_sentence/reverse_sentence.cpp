//Reverse order of words in a sentence.
#include<iostream>

using namespace std;

void reverse_words(char *str) {
	char *word_begin = str;
	char *word_bound = str;

	while (*word_bound) {
		word_bound++;
		//cout << "word begin: " << word_begin << "word bound :" << word_bound << endl;
		if (*word_bound == '\0') {
			reverse(word_begin, word_bound-1);
		}
		else if (*word_bound == ' ') {
			reverse(word_begin, word_bound-1);
			word_begin = word_bound + 1;
		}
	}

	reverse(str, word_bound - 1);

}

void reverse(char *begin, char *end) {

	char temp;

	while (begin <= end) {
		temp = *begin;
		*begin++ = *end;
		*end-- = temp;
	}
	
}

int main() {
	char s[] = "i like this program very much";
	char *temp = s;

	reverse_words(s);
	printf("%s", s);
	getchar();

	return 0;
}

