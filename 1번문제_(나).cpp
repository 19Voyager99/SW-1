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
	if(n==1) return 1; // 팩토리얼의 마지막에서 1을 곱하고  종료  
	else return n*factorial(n-1); // 1만큼 낮아진 값을 넣어서 다시 호출 
}
