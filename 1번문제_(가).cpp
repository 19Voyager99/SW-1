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
	int i, res= 1; // 19line의 변수 res와 main 함수의 변수 res는 변수의 scope와 lifetime이 다르기 때문에 이름이 같아도 된다. 
	for(i=1;i<=n;i++){
		res = res * i;
	}
	return res;
}
