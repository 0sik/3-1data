#include<stdio.h>
#include<string.h>

typedef struct studentTag {
	char name[10];
	int age;
	double gpa; // Æò±Õ ÆòÁ¡
}student;

//typedef struct studentTag student;
int main() {
	
	struct studentTag st[2] = { {"kim",20,3.5},{"park",20,3.8} };
	for (int i = 0; i < 2; i++) {
		printf("st[%d]:%s,%d,%lf\n", i, st[i].name, st[i].age, st[i].gpa);
	}
	
	//student s2={"park",20,3.8};
	//s1.age = 20;
	//s1.gpa = 3.5;
	//strcpy(s1.name,"kim");
	//printf("s1:%s, %d, %lf\n", s1.name, s1.age, s1.gpa);
	//printf("s2:%s, %d, %lf\n", s2.name, s2.age, s2.gpa);
	return 0;
}