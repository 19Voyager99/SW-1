//������ �ڿ��� n (10~20)�� �����Ͽ� f(1)���� f(n)������ ������ ����ϴ� ���α׷��� �ۼ�
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// 1. ������ �ڿ��� n (10~20) ���� 
// 2.  ũ�Ⱑ n�� ���� ������ �迭 ����
// 3.  f(1),f(2) = 1, 2 ����
// 4. for �ݺ������� i+2 ��° �ε����� i + (i+1) �� ���� �����ϴ� ���� n-2�� �ݺ�
// 5. for �ݺ������� �ε����� ����� ������ ��� 
int main(void){
	int n, i;
	srand((unsigned)time(NULL));
	
	n=rand()%11+10;
	printf("n = %d\n",n);
	
	int fibonacci[n];
	
	fibonacci[0]=1;
	fibonacci[1]=2;
	
	for(i=0;i<n-2;i++){
		fibonacci[i+2] = fibonacci[i] + fibonacci[i+1];
	}
	
	for(i=0;i<n;i++){
		printf("f(%d)= %d\n", i+1,fibonacci[i]);
	}
	
	return 0;
}
