/* 5명 학생의 이름(알파벳 1자)과 각 학생의 5번의 학점(A,B,C,D,F)을 한 학생씩 읽어 최대학점과 최소학점(중복학점 존재) 2개로만 (예: A, A, B, B, F: A와 F가 해당) 다음과 같이 평점을 계산하여 석차순으로(동일 석차 존재 가능: 예 1 1 3등 ) 각 학생의 석차, 이름 및 평균 평점과 전체 학생의 평균 평점을 출력하는 프로그램을 작성
 A(4.5) B(3.5) C(2.5) D(1.5) F(0)
 출력 예시: 1: S 4.00 2: K 4.00 3: H 3.58 4: M 3.33 5: l 3.01 */
#include<stdio.h>
#define NUM 5
#define SCORENUM 5
//1. 반복문으로 학생 이름 입력받고 -> 학점을 입력받아 배열에 입력하는 것을 5번 반복 
//2.  버블 정렬/ 선택 정렬로 배열을 내림차순으로 정렬
//3. 0번 인덱스와 4번 인덱스를 읽어서 switch문으로 학점을 평점으로 변환한 뒤 평균 계산
//4. 학생들의 평균들을 입력한 배열을 다시 정렬하면서 이름을 입력한 배열을 그에 맞춰서 정렬? 
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
		// sortChar 함수: 입력받은 학점들을 내림차순으로 정렬  
		sortChar(grade);
		// readGrade 함수: 배열에 입력된 학점을 읽어내어 실수 형태의 점수로 변환 
		min = readGrade(grade, SCORENUM-1);
		max = readGrade(grade, 0);
		avg[i]= (min+max) / 2;
	}
	// sortBoth 함수: 평균 배열의 값 내림차순으로 배열하기 + 학생들 이름 석차대로 배열하기 
	sortBoth(name, avg);
	// 석차 계산  
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
