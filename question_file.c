#include "main.h"

void get_question_file(Data* data) {
    char path[256] = "./question/";
    
    switch (data->difficulty_id) {
        case 0:
            strcat(path, "Lv1/");
            break;
        case 1:
            strcat(path, "Lv2/");
            break;
        case 2:
            strcat(path, "Lv3/");
            break;
    }
    
    switch (data->question_id) {
        case 0:
            strcat(path, "1.txt");
            break;
        case 1:
            strcat(path, "2.txt");
            break;
        case 2:
            strcat(path, "3.txt");
            break;
        case 3:
            strcat(path, "4.txt");
            break;
    }
    
    if ((data->question_fp = fopen(path, "r")) == NULL) {
        printf("can't open file: %s\f\r", path);
        exit_pro();
    }
}
