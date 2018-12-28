/*
 * file ѧ����������ϵͳ
 *
 * author 2leimeng's high school classmate/2leimeng
 * date 2018/12/28
 * compile environment Visual Studio 2017 
 *
 * note ��Ŀ����->��������->C/C++ -> SDL��� ��
 */
#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include "stdlib.h"
#include"string.h"


typedef struct  student
{
	int schoolID;
	char name[10];
	char sex[10];
	char major[20];
	char college[15];
	char health[10];
	struct student* next;
}node;

int enterSchoolID(node*L); // �����ж�ѧ���Ƿ��ظ������ظ�������ʾ���������롱��
int isExist(node*L);
int getChoice(int x, int y);


/*1��Ϣ����*/
node* createdatabase()
{
	node* L, *r, *p;
	int pd = 1, i = 1;
	L = (node *)malloc(sizeof(node));
	L->next = NULL; r = L;
	while (pd == 1)
	{
		system("cls");
		printf("�� %d ��ѧ���Ļ�����Ϣ\n", i);
		p = (node *)malloc(sizeof(node));
		printf("������ѧ��\n");
		p->schoolID = enterSchoolID(L);
		printf("����������\n");
		fflush(stdin);
		scanf("%s", &p->name);
		printf("�������Ա�\n");
		fflush(stdin);
		scanf("%s", &p->sex);
		printf("������ѧԺ\n");
		fflush(stdin);
		scanf("%s", &p->college);
		fflush(stdin);
		printf("������רҵ\n");
		fflush(stdin);
		scanf("%s", &p->major);
		printf("�����뽡�����\n");
		fflush(stdin);
		scanf("%s", &p->health);
		r->next = p;
		r = p;
		i++;
		printf("����������Ϣ�밴��1 ���ز˵��밴��0\n");
		scanf("%d", &pd);
	}
	r->next = NULL;
	return L;
}


/*2��Ϣ���*/
void output(node* L)
{
	node *p;
	p = L->next;
	printf("ѧ��\t����\t�Ա�\tѧԺ\tרҵ\t�������\n");
	while (p != NULL)
	{
		printf("%d\t", p->schoolID);
		printf("%s\t", p->name);
		printf("%s\t", p->sex);
		printf("%s\t", p->college);
		printf("%s\t", p->major);
		printf("%s\t\n", p->health);
		p = p->next;
	}
}

/*��Ϣ������Ա�*/
void outputBySex(node* L)
{
	node *p;
	char sex[10];
	printf("�������Ա�");
	fflush(stdin);
	gets_s(sex);
	p = L->next;
	printf("ѧ��\t����\t�Ա�\tѧԺ\tרҵ\t�������\n");
	while (p != NULL)
	{
		if (strcmp(sex, p->sex) == 0)
		{
			printf("%d\t", p->schoolID);
			printf("%s\t", p->name);
			printf("%s\t", p->sex);
			printf("%s\t", p->college);
			printf("%s\t", p->major);
			printf("%s\t\n", p->health);
		}
		p = p->next;
	}
}

/*��Ϣ�����רҵ*/
void outputByMajor(node* L)
{
	node *p;
	char major[20];
	printf("������רҵ��");
	fflush(stdin);
	gets_s(major);
	p = L->next;
	printf("ѧ��\t����\t�Ա�\tѧԺ\tרҵ\t�������\n");
	while (p != NULL)
	{
		if (strcmp(major, p->major) == 0)
		{
			printf("%d\t", p->schoolID);
			printf("%s\t", p->name);
			printf("%s\t", p->sex);
			printf("%s\t", p->college);
			printf("%s\t", p->major);
			printf("%s\t\n", p->health);
		}
		p = p->next;
	}
}

/*��Ϣ�����ѧԺ*/
void outputByCollege(node* L)
{
	node *p;
	char college[15];
	printf("������ѧԺ��");
	fflush(stdin);
	gets_s(college);
	p = L->next;
	printf("ѧ��\t����\t�Ա�\tѧԺ\tרҵ\t�������\n");
	while (p != NULL)
	{
		if (strcmp(college, p->college) == 0)
		{
			printf("%d\t", p->schoolID);
			printf("%s\t", p->name);
			printf("%s\t", p->sex);
			printf("%s\t", p->college);
			printf("%s\t", p->major);
			printf("%s\t\n", p->health);
		}
		p = p->next;
	}
}

/*��Ϣ���������״��*/
void outputByHealth(node* L)
{
	node *p;
	char health[5];
	printf("�����뽡��״����");
	fflush(stdin);
	gets_s(health);
	p = L->next;
	printf("ѧ��\t����\t�Ա�\tѧԺ\tרҵ\t�������\n");
	while (p != NULL)
	{
		if (strcmp(health, p->health) == 0)
		{
			printf("%d\t", p->schoolID);
			printf("%s\t", p->name);
			printf("%s\t", p->sex);
			printf("%s\t", p->college);
			printf("%s\t", p->major);
			printf("%s\t\n", p->health);
		}
		p = p->next;
	}
}

