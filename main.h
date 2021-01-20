#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <termios.h>
#include <time.h>

#define QUIT_CHAR 0x04  // EXIT KEY : Ctrl + D
#define ENTER 0x0D      // ENTER
#define ARROW 0x1B      // ↑↓→←

// 端末設定保存用大域変数
struct termios CookedTermIos;   // cooked モード用
struct termios RawTermIos;      // raw モード用

typedef enum {
    ArrNone,    // データなし
    ArrUp,      // 上矢印
    ArrDown,    // 下矢印
} Arrow;

typedef struct {
    int  difficulty_id;     // 難易度番号
    int  question_id;       // 問題番号
    char question[4][64];   // 問題リスト
    FILE* question_fp;      // 問題本文のポインタ
    FILE* result_fp;        // 解答ファイルのポインタ
    char input_file[64];    // 標準入力保存ファイルへのパス
    int result;             // 結果のフラグ(0: faild, 1: success)
    FILE* solve_fp;         // 回答のファイルポインタ
    time_t c_start;        // 開始時間
    time_t c_end;          // 終了時間
} Data;

// console.c
void allow_raw_mode();
void allow_cooked_mode();

// select.c
Arrow get_arrow();

void copy_question(char array[4][64], const char buf[4][64]);
void copy_use_question(Data* data);

void difficulty_select_menu(Data* data);
void print_difficulty();

void question_select_menu(Data* data);
void print_question(Data* data);

void get_difficulty(Data* data, char buf[64]);

void exit_pro();

// view_question.c
void allow_question(Data* data);
void print(Data* data);
void print_details(Data* data);
void print_problem(Data* data);

// question_file.c
void get_question_file(Data* data);

// compile_file.c
void open_solve_fp(Data* data);
void solve_and_compile(Data* data);
void retry_with_error(Data* data);
void compare_file(Data* data);
void print_result(Data* data);
void print_retry(Data* data, FILE* error);
void print_retry_failure(Data* data);
