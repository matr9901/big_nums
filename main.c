#include <stdio.h>

int main() {
    char* str;// = malloc (100000*sizeof(char));
    scanf("%ms", str);
    printf("Hello, World!\n");
    printf("%s\n",str);
    return 0;
}