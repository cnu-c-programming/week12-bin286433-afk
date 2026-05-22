#include <stdio.h>

int main(int argc, const char* argv[]){
    if(argc < 2){
        return 0;
    }
    FILE* fp = fopen(argv[1], "r");

    if(fp==NULL) return 0;

    int counts[26] = {0};
    int ch;

    while((ch=fgets(fp))!=EOF){
        if(ch>='a'&& ch<='z'){
            counts[ch-'a']++;
        }
    }

    for(int i = 0; i<26; i++){
        printf("%c: %d\n", 'a'+i, counts[i]);
    }

    fclose(fp);
    return 0;
}