//3.��Ϣ���//
node*  addInformation(node*L)
{
	node*p;
	p = (node *)malloc(sizeof(node));
	printf("����������ѧ���Ļ�����Ϣ\n");
	printf("������ѧ��\n");
	p->schoolID = enterSchoolID(L);
	printf("����������\n");
	scanf("%s", &p->name);
	printf("�������Ա�\n");
	scanf("%s", &p->sex);
	printf("������ѧԺ\n");
	scanf("%s", &p->college);
	printf("������רҵ\n");
	scanf("%s", &p->major);
	printf("�����뽡�����\n");
	scanf("%s", &p->health);
	p->next = L->next;
	L->next = p;
	return L;
}
/*�ж�ѧ���ظ�*/
int enterSchoolID(node*L)
{
	node*p;
	int n;
	p = L->next;
	while (1)
	{
		scanf("%d", &n);
		while ((p != NULL) && (p->schoolID != n))
		{
			p = p->next;
		}
		if (p == NULL)
			return n;
		else
			printf("ѧ���ظ������������룺");
	}
}
//��Ϣɾ��//
node* deleteInformation(node*L)
{
	int schoolid;
	node *p, *q;
	p = L;
	printf("������ɾ��ѧ����ѧ�ţ�");
	schoolid = isExist(L);
	while (p->next != NULL)
	{
		q = p->next;
		if (q->schoolID == schoolid)
		{
			p->next = q->next;
			free(q);
			break;
		}
		else
			p = p->next;
	}
	return L;
}

//��Ϣ�޸�//
void  modifyInformation(node*L)
{
	node*p;
	int n, m;
	p = L->next;
	printf("��������Ҫ�޸���Ϣ��ͬѧ��ѧ�ţ�");
	n = isExist(L);
	while (p->schoolID != n)
	{
		p = p->next;
	}
	printf("ѧ��\t����\t�Ա�\tѧԺ\tרҵ\t�������\n");
	printf("%d\t", p->schoolID);
	printf("%s\t", p->name);
	printf("%s\t", p->sex);
	printf("%s\t", p->college);
	printf("%s\t", p->major);
	printf("%s\t\n", p->health);
	while (1)
	{

		printf("1:�޸�����\n");
		printf("2:�޸��Ա�\n");
		printf("3:�޸�ѧԺ\n");
		printf("4:�޸�רҵ\n");
		printf("5:�޸Ľ������\n");
		printf("0:����޸�\n");
		printf("��ѡ���޸�����:");
		m = getChoice(0, 5);
		switch (m)
		{
		case 0:return;
		case 1: {printf("�������µ���Ϣ��");
			scanf("%s", p->name); break; }
		case 2: {printf("�������µ���Ϣ��");
			scanf("%s", p->sex); break; }
		case 3: {printf("�������µ���Ϣ��");
			scanf("%s", p->college); break; }
		case 4: {printf("�������µ���Ϣ��");
			scanf("%s", p->major); break; }
		case 5: {printf("�������µ���Ϣ��");
			scanf("%s", p->health); break; }
		}
		printf("�޸ĺ����Ϣ��\n");
		printf("ѧ��\t����\t�Ա�\tѧԺ\tרҵ\t�������\n");
		printf("%d\t", p->schoolID);
		printf("%s\t", p->name);
		printf("%s\t", p->sex);
		printf("%s\t", p->college);
		printf("%s\t", p->major);
		printf("%s\t\n", p->health);
	}
}


