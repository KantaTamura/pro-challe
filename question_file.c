#include "main.h"

void get_question_file(Data* data) {
    char path_question[256] = "./question/";
    char path_result[256] = "./result/";

    switch (data->difficulty_id) {
    case 0:
        strcat(path_question, "Lv1/");
        strcat(path_result, "Lv1/");
        break;
    case 1:
        strcat(path_question, "Lv2/");
        strcat(path_result, "Lv2/");
        break;
    case 2:
        strcat(path_question, "Lv3/");
        strcat(path_result, "Lv3/");
        break;
    }

    switch (data->question_id) {
    case 0:
        strcat(path_question, "1.txt");
        strcat(path_result, "1.txt");
        break;
    case 1:
        strcat(path_question, "2.txt");
        strcat(path_result, "2.txt");
        break;
    case 2:
        strcat(path_question, "3.txt");
        strcat(path_result, "3.txt");
        break;
    case 3:
        strcat(path_question, "4.txt");
        strcat(path_result, "4.txt");
        break;
    }

    if ((data->question_fp = fopen(path_question, "r")) == NULL) {
        printf("can't open file: %s\f\r", path_question);
        exit_pro();
    }

    if ((data->result_fp = fopen(path_result, "r")) == NULL) {
        printf("can't open file: %s\f\r", path_result);
        exit_pro();
    }
}
