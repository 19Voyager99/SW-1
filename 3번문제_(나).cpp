#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define NUM 21
void selectionSort(int arr[]);
int binary_search(int arr[], int target, int low, int high);
int main(void){
	int i,j, input,index;
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
	index=binary_search(randNum, input, 0, NUM-1);
	
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

int binary_search(int arr[], int target, int low, int high){
	int mid;
	static int cnt=0;
	cnt++;
	if(low > high) return -1; // 탐색 실패, 순환 탈출 
	mid = (low+high)/2;
	
	if(target==arr[mid]) return mid; // 탐색 성공, 순환 탈출 
	else if(arr[mid]> target) return binary_search(arr, target, low, mid-1, cnt);
	else return binary_search(arr, target, mid+1, high, cnt); // 47Line에서 함수 선언할때와는 다르게 함수를 호출하는것이므로 포인터 * 를 붙이면 안되는 것으로 보임. 
}
