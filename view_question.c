#include "main.h"

void allow_question(Data* data) {
    char arrow_data[4] = "> ";
    char allow_data[4][16] = {
        "Ok",
        "No, Quit program",
    };
    int allow_id = 0;

    while (1) {
        print(data);
        printf("問題を開始してもいいですか？\f\r");
        for (int i = 0; i < 2; i++) {
            printf("%c %s\f\r", arrow_data[i], allow_data[i]);
        }
        Arrow arrow = get_arrow();
        switch (arrow) {
        case ArrNone:
            break;

        case ArrUp:
            if (allow_id == 0) break;

            arrow_data[allow_id] = ' ';
            allow_id -= 1;
            arrow_data[allow_id] = '>';
            break;

        case ArrDown:
            if (allow_id == 1) break;

            arrow_data[allow_id] = ' ';
            allow_id += 1;
            arrow_data[allow_id] = '>';
            break;

        default:
            break;
        }
        if (arrow == ArrNone) break;
    }

    switch (allow_id) {
    case 0:
        break;
    case 1:
        exit_pro();
    }
}

void print(Data* data) {
    system("clear");
    print_details(data);
    print_problem(data);
}

void print_details(Data* data) {
    printf("難易度: %d\f\r", data->difficulty_id);
    printf("問題文: %25s\f\r", data->question[data->question_id]);
    printf("\f\r");
}

void print_problem(Data* data) {
    char buf[256];
    while (fgets(buf, 256, data->question_fp) != NULL) {
        printf("%s\r", buf);
    }
    fseek(data->question_fp, 0L, SEEK_SET);
}