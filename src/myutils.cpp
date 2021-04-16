#include "myutils.h"

myutils::myutils()
{

}


int myutils::pow(int a, int b) {
    if (b == 1) {
        return a;
    }

    if (b == 0) {
        return 1;
    }

    if (b < 0) {
        return -1;
    }

    if (b == 2) {
        return a * a;
    } else {
        return a * pow(a, b-1);
    }
}
