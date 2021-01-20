#include "main.h"

void exit_pro();



int main(void) {
    Data data = { 0, 0, "" };
    
    // コンソールをRawモードに
    allow_raw_mode();

    // select menu 
    // 難易度選択
    difficulty_select_menu(&data);

    // 選択した難易度の問題をコピー
    copy_use_question(&data);

    // 問題選択
    question_select_menu(&data);

    // viwe question
    printf("難易度: %d\f\r問題文: %25s\f\r", data.difficulty_id, data.question[data.question_id]);
    

    // コンソールをCookedモードに
    allow_cooked_mode();

    return 0;
}

