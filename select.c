#include "main.h"
#include "const.h"

Arrow get_arrow() {
    char c; Arrow arrow = ArrNone;
    while ((c = getchar()) != QUIT_CHAR) {
        if (c == ARROW && arrow == ArrNone) {
            getchar();  c = getchar();
            switch (c) {
            case 'A':
                return ArrUp;
            case 'B':
                return ArrDown;
            default:
                break;
            }
        }
        if (c == ENTER) {
            return ArrNone;
        }
    }
    exit_pro();
}


void copy_question(char array[4][64], const char buf[4][64]) {
    for (int i = 0; i < 4; i++) {
        strcpy(array[i], buf[i]);
    }
}

void copy_use_question(Data* data) {
    switch (data->difficulty_id) {
    case 0:
        copy_question(data->question, que_lv1);
        break;
    case 1:
        copy_question(data->question, que_lv2);
        break;
    case 2:
        copy_question(data->question, que_lv3);
        break;
    }
}

void difficulty_select_menu(Data* data) {
    while (1) {
        print_difficulty();
        Arrow arrow = get_arrow();
        switch (arrow) {
        case ArrNone:
            break;

        case ArrUp:
            if (data->difficulty_id == 0) break;

            arrow_point[data->difficulty_id] = ' ';
            data->difficulty_id -= 1;
            arrow_point[data->difficulty_id] = '>';
            break;

        case ArrDown:
            if (data->difficulty_id == 2) break;

            arrow_point[data->difficulty_id] = ' ';
            data->difficulty_id += 1;
            arrow_point[data->difficulty_id] = '>';
            break;

        default:
            break;

        }
        if (arrow == ArrNone) break;
    }
}

void print_difficulty() {
    system("clear");
    printf("難易度を選択してください。\f\r");
    for (int i = 0; i < 3; i++) {
        printf("%d. %c %s\f\r", i, arrow_point[i], select_diff[i]);
    }
}

void question_select_menu(Data* data) {
    strcpy(arrow_point, ">          ");
    while (1) {
        print_question(data);
        Arrow arrow = get_arrow();
        switch (arrow) {
        case ArrNone:
            break;

        case ArrUp:
            if (data->question_id == 0) break;

            arrow_point[data->question_id] = ' ';
            data->question_id -= 1;
            arrow_point[data->question_id] = '>';
            break;

        case ArrDown:
            if (data->question_id == 3) break;

            arrow_point[data->question_id] = ' ';
            data->question_id += 1;
            arrow_point[data->question_id] = '>';
            break;

        default:
            break;
        }
        if (arrow == ArrNone) break;
    }
}

void print_question(Data* data) {
    system("clear");
    printf("選択した難易度:%s\f\r", select_diff[data->difficulty_id]);
    printf("問題を選択してください。\f\r");
    for (int i = 0; i < 4; i++) {
        printf("%d. %c %25s\f\r", i, arrow_point[i], data->question[i]);
    }
}

void exit_pro() {
    allow_cooked_mode();
    system("clear");
    exit(-1);
}
