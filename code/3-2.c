#include <stdio.h>

int main(int argc, const char* argv[]) {
    
    if (argc < 2)
        return 0;
    
    const char* filename = argv[1];
    char buffer[10] = {0};

    FILE* fp = fopen(filename, "r");
    if(fp==NULL){
        return 0;
    }

    fscanf(fp, "%9s", buffer);
    //fgets(buffer, sizeof(buffer), fp);
    fclose(fp);

    printf("%s\n", buffer);


    return 0;
}

