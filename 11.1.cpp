#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
#include<stdio.h>
#include <io.h>
#include <fcntl.h>
#include <fcntl.h>


using namespace std;
int main() {
	int a;
	char str[100];

	cin >> a;
	cout << a << endl;

	scanf("%d", &a);
	printf("printf=%d", a);

	getchar();
	fgets(str,100,stdin);
	puts(str);

	FILE* f = fopen("text.txt", "w");
	if (f == NULL) {
		printf("file open error\n");
		return 0;
	}

	fprintf(f, "hello world\n");
	fclose(f);
	f = fopen("text.txt", "r");
	char A[100];
	while (fgets(A, 100, f)!= NULL) {
		printf("%s", A);
	}
	fclose(f);

	int fd = _open("text2.txt", O_CREAT | O_WRONLY, 0644);
	_write(fd, "hello linux IO\n", 20);
	_close(fd);

	char B[100];
	fd = _open("text2.txt", O_RDONLY);
	_read(fd, B, 20);
	B[20] = '\0';
	printf("read():%s\n", B);
	_close(fd);










	return 0;
}