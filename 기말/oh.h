
void userIntro(); //����� �������̽� �Լ�

void student_adjust(); //����

void student_add(); //�߰�

void student_change(); //����

void student_delete(); //����

typedef struct {
	char name[20];
	long id;
	float score;
} STUDENT;

STUDENT database[101]; //�л������� ���� �迭

int compareName(const void *a, const void *b); //�̸���
int compareStudentNum(const void *a, const void *b); //�й���
int compareScore(const void *a, const void *b); //������
