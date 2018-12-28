/*
 * file 学生健康管理系统
 *
 * author 2leimeng's high school classmate/2leimeng
 * date 2018/12/28
 * compile environment Visual Studio 2017 
 *
 * note 项目属性->配置属性->C/C++ -> SDL检查 否
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

int enterSchoolID(node*L); // 包含判断学号是否重复，若重复，则提示“重新输入”；
int isExist(node*L);
int getChoice(int x, int y);


/*1信息输入*/
node* createdatabase()
{
	node* L, *r, *p;
	int pd = 1, i = 1;
	L = (node *)malloc(sizeof(node));
	L->next = NULL; r = L;
	while (pd == 1)
	{
		system("cls");
		printf("第 %d 个学生的基本信息\n", i);
		p = (node *)malloc(sizeof(node));
		printf("请输入学号\n");
		p->schoolID = enterSchoolID(L);
		printf("请输入姓名\n");
		fflush(stdin);
		scanf("%s", &p->name);
		printf("请输入性别\n");
		fflush(stdin);
		scanf("%s", &p->sex);
		printf("请输入学院\n");
		fflush(stdin);
		scanf("%s", &p->college);
		fflush(stdin);
		printf("请输入专业\n");
		fflush(stdin);
		scanf("%s", &p->major);
		printf("请输入健康情况\n");
		fflush(stdin);
		scanf("%s", &p->health);
		r->next = p;
		r = p;
		i++;
		printf("继续输入信息请按：1 返回菜单请按：0\n");
		scanf("%d", &pd);
	}
	r->next = NULL;
	return L;
}


