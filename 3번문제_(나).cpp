#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define NUM 21
void selectionSort(int arr[]);
int binary_search(int arr[], int target, int *index);
int main(void){
	int i,j, input,index, cntR;
	int cnt=0;
	int randNum[NUM];
	
	srand((unsigned)time(NULL));
	
	for(i=0;i<NUM;i++){
		randNum[i]= rand()% 40+ 61;
		for(j=0;j<i;j++){ // �ߺ� �� ���� 
			if(randNum[i] == randNum[j]) i--; // ������ ������ �迭�� ����Ǿ� �ִ� �� ���ؼ� ������ �ٽ� ���� ����   
		}
	}
	
	selectionSort(randNum); // �������� �����ϱ� 
	
	for(i=0;i<NUM;i++) printf("%d ", randNum[i]);
	
	printf("\nInput NUM: ");
	scanf("%d", &input); 
	cntR=binary_search(randNum, input, &index);
	
	if(index!=-1) printf("Index: %d, Number of Comparison: %d", index, cntR);
	else printf("NOT FOUND, Number of Comparison: %d", cntR);
	
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

int binary_search(int arr[], int target, int *index){
	static int cnt=0, low=0, high=0;
	static int mid;
		
	if(low==0&&high==0){
		low=0;
		high=NUM-1;
	}
	
	if(low > high){
		*index=-1;
		return cnt;
	} // Ž�� ����, ��ȯ Ż��
	cnt++; 
	mid = (low+high) /2;
	if(target==arr[mid]){
		*index=mid;
		return cnt; // Ž�� ����, ��ȯ Ż��
	} 
	else if(target > arr[mid]) low = mid + 1;
	else  high = mid - 1;
	
	return binary_search(arr,target,index);
}
