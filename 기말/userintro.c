
/*20143079 ������
�⸻������Ʈ - ����� �������̽�*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "oh.h"

void userIntro()
{
	int first;

	printf("**********\n* 1.���� *\n* 2.�߰� *\n* 3.���� *\n* 4.���� *\n**********\n���ϴ� ��ȣ�� �Է��ϼ���.\n");
	scanf("%d", &first);

	if(first==1) //����
	{
		student_adjust();
	}

	else if(first==2) //�߰�
	{
		student_add();
	}

	else if(first==3) //����
	{
		student_change();
	}

	else if(first==4) //����
	{
		student_delete();
	}

	else
	{
		printf("\n�ùٸ��� ���� ���� �Է��Ͽ����ϴ�.\n");
		printf("���α׷��� �����մϴ�.\n\n");
	}
}