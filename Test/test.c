#include <stdio.h>
#include <stdlib.h>
// #include <unistd.h>


int main(void){
    system("clear");
    char s [104];
    int line = 0;
    FILE *wd;
    wd = fopen("Wedomosti.dat", "rb");
    while (fgets(s, 104, wd) != NULL){
        line++;
    }
    printf("\n%d\n", line);
    return 0;
}
