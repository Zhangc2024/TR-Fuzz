#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SIZE 5
struct student{
	int idNumber;
	char firstName[30];
	char lastName[30];
	char gender;
	int age;
	double GPA;
};
void printStudent(struct student p);
double calculateAvgGPA(double x,double y);
void determineGender(char g,char *n);
void printStudentArray(struct student *pArray);
int countMaleStudent(struct student *pArray);
void sortArray(struct student *studentArray,int param);
main(){
	struct student aStudent={2037,"MEHMET","TAPUR",'M',20,3.22};
	struct student aStudent2;
	aStudent2.idNumber=1302;
	strcpy(aStudent2.firstName,"TPR");
	strcpy(aStudent2.lastName,"Eng");
	aStudent2.gender='F';
	aStudent2.age=19;
	aStudent2.GPA=3.40;
	printStudent(aStudent);
	printStudent(aStudent2);
	
	double GPAAvg=calculateAvgGPA(aStudent.GPA,aStudent2.GPA);
	printf("Average of GPA of two student is %lf\n\n",GPAAvg);
	determineGender(aStudent.gender,aStudent.firstName);
	determineGender(aStudent2.gender,aStudent2.firstName);
	struct student studentArray[SIZE];
	int i;
	studentArray[0]=aStudent;
	studentArray[1]=aStudent2;
	
	for(i=2;i<SIZE;i++){
		studentArray[i].idNumber=2000+i;
		printf("Enter name and surname\n");
		scanf("%s%s",studentArray[i].firstName,studentArray[i].lastName);
		printf("Enter Gender\n");
		scanf("%s",&studentArray[i].gender);
		studentArray[i].age=18+rand()%18;
		printf("Enter GPA\n");
		scanf("%lf",&studentArray[i].GPA);
	}
	
	printStudentArray(studentArray);
	
	printf("There are %d male student\n\n",countMaleStudent(studentArray));
	sortArray(studentArray,2);
	printStudentArray(studentArray);
	
	sortArray(studentArray,4);
	printStudentArray(studentArray);
	
}
void printStudent(struct student p){
	printf("%d\t",p.idNumber);
	printf("%s\t",p.firstName);
	printf("%s\t",p.lastName);
	printf("%c\t",p.gender);
	printf("%d\t",p.age);
	printf("%lf\n\n",p.GPA);
	
}
double calculateAvgGPA(double x,double y){
	return (x+y)/2;
}
void determineGender(char g,char *n){
	if(g=='M')
		printf("The student %s is male\n",n);
	else
		printf("The student %s is female\n",n);

}
void printStudentArray(struct student *pArray){
	int i;
	for(i=0;i<SIZE;i++){
		printf("%d\t",pArray[i].idNumber);
		printf("%s\t",pArray[i].firstName);
		printf("%s\t",pArray[i].lastName);
		printf("%c\t",pArray[i].gender);
		printf("%d\t",pArray[i].age);
		printf("%lf\n",pArray[i].GPA);
	}
	printf("-------------------------------------------------------------------------------------------\n\n");
}
int countMaleStudent(struct student *pArray){
	int cnt=0;
	int i;
	for(i=0;i<SIZE;i++){
		if(pArray[i].gender=='M')
			cnt++;
	}
	return cnt;
	printf("****%d****",cnt);
}
void sortArray(struct student *studentArray,int param){
	int i,pass;
	switch(param){
		case 1:
			for(pass=0;pass<SIZE-1;pass++){
				for(i=0;i<SIZE-1;i++){
					if(studentArray[i].idNumber>studentArray[i+1].idNumber){
						struct student hold=studentArray[i];
						studentArray[i]=studentArray[i+1];
						studentArray[i+1]=hold;
					}
				}
			}
		break;	
		case 2:
			for(pass=0;pass<SIZE-1;pass++){
				for(i=0;i<SIZE-1;i++){
					if(studentArray[i].gender>studentArray[i+1].gender){
						struct student hold=studentArray[i];
						studentArray[i]=studentArray[i+1];
						studentArray[i+1]=hold;
					}
				}
			}
		break;		
		case 3:
			for(pass=0;pass<SIZE-1;pass++){
				for(i=0;i<SIZE-1;i++){
					if(studentArray[i].age>studentArray[i+1].age){
						struct student hold=studentArray[i];
						studentArray[i]=studentArray[i+1];
						studentArray[i+1]=hold;
					}
				}
			}
		break;
		case 4:
			for(pass=0;pass<SIZE-1;pass++){
				for(i=0;i<SIZE-1;i++){
					if(studentArray[i].GPA>studentArray[i+1].GPA){
						struct student hold=studentArray[i];
						studentArray[i]=studentArray[i+1];
						studentArray[i+1]=hold;
					}
				}
			}
		break;								
	}
	
}


