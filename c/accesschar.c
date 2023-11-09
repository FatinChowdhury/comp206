#include <stdio.h>
int main(void){
        char str[] = "abcd";
        str[2] = 'z';
        *(str+1) = 'y';
        printf("%s\n", str);
}
