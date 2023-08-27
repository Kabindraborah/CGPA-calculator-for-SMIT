#include <stdio.h>

double gradeToPoints(char grade) {
    switch (grade) {
        case 'S':
        case 's':
            return 10.0;
        case 'A':
        case 'a':
            return 9.0;
        case 'B':
        case 'b':
            return 8.0;
        case 'C':
        case 'c':
            return 7.0;
        case 'D':
        case 'd':
            return 6.0;
        case 'E':
        case 'e':
            return 5.0;
        case 'F':
        case 'f':
            return 0.0;
        default:
            return -1.0; 
    }
}

int main() {
    int numCourses;
    printf("Enter the number of courses: ");
    scanf("%d", &numCourses);

    double totalCredits = 0.0;
    double totalGradePoints = 0.0;

    for (int i = 0; i < numCourses; i++) {
        int credit;
        char grade;

        printf("\nEnter credit of the course %d: ", i + 1);
        scanf("%d", &credit);

        printf("Enter grade for course %d: ", i + 1);
        scanf(" %c", &grade);

        double gradePoints = gradeToPoints(grade);

        if (gradePoints == -1.0) {
            printf("Invalid grade entered for course %d. Please enter a valid grade.\n", i + 1);
            i--; 
            continue;
        }

        totalCredits += credit;
        totalGradePoints += credit * gradePoints;
    }

    if (totalCredits > 0) {
        double cgpa = totalGradePoints / totalCredits;
        printf("\nYour CGPA is: %.2lf\n", cgpa);

        if (cgpa < 5.0) {
            printf("You have failed in this semester.\n");
        }
    } else {
        printf("No courses entered.\n");
    }

    return 0;
}
