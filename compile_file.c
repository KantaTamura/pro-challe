#include "main.h"

void solve_and_compile(Data* data) {
    FILE* solve;

    if ((solve = fopen("./result/solve.c", "w")) == NULL) {
        printf("Can't open file: %s\f\r", "./result/solve.c");
        exit_pro();
    }

    system("vim ./result/solve.c");

    system("gcc ./result/solve.c -o ./result/result 2> ./result/error.txt");

    char exe[64] = "./result/result > ./result/result.txt < ";
    strcat(exe, data->input_file);
    system(exe);
}
