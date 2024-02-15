#include <iostream>

// Calculating the days between two dates ( Considering leap years )

using namespace std;

bool IsKabise(int y) {

    if ((y % 4) == 0&&y%100!=0) {

        return true;

    }
    if (y % 400 == 0) {

        return true;

    }

    return false;


}

int taakhar(int d, int m, int y) {
    int arraym[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
    int arrayk[12] = { 31,29,31,30,31,30,31,31,30,31,30,31 };
    int s = 0;
    if (IsKabise(y)) {
        s += arrayk[m - 1] - d;
        for (int i = m ; i < 12; i++) {
            s += arrayk[i];
        }
    }
    else {
        s += arraym[m-1] - d;
        for (int i = m; i < 12; i++) {
            s += arraym[i];
        }
    }
    return s;
}





    int taaval(int d, int m, int y) {

        int arraym[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
        int arrayk[12] = { 31,29,31,30,31,30,31,31,30,31,30,31 };
        int s = 0;
        if (IsKabise(y)) {
            s += d;
            for (int i = m-2; i >=0; i--) {
                s += arrayk[i];
            }
        }
        else {
            s += d;
            for (int i = m-2; i >= 0; i--) {
                s += arraym[i];
            }
        }
        return s;
    
    
    
    }

int main()
{
    int d1, m1, y1;
    int d2, m2, y2;
    cin >> d1 >> m1 >> y1;
    cin >> d2 >> m2 >> y2;
    int arraym[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
    int arrayk[12] = { 31,29,31,30,31,30,31,31,30,31,30,31 };
    int bein = 0;
    for (int p = y1 + 1;p<y2;p++){

        if (IsKabise(p)) {
            bein += 366;
        }
        else {
            bein += 365;
        }
    }
    cout << bein + taakhar(d1,m1,y1) + taaval(d2,m2,y2);

}





