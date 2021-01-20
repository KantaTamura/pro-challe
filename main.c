#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <unistd.h>
#include <termios.h>

#define QUIT_CHAR 0x04 /* CTRL-D を押すと終了する．*/
#define ENTER 0x0D
#define ARROW 0x1B

char select_diff[4][64] = {
    "初級",
    "中級",
    "上級",
};

char arrow_point[16] = ">          ";

// 端末設定保存用大域変数
struct termios CookedTermIos;   // cooked モード用
struct termios RawTermIos;      // raw モード用

typedef enum {
    ArrNone,    // データなし
    ArrUp,      // 上矢印
    ArrDown,    // 下矢印
} Arrow;

void allow_raw_mode();
void allow_cooked_mode();

void exit_pro();

Arrow get_arrow();

void print_diff();

int main(void) {
    allow_raw_mode();

    int diff_id = 0;
    while (1) {
        print_diff();
        Arrow arrow = get_arrow();
        switch (arrow) {
        case ArrNone:
            break;
        case ArrUp:
            if (diff_id == 0) break;
            arrow_point[diff_id] = ' ';
            diff_id -= 1;
            arrow_point[diff_id] = '>';
            break;
        case ArrDown:
            if (diff_id == 2) break;
            arrow_point[diff_id] = ' ';
            diff_id += 1;
            arrow_point[diff_id] = '>';
            break;
        default:
            break;
        }
        if (arrow == ArrNone) break;
    }

    printf("選択した難易度:%s\f\r", select_diff[diff_id]);




    allow_cooked_mode();

    return 0;
}

void allow_raw_mode() {
    // 初期状態の端末設定 (cooked モード) を取得・保存する．
    tcgetattr(STDIN_FILENO, &CookedTermIos);

    // raw モードの端末設定を作成・保存する．
    RawTermIos = CookedTermIos;
    cfmakeraw(&RawTermIos);

    // 端末を raw モードに設定する．
    tcsetattr(STDIN_FILENO, 0, &RawTermIos);

    // 端末をクリアする
    system("clear");
}

void allow_cooked_mode() {
    // 端末設定を元に戻す．
    tcsetattr(STDIN_FILENO, 0, &CookedTermIos);
    putchar('\n');
}

void exit_pro() {
    allow_cooked_mode();
    exit(-1);
}

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

void print_diff() {
    system("clear");
    printf("難易度を選択してください。\f\r");
    for (int i = 0; i < 3; i++) {
        printf("%d. %c %s\f\r", i, arrow_point[i], select_diff[i]);
    }
}
