/* 5�� �л��� �̸�(���ĺ� 1��)�� �� �л��� 5���� ����(A,B,C,D,F)�� �� �л��� �о� �ִ������� �ּ�����(�ߺ����� ����) 2���θ� (��: A, A, B, B, F: A�� F�� �ش�) ������ ���� ������ ����Ͽ� ����������(���� ���� ���� ����: �� 1 1 3�� ) �� �л��� ����, �̸� �� ��� ������ ��ü �л��� ��� ������ ����ϴ� ���α׷��� �ۼ�
 A(4.5) B(3.5) C(2.5) D(1.5) F(0)
 ��� ����: 1: S 4.00 2: K 4.00 3: H 3.58 4: M 3.33 5: l 3.01 */
#include<stdio.h>
#define NUM 5
#define SCORENUM 5
//1. �ݺ������� �л� �̸� �Է¹ް� -> ������ �Է¹޾� �迭�� �Է��ϴ� ���� 5�� �ݺ� 
//2.  ���� ����/ ���� ���ķ� �迭�� ������������ ����
//3. 0�� �ε����� 4�� �ε����� �о switch������ ������ �������� ��ȯ�� �� ��� ���
//4. �л����� ��յ��� �Է��� �迭�� �ٽ� �����ϸ鼭 �̸��� �Է��� �迭�� �׿� ���缭 ����? 
void sortChar(char grade[]);
void sortBoth(char name[], float avg[]); 
float readGrade(char grade[], int i);

int main(void){
	int i, j, rank[5]={1,1,1,1,1};
	float avg[NUM], min, max;
	char name[SCORENUM+1], grade[SCORENUM+1];
	
	for(i=0;i<NUM;i++){
		printf("Insert Name: ");
		scanf(" %c",&name[i]);

		for(j=0;j<SCORENUM;j++){
			printf("Insert Grade(%d): ",j+1);
			scanf(" %c",&grade[j]);
		}
		// sortChar �Լ�: �Է¹��� �������� ������������ ����  
		sortChar(grade);
		// readGrade �Լ�: �迭�� �Էµ� ������ �о�� �Ǽ� ������ ������ ��ȯ 
		min = readGrade(grade, SCORENUM-1);
		max = readGrade(grade, 0);
		avg[i]= (min+max) / 2;
	}
	// sortBoth �Լ�: ��� �迭�� �� ������������ �迭�ϱ� + �л��� �̸� ������� �迭�ϱ� 
	sortBoth(name, avg);
	// ���� ���  
	for(i=0;i<NUM;i++){
		for(j=0;j<NUM;j++){
			if(avg[i]>avg[j]){
				rank[j]++;
			} 
		}
	}
	
	for(i=0;i<NUM;i++){
		printf("%d: %c %.2f\t", rank[i],name[i],avg[i]);
	}
	return 0;
}

void sortChar(char grade[]){
	int cnt, cnt2;
	char temp;
	for(cnt=0;cnt<SCORENUM-1;cnt++){
		 	for(cnt2=cnt+1;cnt2<SCORENUM;cnt2++){
		 		if(grade[cnt] < grade[cnt2]){
		 			temp = grade[cnt];
		 			grade[cnt] = grade[cnt2];
		 			grade[cnt2] = temp;
				 }
			 }
		 }
}

void sortBoth(char name[], float avg[]){
	int i, j, tempf;
	char temp;
	for(i=0;i<NUM-1;i++){
		for(j=i+1;j<NUM;j++){
			if(avg[i]<avg[j]){
				tempf = avg[i];
				avg[i] = avg[j];
				avg[j] = tempf;
				temp = name[i];
				name[i] = name[j];
				name[j] = temp;
			}
		}
	}
}

float readGrade(char grade[], int i){
	float score;
	switch(grade[i]){
			case 'A' : score = 4.5; break;
			case 'B' : score = 3.5; break;
			case 'C' : score = 2.5; break;
			case 'D' : score = 1.5; break;
			case 'F' : score = 0; break;
		}
	return score;
}
