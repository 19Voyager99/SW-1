#include <stdio.h>

int factorial(int n);

int main(void){
	int n, res;
	
	printf("Input N(1~10): ");
	scanf("%d", &n);
	
	res = factorial(n);
	
	printf("Res: %d", res);
	
	return 0;
}

int factorial(int n){
	if(n==1) return 1; // ���丮���� ���������� 1�� ���ϰ�  ����  
	else return n*factorial(n-1); // 1��ŭ ������ ���� �־ �ٽ� ȣ�� 
}
