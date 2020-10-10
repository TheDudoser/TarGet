#include <iostream>
#include <ctime>
#include <math.h>

using namespace std;

void randomize_coordinate(float* x, float* y){
    srand(time(NULL));

    *x += rand() % 11 - 5;
    *y += rand() % 11 - 5;
    //cout << *x << ' ' << *y;
}

void check_hit(float x, float y, int *sum, int sectors[6])
{
    double r;
    int goal;
    //cout << "x: " << x << ' ' << "y: " << y << endl;
    r = sqrt(x*x + y*y);
    //cout << "r: " << r << endl;

    for (int i = 0; i < 6; ++i){
        (((i+1)<6) && ((r < sectors[i]) && (r >= sectors[i+1]))) ? goal = i + 1 : goal = 0;
        //cout << "goal: " << goal << endl;
        *sum += goal;
    }
    //cout << "sum: " << *sum << endl;
}

int main() {
    float x, y;
    int sum = 0;
    int sectors [6] = {5, 4, 3, 2, 1, 0};

    for (int i = 1; i < 6; ++i) {
        cout << i << " ВЫСТРЕЛ" << endl;
        cout << "Введите координату x:" << endl;
        cin >> x;

        cout << "Введите координату y:" << endl;
        cin >> y;
        cout << '\n';

        randomize_coordinate(&x, &y);

        check_hit(x, y, &sum, sectors);

    }
    cout << "Ты набрал " << sum << " очков" << endl;
    if (sum < 10)
        cout << "лузер" << endl;
    return 0;
}
