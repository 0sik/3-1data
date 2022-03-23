#include <stdio.h>
typedef struct studentTag {
	char	name[20]; 	// 문자배열로 된 이름
	int		age;	 	// 나이를 나타내는 정수값
	double	gpa;		// 평균 평점을 나타내는 실수값
} student;
double AvgOfGPA(student data[], int num);
int main(void)
{
	double avg;
	student data[10] = {	{ "kim", 20, 4.0 },
							{ "choi", 20, 3.7 },
							{ "park", 20, 4.1 },
							{ "lee", 20, 3.5 },
							{ "jeong", 20, 3.3 },
							{ "song", 20, 3.2 },
							{ "hwang", 20, 3.6 },
							{ "koo", 20, 3.5 },
							{ "na", 20, 3.8 },
							{ "oh", 20, 3.9 }
	};

	avg = AvgOfGPA(data, 10);
	printf("> avg = %lf\n", avg);
	return 0;
}

double AvgOfGPA(student data[], int num)
{
	double result = 0.0;
	// 해당 code를 작성하시오.
	for (int i = 0; i < num; i++) {
		result += data[i].gpa;
	}
	result = result / num;

	return result;
}