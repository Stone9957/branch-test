#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>


/*�̾߱� �̾��
//���ڿ� ���� '\0'
//strcat ���ڿ� ���̱�
int main()
{
	char novel[800] = { 0 };
	char str_in[80];

	while (1)
	{
		printf("���ڿ��� �Է��ϼ��� :");
		gets_s(str_in);
		if (strcmp(str_in, "��") == 0) break;
		strcat_s(novel, str_in);
		strcat_s(novel, " ");
		printf("��������� �ٰŸ� : ");
		puts(novel);
		puts("\n");
	}
	return 0;
}
*/

//���� ����ó��
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

struct student {
	char sNum[10];
	char major[20];
	char name[20];
	int C;
	int JAVA;
	int DB;
	int total;
	double avg;
	int rank;
	char grade;

};
int main() {
	struct student s[SIZE];
	int i, u;
	int aTotal = 0;
	double aAvg;
	FILE* fp;
	fp = fopen("a.txt", "r");
	if (fp == NULL) {
		printf("file open fail\n");
		exit(1);
	}
	for (i = 0; i < SIZE; i++) {
		fscanf(fp, "%s %s %s %d %d %d", &s[i].major, &s[i].sNum, &s[i].name, &s[i].C, &s[i].JAVA, &s[i].DB);
		s[i].total = s[i].C + s[i].JAVA + s[i].DB;
		s[i].avg = s[i].total / 3.0;
		aTotal += s[i].total;

		if (s[i].avg >= 90)
			s[i].grade = 'A';
		else if (s[i].avg >= 80)
			s[i].grade = 'B';
		else if (s[i].avg >= 70)
			s[i].grade = 'C';
		else if (s[i].avg >= 60)
			s[i].grade = 'D';
		else
			s[i].grade = 'F';
	}
	fclose(fp);
	aAvg = aTotal / (SIZE * 3.0);
	for (i = 0; i < SIZE; i++) {
		s[i].rank = 1;
		for (u = 1; u < SIZE; u++) {
			if (s[i].total < s[u].total)
				s[i].rank++;
		}

	}
	fp = fopen("b.txt", "w");
	if (fp == NULL) {
		printf("file write fail\n");
		exit(1);
	}

	fprintf(fp, "�а��й�����CJAVADB��������������\n");
	fprintf(fp, "=======================================================================================\n");
	for (i = 0; i < SIZE; i++) {
		fprintf(fp, "%3s%6s %6s %9d %8d %6d %6d%.1lf %6c %6d\n", s[i].major, s[i].sNum, s[i].name, s[i].C, s[i].JAVA, s[i].DB, s[i].total, s[i].avg, s[i].grade, s[i].rank);
	}
	fprintf(fp, "=======================================================================================\n");
	fprintf(fp, "�а���ü ����:%d\n", aTotal);
	fprintf(fp, "�а���ü ���:%.2lf", aAvg);
	fclose(fp);
	printf("���� ��� �Ϸ�\n");
	return 0;
}

