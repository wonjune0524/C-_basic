/*

// 1-1		=> O

#include <stdio.h>

int main(void)
{
	int score[5] = { 1,2,3,4,5 };

	for (int i = 0; i < 5; i++)
	{
		printf("%d\n", *(score + i));		// 주소를 해당 데이터로 변환해주는 기능
	}

	return 0;
}

*/

/*

// 1-2		=> X

#include <stdio.h>

int main(void)
{
	double a = 100;
	double* pd = &a;
	
	printf("%f\n", *pd);
	printf("%f\n", *(pd + 1));
	printf("%p\n", pd);
	printf("%p", (pd + 1));

	return 0;
}

*/

/*

// 1-3		=>		O

#include <stdio.h>

int main(void)
{
	int arr[5] = { 1,2,3,4,5 };
	int* pa = arr;

	for (int i = 0; i < 5; i++)
	{
		printf("%d\n", pa[i]);		// 배열 포인터라서 앞에 * 안붙인듯?
		printf("%d\n\n", *(pa + i));
	}
	
	return 0;
}

*/

/*

// 1-4		=> O

#include <stdio.h>

void Func1(int arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("%d\n", arr[i]);
	}
}

void Func2(int *arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("%d\n", arr[i]);
	}
}

int main(void)
{
	int arrrr[] = { 1,2,3,4,5 };
	int sizeee = sizeof(arrrr) / 4;

	Func1(arrrr, sizeee);
	printf("\n\n");
	Func2(arrrr, sizeee);

	return 0;
}

*/

/*

// 1-5		=> X

#include <stdio.h>

int main(void)
{
	int score[5] = { 1,2,3,4,5 };

	for (int i = 0; i < 5; i++)
	{
		printf("%d\n", (score + 1));
	}

	return 0;
}

*/

// 2-1		=> double*

// 2-2		=> 포인터 배열

// 2-3		=> 2차원 배열

// 2-4		=> 함수 포인터

// 2-5		=> %p

// 3-1		=> (다)

// 3-2		=> (나)

// 3-3		=> (나)

// 3-4		=> (다)

// 3-5		=> (라)

// 4-1		=> int* a, * b,* c;

// 4-2		=> double *parr[3] = {&a, &b, &c};

// 4-3		=> void (*pf)(double, double) = &pow;

/*

// 5		=> 18

#include <stdio.h> 

void sub1(int* p, int n)
{
	*p += n;
}
void sub2(int* p, int n)
{
	*p -= n;
}
void sub3(int* p, int n)
{
	*p *= n;
}
void sub4(int* p, int n)
{
	*p /= n;
}

int main(void)
{
	void sub1(int*, int);
	void sub2(int*, int);
	void sub3(int*, int);
	void sub4(int*, int);
	void (*pf[4])(int*, int) = { sub1, sub2, sub3, sub4 };
	int data = 100;

	pf[1](&data, 10);
	pf[3](&data, 5);
	printf("%d\n", data);

	return 0;
}

*/

