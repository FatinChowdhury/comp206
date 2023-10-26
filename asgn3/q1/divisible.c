#include <stdio.h>
int main(int argc, int *argv[]){
        puts("Please enter three numbers: ");
        scanf("%d", argv);

        for (int i=0; i<3; i++){
                if (argv[1] % argv[0] == 0 && argv[2] % argv[0] == 0){

                        if (argv[0] < argv[1] && argv[1] < argv[2]){
                                puts("Divisible & Increasing");
                                return 0;
                        }
                        else {
                                puts("Divisible & Not Increasing");
                                return 2;
                        }
                }
                else if (argv[1] % argv[0] != 0 || argv[2] % argv[0] != 0){
                        if (argv[0] < argv[1] && argv[1] < argv[2]){
                                puts("Not Divisible & Increasing");
                                return 1;
                        }
                        else {
                                puts("Not Divisible & Not Increasing");
                                return 3;
                        }
        }
}
