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
main(){	
	struct student aStudent={2037,"MEHMET","TAPUR",'M',20,3.22};
	struct student aStudent2;
	aStudent2.idNumber=1302;
	strcpy(aStudent2.firstName,"TPR");
	strcpy(aStudent2.lastName,"Eng");
	aStudent2.gender='F';
	aStudent2.age=19;
	aStudent2.GPA=3.40;	
	printf("idNumber member is %d\n",aStudent.idNumber);
	printf("fistName member is %s\n",aStudent.firstName);
	printf("lastName member is %s\n",aStudent.lastName);
	printf("gender member is %c\n",aStudent.gender);
	printf("age member is %d\n",aStudent.age);
	printf("GPA member is %lf\n\n",aStudent.GPA);
	
	printf("idNumber member is %d\n",aStudent2.idNumber);
	printf("fistName member is %s\n",aStudent2.firstName);
	printf("lastName member is %s\n",aStudent2.lastName);
	printf("gender member is %c\n",aStudent2.gender);
	printf("age member is %d\n",aStudent2.age);
	printf("GPA member is %lf\n\n",aStudent2.GPA);
	
	double GPAAvg=(aStudent.GPA+aStudent2.GPA)/2;
	printf("Average of GPA of two student is %lf\n",GPAAvg);
	
	printf("Compare first names: %s and %s is %d\n",aStudent.firstName,aStudent2.firstName,strcmp(aStudent.firstName,aStudent2.firstName));
	printf("Compare last names: %s and %s is %d\n",aStudent.lastName,aStudent2.lastName,strcmp(aStudent.lastName,aStudent2.lastName));
	if(aStudent.gender=='M')
		printf("The student %s is male\n",aStudent.firstName);
	else
		printf("The student %s is male\n",aStudent.lastName);
			
	if(aStudent2.gender=='M')
		printf("The student %s is male\n",aStudent2.firstName);
	else
		printf("The student %s is male\n",aStudent2.lastName);		
		
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
	for(i=0;i<SIZE;i++){
		printf("%d\t",studentArray[i].idNumber);
		printf("%s\t",studentArray[i].firstName);
		printf("%s\t",studentArray[i].lastName);
		printf("%c\t",studentArray[i].gender);
		printf("%d\t",studentArray[i].age);
		printf("%lf\n",studentArray[i].GPA);
		printf("-----------------------------------------------------------------------------------\n\n");
	}
	double ageAvg=0;
	for(i=0;i<SIZE;i++)
		ageAvg=ageAvg+studentArray[i].age;
	printf("\naverage of students is %lf\n",ageAvg/5);
	int countMale=0;	
	for(i=0;i<SIZE;i++){
		if(studentArray[i].gender=='M')
			countMale++;
	}
	printf("There are %d male students\n",countMale);
	int pass=0;
	for(pass=0;pass<SIZE-1;pass++){
		for(i=0;i<SIZE-1;i++){
			if(studentArray[i].GPA>studentArray[i+1].GPA){
				struct student hold=studentArray[i];
				studentArray[i]=studentArray[i+1];
				studentArray[i+1]=hold;
			}
		}
	}
	for(i=0;i<SIZE;i++){
		printf("%d\t",studentArray[i].idNumber);
		printf("%s\t",studentArray[i].firstName);
		printf("%s\t",studentArray[i].lastName);
		printf("%c\t",studentArray[i].gender);
		printf("%d\t",studentArray[i].age);
		printf("%lf\n",studentArray[i].GPA);
		printf("-----------------------------------------------------------------------------------\n\n");
	}	
	struct student *studentPtr;
	studentPtr=&aStudent2;
	printf("\nidNumber member is %d\n",studentPtr->idNumber);
	printf("fistName member is %s\n",studentPtr->firstName);
	printf("lastName member is %s\n",studentPtr->lastName);
	printf("gender member is %c\n",studentPtr->gender);
	printf("age member is %d\n",studentPtr->age);
	printf("GPA member is %lf\n\n",studentPtr->GPA);
		
	studentPtr=studentArray;
	for(pass=0;pass<SIZE-1;pass++){
		for(i=0;i<SIZE-1;i++){
			if((studentPtr+i)->age>(studentPtr+i+1)->age){
				struct student hold=studentArray[i];
				studentArray[i]=studentArray[i+1];
				studentArray[i+1]=hold;
			}
		}
	}
	for(i=0;i<SIZE;i++){
		printf("%d\t",(studentPtr+i)->idNumber);
		printf("%s\t",(studentPtr+i)->firstName);
		printf("%s\t",(studentPtr+i)->lastName);
		printf("%c\t",(studentPtr+i)->gender);
		printf("%d\t",(studentPtr+i)->age);
		printf("%lf\n",(studentPtr+i)->GPA);
		printf("-----------------------------------------------------------------------------------\n\n");
	}	
	
}
