#include <stdio.h>
int main(void){
        char *p = "abcd";
        p[0] = 'd'; // will print out Segmentation fault (you tried to edit a value that you dont have the right to edit}
