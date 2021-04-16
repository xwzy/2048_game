#ifndef MODEL_H
#define MODEL_H

#include <cstdio>
#include <ctime>
#include <cstdlib>

#include <vector>

using namespace std;
class model
{
public:
    model();


    void printa();
    void appear();
    void init();
    void action(char move);
    void movel();
    void mover();
    void moveu();
    void moved();
    void checkdead();
    bool isDead();


    vector<int> getStatus();

    int getPoints() {
        return points;
    }
private:
    int a[4][4];
    int *ptr = *a;
    int alive = 1;
    int points;

};

#endif // MODEL_H
