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
	int i, res= 1; // 19line�� ���� res�� main �Լ��� ���� res�� ������ scope�� lifetime�� �ٸ��� ������ �̸��� ���Ƶ� �ȴ�. 
	for(i=1;i<=n;i++){
		res = res * i;
	}
	return res;
}
