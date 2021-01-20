#include "main.h"

int main(void) {
    Data data;
    data.difficulty_id = 0;
    data.question_id = 0;
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
    // 問題のファイルのファイルポインタを入手
    get_question_file(&data);
    // 許可
    allow_question(&data);

    // resolve question
    open_solve_fp(&data);
    solve_and_compile(&data);
    compare_file(&data);

    print_result(&data);
    
    // コンソールをCookedモードに
    allow_cooked_mode();
    return 0;
}

