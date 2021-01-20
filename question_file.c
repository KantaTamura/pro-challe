#include "main.h"

void get_question_file(Data* data) {
    char path_question[64] = "./question/";
    char path_result[64] = "./result/";
    char path_input[64] = "./input/";

    switch (data->difficulty_id) {
    case 0:
        strcat(path_question, "Lv1/");
        strcat(path_result, "Lv1/");
        strcat(path_input, "Lv1/");
        break;
    case 1:
        strcat(path_question, "Lv2/");
        strcat(path_result, "Lv2/");
        strcat(path_input, "Lv2/");
        break;
    case 2:
        strcat(path_question, "Lv3/");
        strcat(path_result, "Lv3/");
        strcat(path_input, "Lv3/");
        break;
    }

    switch (data->question_id) {
    case 0:
        strcat(path_question, "1.txt");
        strcat(path_result, "1.txt");
        strcat(path_input, "1.txt");
        break;
    case 1:
        strcat(path_question, "2.txt");
        strcat(path_result, "2.txt");
        strcat(path_input, "2.txt");
        break;
    case 2:
        strcat(path_question, "3.txt");
        strcat(path_result, "3.txt");
        strcat(path_input, "3.txt");
        break;
    case 3:
        strcat(path_question, "4.txt");
        strcat(path_result, "4.txt");
        strcat(path_input, "4.txt");
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
    
    strcpy(data->input_file, path_input);
}
