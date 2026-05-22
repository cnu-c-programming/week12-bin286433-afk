#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct config{
    char InputFileName[64];
    int Options;
    char SectionName[64];
    unsigned long long Address;
} Config;

void config_parser(Config* config_ptr){
    FILE* fp = fopen("config.txt", "r");
    if(fp==NULL){
        return;
    }

    char buffer[256];

    while(fgets(buffer, sizeof(buffer), fp)!= NULL){
        if(sscanf(buffer, " Options = %d", &config_ptr->Options)==1){
            continue;
        }
        if(sscanf(buffer, " InputFileName = %s", &config_ptr->InputFileName)==1){
            continue;
        }
        if(sscanf(buffer, " SectionName = %s", &config_ptr->SectionName)==1){
            continue;
        }
        char addr_str[64];
        if(sscanf(buffer, " Address = %s", addr_str)==1){
            config_ptr->Address = strtoull(addr_str, NULL, 0);
        }
    }

    fclose(fp);
    // fscanf(fp, "Options=%d\n", &config_ptr->Options);
    // fscanf(fp, "InputFileName=%s\n", config_ptr->InputFileName);
    // fscanf(fp, "SectionName=%s\n", config_ptr->SectionName);
    // fscanf(fp, "Address=%lli\n", &config_ptr->Address);
    

}

int main(int argc, const char* argv[]){
    Config config;
    config_parser(&config);

    printf("config: %s %d %s %llu\n",
        config.InputFileName,
        config.Options,
        config.SectionName,
        config.Address);
    return 0;    
}
