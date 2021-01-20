#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <termios.h>

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
} Data;

// console.c
void allow_raw_mode();
void allow_cooked_mode();

// select.c
Arrow get_arrow();

void copy_question          (char array[4][64], const char buf[4][64]);
void copy_use_question      (Data* data);

void difficulty_select_menu (Data* data);
void print_difficulty       ();

void question_select_menu   (Data* data);
void print_question         (Data* data);

void exit_pro();

// view_question.c
void allow_question(Data* data);
void print(Data* data);
void print_details(Data* data);
void print_problem(Data* data);

// question_file.c
void get_question_file(Data* data);

// compile_file.c
void solve_and_compile(Data* data);

