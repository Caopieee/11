#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include<string>
#include<iostream>

using namespace std;

int max(int* A, int N)
{
	int m = A[0];

	for (int i = 1; i < N; i++)
		if (A[i] > m)
			m = A[i];

	return m;
}

int main() {
	char word[50][26];
	int n = 0;
	int i, j;
	int m = 50;

	FILE* f = fopen("input.txt", "r");
	if (f == NULL) {
		printf("file open error\n");
		return 0;


	}
	while (fscanf(f, "%s", word[n]) != EOF) {
		n++;
	}

	fclose(f);

	int count[50] = { 0 };
	for (i = 0; i < n; i++) {
		int len = strlen(word[i]);
		for (j = 0; j < n; j++) {
			if (i == j) continue;
			if (strncmp(word[i], word[j], len) == 0) {
				count[i]++;
			}


		}


	}

	if (max(count,m)==0){ 
		printf("no\n");
		return 0;
	}
	

	

	

	int important=-1;
	int importantindex = 0;
	for (i = 0; i < n; i++) {
		if (count[i] > important) {
			important = count[i];
			importantindex = i;
		}

	}

	int maxlen = 0;
	int maxlenindex = 0;
	for (i = 0; i < n; i++) {
		if ((count[i] > 0) && (strlen(word[i]) > maxlen)) {
			maxlen = strlen(word[i]);
			maxlenindex = i;
		}


	}

	cout << "most long :" << word[maxlenindex] << endl;
	cout << "most important:" << word[importantindex] << endl;









	return 0;
}