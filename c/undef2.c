#include <stdio.h>
int main(void){
        // char *str1 = "abcd";
        char str2[] = "hello";

        char *p;
        p = str2;
        // str1[0] = 'a'; // Wrong
        p[0] = 'a'; // this is fine
        printf("%s\n", p);
        printf("%s\n", str2);
}
