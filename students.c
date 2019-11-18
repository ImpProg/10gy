#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Student {
    char neptun[10];
    char name[30];
    int age;
    int grades[3];
} Student;

double getAvg(int* grades, size_t count) {
    double sum = 0;
    for (int i = 0; i < count; ++i) {
        sum += grades[i];
    }

    return count == 0 ? 0 : sum / count;
}

Student* findBest(Student* students, size_t count) {
    int best = 0;
    double maxAvg = getAvg(students[0].grades, 3);
    for (int i = 1; i < count; ++i) {
        if (getAvg(students[i].grades, 3) > maxAvg) {
            best = i;
            maxAvg = getAvg(students[i].grades, 3);
        }
    }

    return students + best;
}

Student* readStudents(char* fileName, size_t* count) {
    FILE* file = fopen(fileName, "r");
    if (!file) {
        return NULL;
    }

    fscanf(file, "%d\n", count);
    Student* students = malloc(*count * sizeof(Student));

    for (int i = 0; i < *count; ++i) {
        char buffer[100];
        fscanf(file, "%[^\n]", buffer);
        fgetc(file);
        
        strcpy(students[i].neptun, strtok(buffer, ":"));
        strcpy(students[i].name, strtok(NULL, ":"));
        students[i].age = atoi(strtok(NULL, ":"));
        students[i].grades[0] = atoi(strtok(NULL, ","));
        students[i].grades[1] = atoi(strtok(NULL, ","));
        students[i].grades[2] = atoi(strtok(NULL, ","));
    }
    
    fclose(file);
    return students;
}

int main(int argc, char** argv) {
    if (argc != 2) {
        printf("Missing parameter\n");
        return -1;
    }

    size_t count;
    Student* students = readStudents(argv[1], &count);
    for (int i = 0; i < count; ++i) {
        printf("%s (%s), %d\n", students[i].name, students[i].neptun, students[i].age);
    }

    Student* best = findBest(students, count);
    printf("Best student: %s, avg: %1.2f\n", best->name, getAvg(best->grades, 3));

    free(students);
    return 0;
}