

/* �л� �ڷ�ó�� - ���� */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "oh.h"

void student_delete()
{
	
	FILE *file;
	
	int i=0;
	int j=0;
	int count=0;
	long input_id=0;

	file=fopen("student.db", "r");

	while(!feof(file)) //database�� �л��ڷ� �ޱ�
	{
		fscanf(file, "%s %ld %f", database[count].name, &database[count].id, &database[count].score);

		count++; //count=�л���
		if(count>=100) //�л����� �ִ� 100��
			count=100;
	}
	fclose(file);

	file=fopen("student.db", "w");


	//������ ������ �ٽ� ������
	printf("�ѱ��� �����͢�\n");
	printf("------------------------------");

	i=0;
	while(i<count)
	{
		printf("\n%s %ld %f\n", database[i].name, database[i].id, database[i].score);
		i++;
	}

	printf("------------------------------\n\n");


	printf("������ �й��� �Է��ϼ���.\n");
	scanf("%ld", &input_id);

	
	i=0;
	while(i<count) //count=�л���
	{
		if(database[i].id==input_id) //���� �й��� �Է��� �й��� ������
		{
			count--; //�л���-1
			break;
		}
		i++;
	}

	for(j=i; j<count+1; j++) //j�̻���� ��ĭ�� ���� �÷��� ���ľ�
	{
		strcpy(database[j].name,database[j+1].name);
		database[j].id=database[j+1].id;
		database[j].score=database[j+1].score;
	}

	i=0;
	while(i!=count) //������ ������ student.db�� �ٽ�����
	{
		fprintf(file, "%s %ld %f", database[i].name, database[i].id, database[i].score);
		i++;
	}
	fclose(file);


	///���///
	printf("\n\n�Ѻ���� �����͢�\n");
	printf("(�߸� �������� ��� �ٽ� ó������ �������ּ���.)\n");
	printf("\n\n*����*\n�л����� 100���� �Ѿ ��� 100������� ����մϴ�.\n\n");
	printf("------------------------------");

	i=0;
	while(i!=count)
	{
		printf("\n%s %ld %f\n", database[i].name, database[i].id, database[i].score);
		i++;
	}

	printf("------------------------------\n\n");

	userIntro(); //�ٽ� ó������

}
