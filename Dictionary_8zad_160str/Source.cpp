#include<iostream>
using namespace std;
#define MAX_LENGHT 30
#define MAX_SIZE 40
class Dictionary {
	char** wordFirstLanguage;
	char** wordSecondLanguage;
	int firstCurrent;
	int secondCurrent;
public:
	Dictionary();
	~Dictionary();
	void addWord(char*,char*);
	void deleteWord(char*);
	char* searchForWord(char*);
	char* translateSentence(char*);
};
Dictionary::Dictionary() {
	wordFirstLanguage = new char*[MAX_SIZE];
	wordSecondLanguage = new char*[MAX_SIZE];
	for (int i = 0; i < MAX_SIZE; i++) {
		wordFirstLanguage[i] = new char[MAX_LENGHT];
		wordSecondLanguage[i] = new char[MAX_LENGHT];
	}
	firstCurrent = 0;
	secondCurrent = 0;
}
Dictionary::~Dictionary() {
	delete[] wordFirstLanguage;
	delete[] wordSecondLanguage;
}
void Dictionary::addWord(char* w1,char* w2) {
	if ((strlen(w1) < 29) && (strlen(w2) < 29)) {
		strcpy(wordFirstLanguage[firstCurrent++], w1);
		strcpy(wordSecondLanguage[secondCurrent++], w2);
	}
	else {
		cout << "Symbols are out of bounds!\n";
	}
}
void Dictionary::deleteWord(char* wd) {
	for (int i = 0; i < firstCurrent; i++) {
		if (strcmp(wordFirstLanguage[i], wd) == 0) {
			strcpy(wordFirstLanguage[i], "");
			strcpy(wordSecondLanguage[i], "");
			return;
		}
	}
	for (int i = 0; i < secondCurrent; i++) {
		if (strcmp(wordSecondLanguage[i], wd) == 0) {
			strcpy(wordFirstLanguage[i], "");
			strcpy(wordSecondLanguage[i], "");
			return;
		}
	} 
}
char* Dictionary::searchForWord(char* wd) {
	for (int i = 0; i < firstCurrent; i++) {
		if (strcmp(wordFirstLanguage[i], wd) == 0) {
			return wordSecondLanguage[i];
		}
	}
	for (int i = 0; i < secondCurrent; i++) {
		if (strcmp(wordSecondLanguage[i], wd) == 0) {
			return wordFirstLanguage[i];
		}
	}
}
char* Dictionary::translateSentence(char* sentence) {
	char* temporaryHolder = new char[strlen(sentence)+1];
	char** allWords = new char*[MAX_SIZE];
	char* result = new char[strlen(sentence) + 1];
	char* currentWord;
	strcpy(temporaryHolder, sentence);
	currentWord = strtok(temporaryHolder, " ,.!?");
	int maxWords = 0;
	bool first = true;
	bool second = true;
	for (int i = 0; i < MAX_SIZE; i++) {
		allWords[i] = new char[MAX_LENGHT];
	}
	for (int i = 0; currentWord != NULL; i++) {
		strcpy(allWords[i], currentWord);
		maxWords++;
		currentWord = strtok(NULL, " ,.!?");
	}
	for (int i = 0; i < maxWords; i++) {
		if (first) {
			for (int k = 0; k < firstCurrent; k++) {
				if (strcmp(allWords[i], wordFirstLanguage[k]) == 0) {
					if (i == 0) {
						strcpy(result, wordSecondLanguage[k]);
						strcat(result, " ");
						continue;
					}
					strcat(result, wordSecondLanguage[k]);
					strcat(result, " ");
					second=false;
				}
			}
		}
		if (second) {
			for (int k = 0; k < secondCurrent; k++) {
				if (strcmp(allWords[i], wordSecondLanguage[k]) == 0) {
					if (i == 0) {
						strcpy(result, wordFirstLanguage[k]);
						strcat(result, " ");
						continue;
					}
					strcat(result, wordFirstLanguage[k]);
					strcat(result, " ");
					first = false;
				}
			}
		}
	}
	delete[] allWords;
	delete[] temporaryHolder;
	return result;
}
int main() {
	Dictionary obj;
	obj.addWord("hello", "zdravei");
	obj.addWord("this", "tova");
	obj.addWord("fun", "zabavno");
	obj.addWord("is", "e");
	cout<<obj.translateSentence("hello this is fun")<<endl;
	return 0;
}