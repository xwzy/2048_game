#include "model.h"

model::model()
{
    init();
}



void model::init() {
    alive = 1;
    points = 0;

    for (int i = 0; i < 16; i++) {
        *(ptr+i) = 0;
    }
    //初始化盘面
    srand((unsigned int)time(NULL));
    int x = rand() % 16;
    *(ptr+x) = 2;
    srand((unsigned int)time(NULL)+433);
    x = rand() % 15;
    *(ptr+x) = 2;
}


void model::appear() {
    int cnt = 0;
    for (int i = 0; i != 16; ++i) {
        if (*(ptr+i) == 0) {
//  很诡异的语句          srand((unsigned int)time(0l)*23+12);
            int num = rand() % 100;
//            printf("%d\n", num);
            if (num > 72 && cnt < 2) {
                *(ptr+i) = 2;
                cnt++;
            }
            if (num > 92 && cnt < 2) {
                *(ptr+i) = 4;
            }

        }
    }
//    printf("cnt = %d\n", cnt);
}


void model::checkdead() {
    for (int i = 0; i != 16; ++i) {
        if (*(ptr+i) == 0) {
            alive = 1;
            return;
        }
    }
    for (int i = 1; i != 3; ++i) {
        for (int j = 1; j != 3; ++j) {
            if (a[i+1][j] == a[i][j] || a[i-1][j] == a[i][j] || a[i][j+1] == a[i][j] || a[i][j-1] == a[i][j] ) {
                alive = 1;
                return;
            }
        }
    }
    for (int j = 0; j != 4; ++j) {
        for (int i = 0; i != 3; ++i) {
            if (a[j][i] == a[j][i+1]) {
                alive = 1;
                return;
            }
        }
    }
    for (int j = 0; j != 4; ++j) {
        for (int i = 0; i != 3; ++i) {
            if (a[i][j] == a[i+1][j]) {
                alive = 1;
                return;
            }
        }
    }
    alive = 0;
}

bool model::isDead() {
    checkdead();
    if (alive == 0) {
        return true;
    } else {
        return false;
    }
}

vector<int> model::getStatus() {

    vector<int> s;
    for (int i = 0; i != 4; ++i) {
        for (int j = 0; j != 4; ++j) {
            s.push_back(a[i][j]);
        }
    }

    return s;

}

void model::printa() {
    printf("|");
//    printf("____________________\n|");
    for (int i = 0; i != 4; ++i) {
        printf("————————————————————\n|");
        for (int j = 0; j != 4; ++j) {
            if (a[i][j] != 0) {
                printf("%4d|",a[i][j]);
            } else {
                printf("   O|");
            }
        }
        printf("\n|");
    }
    printf("————————————————————\n");
}

void model::action(char move) {
    switch (move) {
        case 'a':
            movel();
            break;
        case 'd':
            mover();
            break;
        case 'w':
            moveu();
            break;
        case 's':
            moved();
            break;

        default:
            printf("错误的输入\nf");
            break;
    }
}


void model::movel() {
    for (int step = 0; step != 3; ++step) {
        for (int i = 0; i != 4; ++i) {
            for (int col = 3; col != 0; col--) {
                if (*(ptr+col+i*4) != 0) {
                    if (*(ptr+col+i*4) == *(ptr+col-1+i*4)) {
                        *(ptr+col+i*4) = 0;
                        points += *(ptr+col-1+i*4);
                        *(ptr+col-1+i*4) *= 2;
                    } else if (*(ptr+col-1+i*4) == 0) {
                        *(ptr+col-1+i*4) = *(ptr+col+i*4);
                        *(ptr+col+i*4) = 0;
                    }
                }
            }
        }
    }
}

void model::mover() {
    for (int step = 0; step != 3; ++step) {
        for (int i = 0; i != 4; ++i) {
            for (int col = 0; col != 3; ++col) {
                if (*(ptr+col+i*4) != 0) {
                    if (*(ptr+col+i*4) == *(ptr+col+1+i*4)) {
                        *(ptr+col+i*4) = 0;
                        points += *(ptr+col+1+i*4);
                        *(ptr+col+1+i*4) *= 2;
                    } else if (*(ptr+col+1+i*4) == 0) {
                        *(ptr+col+1+i*4) = *(ptr+col+i*4);
                        *(ptr+col+i*4) = 0;
                    }
                }
            }
        }
    }
}
void model::moveu() {
    for (int step = 0; step != 3; ++step) {
        for (int line = 3; line != 0; --line) {
            for (int i = 0; i != 4; ++i) {
                if (*(ptr+i+line*4) != 0) {
                    if (*(ptr+i+line*4) == *(ptr+i+(line-1)*4)) {
                        *(ptr+i+line*4) = 0;
                        points += *(ptr+i+(line-1)*4);
                        *(ptr+i+(line-1)*4) *= 2;
                    } else if (*(ptr+i+(line-1)*4) == 0) {
                        *(ptr+i+(line-1)*4) = *(ptr+i+line*4);
                        *(ptr+i+line*4) = 0;
                    }
                }
            }
        }
    }
}
void model::moved() {
    for (int step = 0; step != 3; ++step) {

        for (int line = 0; line != 3; ++line) {
            for (int i = 0; i != 4; ++i) {
                if (*(ptr+i+line*4) != 0) {
                    if (*(ptr+i+line*4) == *(ptr+i+(line+1)*4)) {
                        *(ptr+i+line*4) = 0;
                        points += *(ptr+i+(line+1)*4);
                        *(ptr+i+(line+1)*4) *= 2;
                    } else if (*(ptr+i+(line+1)*4) == 0) {
                        *(ptr+i+(line+1)*4) = *(ptr+i+line*4);
                        *(ptr+i+line*4) = 0;
                    }
                }
            }
        }
    }
}
