#include<stdio.h>
#include<stdlib.h>

#define ERROR 0

char sym;  //用于临时存储文件中读出的单个字符
FILE *fp;  //读取文件的指针

//非终结符定义的方法
void e();
void g();
void t();
void s();
void f();
//读取文件中的下一个字符
void advance();
int main()
{
	
	if((fp=fopen("输入文件.txt","r"))==NULL)//读取文件内容，并返回文件指针，该指针指向文件的第一个字符
	{   
		fprintf(stderr,"error opening.\n");
		exit(1);
	}
	e();

	return 0;
}
//对应产生式（1）E->TG
void e()
{
	advance();
	t();
	g();
	if(sym=='#')
	{
		printf("输入的为合法的字符串\n");
	}
	else
	{
		printf("非法字符串");
	}
	
}
//对应产生式（2）G->+TG （3）G->ε  空 ：不做任何处理

void g()
{
	if(sym =='+')
	{
		printf("+");
		advance();
		t();
		g();
	}
}
//对应产生式  （4）T->FS
void t()
{
	f();
	s();
}
// 对应产生式（5）S->*FS （6）S->ε
void s()
{
	if(sym=='*')
	{
		printf("*");
		advance();
		f();
		s();
	}
}
//对应产生式（7）F->(E)  （8）F->i

void f()
{
	if(sym=='(')
	{
		advance();
		e();
		if(sym==')')
			advance();
		else 
		{
			printf("非法字符串");
			exit(ERROR);
		}
	}
	else if(sym=='i') 
	{
		printf("i");
		advance();
	}
	else
	{
		printf("非法字符串");
		exit(ERROR);
	}
}
void advance()
{
	sym=fgetc(fp);// 从数据流中区下一个字符	
}
