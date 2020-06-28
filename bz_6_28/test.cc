#include<iostream>
#include<stdlib.h>
using namespace std;
typedef struct node
{
	char data;
	struct node *l,*r;
}Tree;
int obj=0;
void init(Tree *&l)//创建树
{
	char ch;
	cin>>ch;
	if(ch=='#') l=NULL;
	else
	{
		l=(Tree *)malloc(sizeof(Tree));
		l->data=ch;
		init(l->l);
		init(l->r);
	}
}
void getnode(Tree *&l)//得到结点
{
	if(l)
	{
		if((l->l==NULL&&l->r!=NULL)||(l->l!=NULL&&l->r==NULL))
		cout<<l->data<<" ";
		obj++;
		if(l->l!=NULL) getnode(l->l);
		if(l->r!=NULL) getnode(l->r);
	}
}
int main()
{
	Tree *l;
	init(l);
	getnode(l);
	cout<<obj;
	return 0;
}
