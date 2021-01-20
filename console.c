#include "main.h"

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

