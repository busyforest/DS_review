#include "string.h"
#include <stdio.h>

int main(){
    char* string = "abcdabca\0";
    char* partern = "dabca\0";
    printf("%d\n", KMP(string, partern));
    return 0;
}