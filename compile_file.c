#include "main.h"

void open_solve_fp(Data* data) {
    data->c_start = time(NULL);
    if ((data->solve_fp = fopen("./result/solve.c", "w")) == NULL) {
        printf("Can't open file: %s\f\r", "./result/solve.c");
        exit_pro();
    }
}

void solve_and_compile(Data* data) {
    while (1) {
        system("vim ./result/solve.c");

        system("gcc ./result/solve.c -o ./result/result 2> ./result/error.txt");

        FILE* error;
        if ((error = fopen("./result/error.txt", "r")) == NULL) {
            printf("Can't open file: %s\f\r", "./result/solve.c");
            exit_pro();
        }
        if (fgetc(error) != EOF) {
            fseek(error, 0L, SEEK_SET);
            print_retry(data, error);
            fclose(error);
        }
        else {
            break;
        }
    }

    char exe[64] = "./result/result > ./result/result.txt < ";
    strcat(exe, data->input_file);
    system(exe);
}

void retry_with_error(Data* data) {

}

void compare_file(Data* data) {
    FILE* answer;

    if ((answer = fopen("./result/result.txt", "r")) == NULL) {
        printf("Can't open file: %s\f\r", "./result/result.txt");
        exit_pro();
    }

    char answer_buf[256], result_buf[256];
    data->result = 1;
    while (1) {
        if (fgets(result_buf, 256, data->result_fp) == NULL) break;
        if (fgets(answer_buf, 256, answer) == NULL) break;
        if (strcmp(answer_buf, result_buf) != 0) {
            data->result = 0;
            break;
        }
    }
    fseek(data->result_fp, 0L, SEEK_SET);
    fclose(answer);
}

void print_result(Data* data) {
    if (data->result == 1) {
        data->c_end = time(NULL);
        system("clear");
        print(data);
        printf("\f\r");
        printf("\x1b[43mSuccess!!\x1b[m\f\r");
        printf("%ld秒で完成しました!!\f\r", data->c_end - data->c_start);
    }
    else {
        print_retry_failure(data);
        solve_and_compile(data);
        compare_file(data);
        print_result(data);
    }
}

void print_retry(Data* data, FILE* error) {
    char arrow_data[4] = ">  ";
    char retry_data[4][16] = {
        "Retry",
        "No, Quit program",
    };
    int retry_id = 0;

    while (1) {
        system("clear");
        print(data);
        printf("\f\r");
        printf("Error Code:\f\r\f\r");
        char buf[256];
        while (fgets(buf, 256, error) != NULL) {
            printf("%s\r", buf);
        }
        fseek(error, 0L, SEEK_SET);
        printf("\f\r\x1b[41mCompile Error...\x1b[m\f\r");
        printf("\f\r");
        printf("もう一度挑戦する？\f\r");
        for (int i = 0; i < 2; i++) {
            printf("%c %s\f\r", arrow_data[i], retry_data[i]);
        }
        Arrow arrow = get_arrow();
        switch (arrow) {
        case ArrNone:
            break;

        case ArrUp:
            if (retry_id == 0) break;

            arrow_data[retry_id] = ' ';
            retry_id -= 1;
            arrow_data[retry_id] = '>';
            break;

        case ArrDown:
            if (retry_id == 1) break;

            arrow_data[retry_id] = ' ';
            retry_id += 1;
            arrow_data[retry_id] = '>';
            break;

        default:
            break;
        }
        if (arrow == ArrNone) break;
    }

    switch (retry_id) {
    case 0:
        break;
    case 1:
        exit_pro();
    }
}

void print_retry_failure(Data* data) {
    char arrow_data[4] = ">  ";
    char retry_data[4][16] = {
        "Retry",
        "No, Quit program",
    };
    int retry_id = 0;

    FILE* your_ans;
    if ((your_ans = fopen("./result/result.txt", "r")) == NULL) {
        printf("Can't open file: %s\f\r", "./result/result.c");
        exit_pro();
    }

    while (1) {
        system("clear");
        print(data);
        printf("\f\r");

        char buf[256];
        printf("あなたの回答:\f\r");
        while (fgets(buf, 256, your_ans) != NULL) {
            printf("%s\r", buf);
        }
        fseek(your_ans, 0L, SEEK_SET);
        printf("\f\r");
        printf("正答:\f\r");
        while (fgets(buf, 256, data->result_fp) != NULL) {
            printf("%s\r", buf);
        }
        fseek(data->result_fp, 0L, SEEK_SET);

        printf("\x1b[41mFailure...\x1b[m\f\r");
        printf("\f\r");
        printf("もう一度挑戦する？\f\r");
        for (int i = 0; i < 2; i++) {
            printf("%c %s\f\r", arrow_data[i], retry_data[i]);
        }
        Arrow arrow = get_arrow();
        switch (arrow) {
        case ArrNone:
            break;

        case ArrUp:
            if (retry_id == 0) break;

            arrow_data[retry_id] = ' ';
            retry_id -= 1;
            arrow_data[retry_id] = '>';
            break;

        case ArrDown:
            if (retry_id == 1) break;

            arrow_data[retry_id] = ' ';
            retry_id += 1;
            arrow_data[retry_id] = '>';
            break;

        default:
            break;
        }
        if (arrow == ArrNone) break;
    }

    switch (retry_id) {
    case 0:
        break;
    case 1:
        exit_pro();
    }
}
