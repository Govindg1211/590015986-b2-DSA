#include <stdio.h>
#include <stdlib.h>
struct student {
    char name[50];
    int age;
    int marks;
};
int main() {
    int n;
    printf("Enter the number of students: ");
    scanf("%d", &n);
    printf("\n");
    struct student arr = (struct student)malloc(n * sizeof(struct student));
    for (int i = 0; i < n; i++) {
        printf("Enter the name of student %d: ", i + 1);
        scanf("%s", arr[i].name);
        printf("Enter the age of student %d: ", i + 1);
        scanf("%d", &arr[i].age);
        printf("Enter the marks of student %d: ", i + 1);
        scanf("%d", &arr[i].marks);
        printf("\n");
    }
    printf("\nOriginal array is: \n");
    for (int i = 0; i < n; i++) {
        printf("Name: %s\n", arr[i].name);
        printf("Age: %d\n", arr[i].age);
        printf("Marks: %d\n", arr[i].marks);
        printf("\n");
    }
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j].marks < arr[j + 1].marks) {
                struct student temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    printf("\nSorted array is: \n");
    for (int i = 0; i < n; i++) {
        printf("Name: %s\n", arr[i].name);
        printf("Age: %d\n", arr[i].age);
        printf("Marks: %d\n", arr[i].marks);
        printf("\n");
    }
    printf("Student with highest marks is: \n");
    if (n > 0) { 
        printf("Name: %s\n", arr[0].name);
        printf("Age: %d\n", arr[0].age);
        printf("Marks: %d\n", arr[0].marks);
    }
    free(arr);
    return 0;
}