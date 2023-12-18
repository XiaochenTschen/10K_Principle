#include<stdio.h>
 
#pragma pack(2)
 
typedef struct{
	char f2;
	int f3;
}ST3;  //ST3各成员变量2字节对齐
 
#pragma pack()

//more_aligned_int 16字节对齐，sizeof=4 
typedef int more_aligned_int __attribute__((aligned(16)));
//more_aligned_int__1 16字节对齐，sizeof=4....但是 more_aligned_int 代表的意思 ！= more_aligned_int_1
typedef int __attribute__((aligned(16))) more_aligned_int_1;
 
typedef struct{
	int a;
	char b;
} __attribute__((aligned(64))) ST2;//ST2起始地址64字节对齐，sizeof(ST2)=64
 
typedef struct{
	int a;
	char b;
} ST1 __attribute__((aligned(64)));//ST1起始地址64字节对齐,sizeof(ST1)=8，所以不能定义ST1结构体数组(数组要求地址连续)
 
///
int main()
{
	//ST1 st1[3];//error: alignment of array elements is greater than element size
	ST1 st1;	
	ST2 st2;
	ST3 st3;
	printf("sizeof st1 =%u,sizeof st2 =%u,sizeof st3=%u,sizeof int_1=%d\n",sizeof(st1),sizeof(st2),sizeof(st3),sizeof(more_aligned_int_1));//8,64,6(重新定义结构体按新方式对齐),4
	return 0;
}