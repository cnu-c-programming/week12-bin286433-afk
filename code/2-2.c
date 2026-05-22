#include <stdio.h>
#include <string.h>

typedef struct student {
    char name[64];
    int score;
} Student;

int main(int argc, const char* argv[]){
    FILE* fp = fopen("student.txt", "r");
    int count=0;
    Student students[64];
    int total_score =0;
    while(fscanf(fp, "%s %d", students[count].name, &students[count].score) != EOF){
        total_score += students[count].score;
        count++;
    }

    int max =0;
    float avg = 0;

    for(int i=0; i<count; i++){
        max = students[i].score;
        if(students[i].score<students[i+1].score){
            max = students[i+1].score;
        }
    }
    avg = total_score/count;

    printf("max: %d\n", max);
    printf("avg: %.2f\n", avg);

    fclose(fp);
    return 0;

}
