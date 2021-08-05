#define MAXNAME 1000
#define MAXSTUDENTS 100

#include <string.h>
#include <stdlib.h>

// packing?  What's the optimal way to structure this?
typedef struct _student_t {
	int  zid;            // 7-digit number
	char name[MAXNAME];  // names are stored *within* the struct
	int  prog;           // 4-digit number
	int  favnum;         // favourite number
} Student;

// return -ve if a < b, +ve if a > b, 0 if a == b
int stuCmp(const void *a, const void *b) {
	Student studentA = *(Student*)a;
	Student studentB = *(Student*)b;

	int cmp = strcmp(studentA.name, studentB.name);
	if (cmp == 0) {
		return studentB.zid - studentA.zid;
	} else {
		return cmp;
	}
}
 
int main(int argc, char *argv[]) {
	Student students[MAXSTUDENTS];

	// read stdin line-by-line into students[]

	// sort the students[] array
	qsort(students, MAXSTUDENTS, sizeof(Student), stuCmp);

	// print the contents of the students[] array
}
