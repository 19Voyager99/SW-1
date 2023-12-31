#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define NUM 21
void selectionSort(int arr[]);
int binary_search(int arr[], int target, int *cnt);
int main(void){
	int i,j, input,index, cnt=0;
	int randNum[NUM];
	
	srand((unsigned)time(NULL));
	
	for(i=0;i<NUM;i++){
		randNum[i]= rand()% 40+ 61;
		for(j=0;j<i;j++){ // 중복 수 배제 
			if(randNum[i] == randNum[j]) i--; // 생성된 난수와 배열에 저장되어 있는 값 비교해서 같으면 다시 난수 생성   
		}
	}
	
	selectionSort(randNum); // 오름차순 정렬하기
	
	for(i=0;i<NUM;i++) printf("%d ", randNum[i]);
	
	printf("\nInput NUM: ");
	scanf("%d", &input); 
	index=binary_search(randNum, input, &cnt);
	
	if(index!=-1) printf("Index: %d, Number of Comparison: %d", index, cnt);
	else printf("NOT FOUND, Number of Comparison: %d", cnt);
	
	return 0;
}

void selectionSort(int arr[]){
	int i, j, temp;
	for(i=0;i<NUM-1;i++){
		for(j=i+1;j<NUM;j++){
			if(arr[i]>arr[j]){
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
}

int binary_search(int arr[], int target, int *cnt){
	int low=0, high=NUM-1;
	int mid;
	
	while(low<=high){
		(*cnt)++; // cnt 포인터의 주소에 있는 값 증가, 괄호 풀면 포인터를 증가시키는 것이므로 주의  
		mid=(low+high)/2;
		if(target==arr[mid]) return mid; // 탐색 성공, 위치 반환 
		else if(target<arr[mid]) high= mid-1; // 위쪽 버리고 다시 탐색
		else low= mid+1; //아래 버리고 다시 탐색 
	}
	return -1; //NOT FOUND
}
