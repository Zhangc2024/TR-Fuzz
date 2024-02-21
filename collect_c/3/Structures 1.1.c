#include <stdio.h>
#include <string.h>
struct student{
	int idNumber;
	char FirstName[30];
	char LastName[30];
	char gender;
	int age;
	double GPA;
};

main(){	
	struct student aStudent={4015,"MEHMET","TAPUR",'M',20,3.22};
	struct student *aStudentPtr=&aStudent;
	
	
	printf("DOT OPERATOR(aStudent.type)\n\n");

	printf("idNumber is %d\n",aStudent.idNumber);
	printf("idNumber is %s\n",aStudent.FirstName);
	printf("idNumber is %s\n",aStudent.LastName);
	printf("idNumber is %c\n",aStudent.gender);
	printf("idNumber is %d\n",aStudent.age);
	printf("idNumber is %lf\n\n\n\n",(aStudent).GPA);
	
	
	printf("DOT OPERATOR((*aStudentPtr).type)\n\n");
	
	printf("idNumber is %d\n",(*aStudentPtr).idNumber);
	printf("idNumber is %s\n",(*aStudentPtr).FirstName);
	printf("idNumber is %s\n",(*aStudentPtr).LastName);
	printf("idNumber is %c\n",(*aStudentPtr).gender);
	printf("idNumber is %d\n",(*aStudentPtr).age);
	printf("idNumber is %lf\n\n\n\n",(*aStudentPtr).GPA);
	
	
	printf("ARROW OPERATOR(aStudentPtr->type)\n\n");
	
	printf("idNumber is %d\n",aStudentPtr->idNumber);
	printf("idNumber is %s\n",aStudentPtr->FirstName);
	printf("idNumber is %s\n",aStudentPtr->LastName);
	printf("idNumber is %c\n",aStudentPtr->gender);
	printf("idNumber is %d\n",aStudentPtr->age);
	printf("idNumber is %lf\n\n\n",aStudentPtr->GPA);
	
	
	
}
