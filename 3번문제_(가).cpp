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
		for(j=0;j<i;j++){ // �ߺ� �� ���� 
			if(randNum[i] == randNum[j]) i--; // ������ ������ �迭�� ����Ǿ� �ִ� �� ���ؼ� ������ �ٽ� ���� ����   
		}
	}
	
	selectionSort(randNum); // �������� �����ϱ�
	
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
		(*cnt)++; // cnt �������� �ּҿ� �ִ� �� ����, ��ȣ Ǯ�� �����͸� ������Ű�� ���̹Ƿ� ����  
		mid=(low+high)/2;
		if(target==arr[mid]) return mid; // Ž�� ����, ��ġ ��ȯ 
		else if(target<arr[mid]) high= mid-1; // ���� ������ �ٽ� Ž��
		else low= mid+1; //�Ʒ� ������ �ٽ� Ž�� 
	}
	return -1; //NOT FOUND
}
