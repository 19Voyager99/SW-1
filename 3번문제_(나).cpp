#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define NUM 21
void selectionSort(int arr[]);
int binary_search(int arr[], int target, int low, int high, int *cnt);
int main(void){
	int i,j, input,index, cnt=0;
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
	index=binary_search(randNum, input, 0, NUM-1, &cnt);
	
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

int binary_search(int arr[], int target, int low, int high, int *cnt){
	int mid;
	(*cnt)++; // cnt �������� �ּҿ� �ִ� �� ����, ��ȣ Ǯ�� �����͸� ������Ű�� ���̹Ƿ� ����
	
	if(low > high) return -1; // Ž�� ����, ��ȯ Ż�� 
	mid = (low+high)/2;
	
	if(target==arr[mid]) return mid; // Ž�� ����, ��ȯ Ż�� 
	else if(arr[mid]> target) return binary_search(arr, target, low, mid-1, *cnt);
	else return binary_search(arr, target, *cnt, mid+1, high, *cnt);
}
