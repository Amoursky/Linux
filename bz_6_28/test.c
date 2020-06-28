#include <stdio.h>  
#include <stdlib.h>  
#include <malloc.h>  
	  
#define STACKSIZE 100  
	  
typedef int ElemType;  
typedef struct  
{  
    ElemType stack[STACKSIZE];  
    int top;  
}SeqStack;  
	

	  
	void InitStack(SeqStack *S)//将栈S初始化为空栈  
	{  
	    S->top = 0;  
	}  
	int StackEmpty(SeqStack S)//判断栈是否为空，栈为空返回1，否则返回0  
	{  
	    if(0 == S.top)  
	    {  
	        return 1;  
	    }  
	    else  
	    {  
	        return 0;  
	    }  
	}  
	int GetTop(SeqStack S,ElemType *e)//取栈顶元素，将栈顶元素值返回给e，并返回1表示成功，返回0表示失败  
	{  
	    if(S.top <= 0)  
	    {  
	        printf("栈已经空！\n");  
	        return 0;  
	    }  
	    else  
	    {  
	        *e = S.stack[S.top-1];//取栈顶元素  
	        return 1;  
	    }  
	}  
	int PushStack(SeqStack *S,ElemType e)//进栈操作
		//将元素e进栈，元素进栈成功返回1，否则返回0  
	{  
	    if(S->top >= STACKSIZE-1)  
	    {  
	        printf("栈已满，不能入栈！");  
	        return 0;  
	    }  
	    else  
	    {  
	        S->stack[S->top] = e;  
	        S->top++;  
	        return 1;  
	    }  
	}  
	int PopStack(SeqStack *S,ElemType *e)//出栈操作  
	{  
	    if(S->top <= 0)  
	    {  
	        printf("栈已经没有元素，不能出栈！\n");  
	        return 0;  
	    }  
	    else  
	    {  
	        S->top--;  
	        *e = S->stack[S->top];  
	        return 1;  
	    }  
	}  
		int StackLength(SeqStack S)//返回栈长度  
	{  
	    return S.top;  
	}  
	void ClearStack(SeqStack *S)//清空栈  
	{  
	    S->top = 0;  
	}  
	/*利用栈的定义和基本操作实现*/  
	void Conversion(int N)  
	{  
	    SeqStack S;  
	    int x;  
	    InitStack(&S);  
	    while(N > 0)  
	    {  
	        x = N%8;  
	        PushStack(&S,x);  
	        N /= 8;   
	    }  
	    printf("转换成八进制为：");  
	    while(!StackEmpty(S))  
	    {  
	        PopStack(&S,&x);  
	        printf("%d",x);  
	    }  
	    printf("\n");  
	}  
  
	  
int main(void)  
{  
    int N;  
    printf("请输入需要数制转换的十进制数：");  
    scanf("%d",&N);  
    Conversion(N);  
    return 0;  
}