/*2信息输出*/
void output(node* L)
{
	node *p;
	p = L->next;
	printf("学号\t姓名\t性别\t学院\t专业\t健康情况\n");
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

/*信息输出按性别*/
void outputBySex(node* L)
{
	node *p;
	char sex[10];
	printf("请输入性别：");
	fflush(stdin);
	gets_s(sex);
	p = L->next;
	printf("学号\t姓名\t性别\t学院\t专业\t健康情况\n");
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

/*信息输出按专业*/
void outputByMajor(node* L)
{
	node *p;
	char major[20];
	printf("请输入专业：");
	fflush(stdin);
	gets_s(major);
	p = L->next;
	printf("学号\t姓名\t性别\t学院\t专业\t健康情况\n");
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

/*信息输出按学院*/
void outputByCollege(node* L)
{
	node *p;
	char college[15];
	printf("请输入学院：");
	fflush(stdin);
	gets_s(college);
	p = L->next;
	printf("学号\t姓名\t性别\t学院\t专业\t健康情况\n");
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

/*信息输出按健康状况*/
void outputByHealth(node* L)
{
	node *p;
	char health[5];
	printf("请输入健康状况：");
	fflush(stdin);
	gets_s(health);
	p = L->next;
	printf("学号\t姓名\t性别\t学院\t专业\t健康情况\n");
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

//3.信息添加//
node*  addInformation(node*L)
{
	node*p;
	p = (node *)malloc(sizeof(node));
	printf("请输入新添学生的基本信息\n");
	printf("请输入学号\n");
	p->schoolID = enterSchoolID(L);
	printf("请输入姓名\n");
	scanf("%s", &p->name);
	printf("请输入性别\n");
	scanf("%s", &p->sex);
	printf("请输入学院\n");
	scanf("%s", &p->college);
	printf("请输入专业\n");
	scanf("%s", &p->major);
	printf("请输入健康情况\n");
	scanf("%s", &p->health);
	p->next = L->next;
	L->next = p;
	return L;
}
/*判断学号重复*/
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
			printf("学号重复，请重新输入：");
	}
}
//信息删除//
node* deleteInformation(node*L)
{
	int schoolid;
	node *p, *q;
	p = L;
	printf("请输入删除学生的学号：");
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

//信息修改//
void  modifyInformation(node*L)
{
	node*p;
	int n, m;
	p = L->next;
	printf("请输入需要修改信息的同学的学号：");
	n = isExist(L);
	while (p->schoolID != n)
	{
		p = p->next;
	}
	printf("学号\t姓名\t性别\t学院\t专业\t健康情况\n");
	printf("%d\t", p->schoolID);
	printf("%s\t", p->name);
	printf("%s\t", p->sex);
	printf("%s\t", p->college);
	printf("%s\t", p->major);
	printf("%s\t\n", p->health);
	while (1)
	{

		printf("1:修改姓名\n");
		printf("2:修改性别\n");
		printf("3:修改学院\n");
		printf("4:修改专业\n");
		printf("5:修改健康情况\n");
		printf("0:完成修改\n");
		printf("请选择修改内容:");
		m = getChoice(0, 5);
		switch (m)
		{
		case 0:return;
		case 1: {printf("请输入新的信息：");
			scanf("%s", p->name); break; }
		case 2: {printf("请输入新的信息：");
			scanf("%s", p->sex); break; }
		case 3: {printf("请输入新的信息：");
			scanf("%s", p->college); break; }
		case 4: {printf("请输入新的信息：");
			scanf("%s", p->major); break; }
		case 5: {printf("请输入新的信息：");
			scanf("%s", p->health); break; }
		}
		printf("修改后的信息：\n");
		printf("学号\t姓名\t性别\t学院\t专业\t健康情况\n");
		printf("%d\t", p->schoolID);
		printf("%s\t", p->name);
		printf("%s\t", p->sex);
		printf("%s\t", p->college);
		printf("%s\t", p->major);
		printf("%s\t\n", p->health);
	}
}


/*信息查找按学号*/
void findByID(node*L)
{
	int schoolid, choice;
	node *p;
	printf("请输入学号：");
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
			printf("无此学生");
			printf("1:重新输入\n2:放弃查找");
			choice = getChoice(1, 2);
			switch (choice)
			{
			case 1:break;
			case 2:return;
			}
		}
		else
		{
			printf("你所查找的学生的信息：");
			printf("学号\t姓名\t性别\t学院\t专业\t健康情况\n");
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
/*信息查找按姓名*/
void findByName(node*L)
{
	char na[10];
	node *p;
	printf("请输入要查的学生的姓名：");
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
			printf("你所查找的学生的信息：");
			printf("学号\t姓名\t性别\t学院\t专业\t健康情况\n");
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
			printf("无此学生");
			printf("1:重新输入\n2:放弃查找");
			choice = getChoice(1, 2);
			switch (choice)
			{
			case 1:break;
			case 2:return;
			}
		}
	}
}

/*判断选择*/
int getChoice(int x, int y)
{
	int choice = 0;
	while (scanf("%d", &choice) != 1 || choice<x || choice>y)
	{
		printf("你输入错误（范围%d~%d）", x, y);
		printf("请重新输入：");
	}
	return choice;
}


/*判断学号是否存在*/
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
			printf("无此学生，请重新输入：");
	}
}
/*输出功能选择*/
void   outputFuncSelect(node*L)
{
	int nub;
	while (1)
	{
		system("cls");
		printf("   1. 输出所有信息\n");
		printf("   2. 按性别输出信息\n");
		printf("   3. 按专业输出信息\n");
		printf("   4. 按学院输出信息\n");
		printf("   5. 按健康状况输出信息\n");
		printf("   0. 退出输出系统\n");
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
/*查找功能选择*/
void   findFuncSelect(node*L)
{
	int nub;
	while (1)
	{
		printf("   1. 按学号查找信息\n");
		printf("   2. 按姓名查找信息\n");
		printf("   0. 退出查找系统\n");
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

/*菜单*/
void  menu_show()
{
	printf("	欢迎使用\n");
	printf("  学生健康情况监控管理系统\n");
	printf("===========================\n");
	printf("   1. 学生信息的采集\n");
	printf("   2. 学生信息的添加\n");
	printf("   3. 学生信息的查找\n");
	printf("   4. 学生信息的删除\n");
	printf("   5. 学生信息的修改\n");
	printf("   6. 学生信息的统计\n");
	printf("   0. 退出管理系统\n");
	printf("===========================\n");
	printf("   请选择0-6: ");
}

/*主函数*/
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
		case 0: {printf("谢谢你的使用，再见！\n");
			system("pause");
			exit(0);  // 程序运行结束
			break;
		}
		}
	}
}

