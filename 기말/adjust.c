

/* �л� �ڷ�ó�� - ���� */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "oh.h"

int compareName(const void *a, const void *b) //�̸���
{
	return strcmp(((STUDENT *)a)->name, ((STUDENT *)b)->name);
}

int compareStudentNum(const void *a, const void *b) //�й���
{
	return (((STUDENT *)a)->id)-(((STUDENT *)b)->id);
}

int compareScore(const void *a, const void *b) //������
{
	return (((STUDENT *)a)->score)-(((STUDENT *)b)->score);
}

void student_adjust()
{
	
	FILE *file;

	int count=0;
	int nu1=0; //ui���� �Է¹��� ����
	int k=0;
	
	file=fopen("student.db", "r");

	while(!feof(file)) //database�� �л��ڷ� �ޱ�
	{
		fscanf(file, "%s %ld %f", database[count].name, &database[count].id, &database[count].score);

		count++; //count=�л���
		if(count>=100) //�л����� �ִ� 100��
			count=100;
	}
	fclose(file);

	printf("************\n* 1.�̸��� *\n* 2.�й��� *\n* 3.������ *\n*  4.�ڷ�  *\n************\n");
	scanf("%d", &nu1);

	if(nu1==1 || nu1==2 || nu1==3) //4�� �� ������ �Է½� ����� �ʿ�x
		printf("\n\n*����*\n�л����� 100���� �Ѿ ��� 100������� ����մϴ�.\n\n");
	
	if(nu1==1) //����-�̸���
	{
		qsort(database,count,sizeof(STUDENT),compareName);

		printf("���̸��� ���Ģ�\n");
		printf("------------------------------");

		k=0;
		while(k!=count)
		{
			printf("\n%s %ld %f\n", database[k].name, database[k].id, database[k].score);
			k++;
		}

		printf("------------------------------\n\n");

		userIntro(); //�ٽ� ó������

	}

	else if(nu1==2) //����-�й���
	{

		qsort(database,count,sizeof(STUDENT),compareStudentNum);

		printf("���й��� ���Ģ�\n");
		printf("------------------------------");

		k=0;
		while(k!=count)
		{
			printf("\n%s %ld %f\n", database[k].name, database[k].id, database[k].score);
			k++;
		}

		printf("------------------------------\n\n");

		userIntro(); //�ٽ� ó������

	}

	else if(nu1==3) //����-������
	{

		qsort(database,count,sizeof(STUDENT),compareScore);

		printf("�Ѽ����� ���Ģ�\n"); 
		printf("------------------------------");

		k=0;
		while(k!=count)
		{
			printf("\n%s %ld %f\n", database[k].name, database[k].id, database[k].score);
			k++;
		}

		printf("------------------------------\n\n");

		userIntro(); //�ٽ� ó������

	}

	else if(nu1==4) //����-�ڷΰ���
	{
		userIntro();
	}

	else
		printf("�ùٸ��� ���� ���� �Է��Ͽ����ϴ�.\n\n");

}