/*��Ϣ���Ұ�ѧ��*/
void findByID(node*L)
{
	int schoolid, choice;
	node *p;
	printf("������ѧ�ţ�");
	while (1)
	{
		p = L->next;
		scanf("%d", &schoolid);
		while ((p != NULL) && (p->schoolID != schoolid))
		{
			p = p->next;
		}
		if (p == NULL)
		{
			printf("�޴�ѧ��");
			printf("1:��������\n2:��������");
			choice = getChoice(1, 2);
			switch (choice)
			{
			case 1:break;
			case 2:return;
			}
		}
		else
		{
			printf("�������ҵ�ѧ������Ϣ��");
			printf("ѧ��\t����\t�Ա�\tѧԺ\tרҵ\t�������\n");
			printf("%d\t", p->schoolID);
			printf("%s\t", p->name);
			printf("%s\t", p->sex);
			printf("%s\t", p->college);
			printf("%s\t", p->major);
			printf("%s\t\n", p->health);
			return;
		}
	}
}
/*��Ϣ���Ұ�����*/
void findByName(node*L)
{
	char na[10];
	node *p;
	printf("������Ҫ���ѧ����������");
	while (1)
	{
		int choice;
		p = L->next;
		fflush(stdin);
		gets_s(na);
		while ((p != NULL) && (strcmp(na, p->name) != 0))
		{
			p = p->next;
		}
		if (p != NULL)
		{
			printf("�������ҵ�ѧ������Ϣ��");
			printf("ѧ��\t����\t�Ա�\tѧԺ\tרҵ\t�������\n");
			printf("%d\t", p->schoolID);
			printf("%s\t", p->name);
			printf("%s\t", p->sex);
			printf("%s\t", p->college);
			printf("%s\t", p->major);
			printf("%s\t\n", p->health);
			return;
		}
		else
		{
			printf("�޴�ѧ��");
			printf("1:��������\n2:��������");
			choice = getChoice(1, 2);
			switch (choice)
			{
			case 1:break;
			case 2:return;
			}
		}
	}
}

/*�ж�ѡ��*/
int getChoice(int x, int y)
{
	int choice = 0;
	while (scanf("%d", &choice) != 1 || choice<x || choice>y)
	{
		printf("��������󣨷�Χ%d~%d��", x, y);
		printf("���������룺");
	}
	return choice;
}


/*�ж�ѧ���Ƿ����*/
int isExist(node*L)
{
	node*p;
	int n;
	while (1)
	{
		p = L->next;
		scanf("%d", &n);
		while ((p != NULL) && (p->schoolID != n))
		{
			p = p->next;
		}
		if (p != NULL)
			return n;
		else
			printf("�޴�ѧ�������������룺");
	}
}
/*�������ѡ��*/
void   outputFuncSelect(node*L)
{
	int nub;
	while (1)
	{
		system("cls");
		printf("   1. ���������Ϣ\n");
		printf("   2. ���Ա������Ϣ\n");
		printf("   3. ��רҵ�����Ϣ\n");
		printf("   4. ��ѧԺ�����Ϣ\n");
		printf("   5. ������״�������Ϣ\n");
		printf("   0. �˳����ϵͳ\n");
		nub = getChoice(0, 5);
		switch (nub)
		{
		case 1: {system("cls");
			output(L);
			system("pause");
			break; }
		case 2: {system("cls");
			outputBySex(L);
			system("pause");
			break; }
		case 3: {system("cls");
			outputByMajor(L);
			system("pause");
			break; }
		case 4: {system("cls");
			outputByCollege(L);
			system("pause");
			break; }
		case 5: {system("cls");
			outputByHealth(L);
			system("pause");
			break; }
		case 0:return;
		}
	}
}
/*���ҹ���ѡ��*/
void   findFuncSelect(node*L)
{
	int nub;
	while (1)
	{
		printf("   1. ��ѧ�Ų�����Ϣ\n");
		printf("   2. ������������Ϣ\n");
		printf("   0. �˳�����ϵͳ\n");
		nub = getChoice(0, 2);
		switch (nub)
		{
		case 1: {system("cls");
			findByID(L);
			break; }
		case 2: {system("cls");
			findByName(L);
			break;
		}
		case 0:return;
		}
	}
}

/*�˵�*/
void  menu_show()
{
	printf("	��ӭʹ��\n");
	printf("  ѧ�����������ع���ϵͳ\n");
	printf("===========================\n");
	printf("   1. ѧ����Ϣ�Ĳɼ�\n");
	printf("   2. ѧ����Ϣ�����\n");
	printf("   3. ѧ����Ϣ�Ĳ���\n");
	printf("   4. ѧ����Ϣ��ɾ��\n");
	printf("   5. ѧ����Ϣ���޸�\n");
	printf("   6. ѧ����Ϣ��ͳ��\n");
	printf("   0. �˳�����ϵͳ\n");
	printf("===========================\n");
	printf("   ��ѡ��0-6: ");
}

/*������*/
void main()
{
	node*L;
	int nub;
	while (1)
	{
		system("cls");
		menu_show();
		nub = getChoice(0, 6);
		switch (nub)
		{
		case 1: {system("cls");
			L = createdatabase();
			break; }
		case 2: {system("cls");
			L = addInformation(L);
			break;
		}
		case 3: {system("cls");
			findFuncSelect(L);
			break;
		}
		case 4: {system("cls");
			L = deleteInformation(L);
			break;
		}
		case 5: {system("cls");
			modifyInformation(L);
			break;
		}
		case 6: {system("cls");
			outputFuncSelect(L);
			break;
		}
		case 0: {printf("лл���ʹ�ã��ټ���\n");
			system("pause");
			exit(0);  // �������н���
			break;
		}
		}
	}
}

