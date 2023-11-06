//임의의 자연수 n (10~20)을 생성하여 f(1)부터 f(n)까지의 수열을 출력하는 프로그램을 작성
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// 1. 임의의 자연수 n (10~20) 생성 
// 2.  크기가 n인 정수 형태의 배열 생성
// 3.  f(1),f(2) = 1, 2 대입
// 4. for 반복문으로 i+2 번째 인덱스에 i + (i+1) 의 값을 대입하는 것을 n-2번 반복
// 5. for 반복문으로 인덱스에 저장된 정수값 출력 
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
