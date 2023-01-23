#include <stdio.h>

#include <ctype.h>

int main(void) {

	FILE *fp = NULL;

	char buffer[500];

	int line_number=1;

	fp = fopen("Word.txt", "r");

	if( fp == NULL ) {

		printf("파일 열기 실패\n");

		return 0;

	}

	while(fgets(buffer, 500, fp)!=NULL) {

		printf("%d: %s\n", line_number, buffer);

		line_number++;

	}

	fclose(fp);

	return 0;

}