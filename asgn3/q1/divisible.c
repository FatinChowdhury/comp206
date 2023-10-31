#include <stdio.h>
// 1. asks for 3 ints
// 2. checks if (1st int)|(2nd & 3rd ints)
// 3. the 3 ints are in increasing order
//
// Program must:
// -1 return 0; if all conditions satisfied
// prints Divisible & Increasing to screen
//
// -2 return 1; if 2 == false && 3 == true
// prints Not Divisible & Increasing to screen
//
// -3 return 2; if 2 == true && 3 == false
// prints Divisible & Not Increasing
//
// -4 return 3; if 2 == false && 3 == false
// prints Not Divisible && Not Increasing
//
// program terminates after doing this one time.
//
int main(){
        int num1, num2, num3;

        printf("Please input three numbers: ");
        scanf("%d %d %d", &num1, &num2, &num3);

        if (num1 != 0 && num2 % num1 == 0 && num3 % num1 == 0){

                if (num1 < num2 && num2 < num3){
                        puts("Divisible & Increasing");
                                return 0;
                }
                else {
                        puts("Divisible & Not Increasing");
                        return 2;
                }
        }
        else {
                if (num1 < num2 && num2 < num3){
                        puts("Not Divisible & Increasing");
                        return 1;
                }
                else {
                        puts("Not Divisible & Not Increasing");
                        return 3;
                }
        }

        return 0;
}
