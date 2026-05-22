#include <stdio.h>

int main(int argc, const char* argv[]){
    const char* filename = "numbers.txt";

    FILE* fp = fopen(filename, "r");
    
    if(fp==NULL){
        return 0;
    }

    char buffer[64];
    int sum = 0;
    int num = 0;

    while(fscanf(fp, "%s", buffer)!=EOF){
        if(sscanf(buffer, "%d", &num)==1){
            sum+=num;
        }
        else{
            fprintf(stderr, "invalid input %s\n", buffer);
        }
    }

    printf("sum: %d\n", sum);
    fclose(fp);
    return 0;
}
