#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <conio.h>
#include <cstdio>

//created and developed by Hardiansyah Shidek / 1301164097
//IF-40-07

using namespace std;

int main() {

    double T = 9000000;      //T digunakan sebagai parameter dari temperatur
    double alpha = 0.7;     //alpha digunkan untuk jadwal pendinginan dari temperatur
    int maxi = 10;          //nilai maximum x1 dan x2
    int mini = -10;         //nilai minimum x1 dan x2

    srand(time(NULL));
    int ranx1 = (mini + (rand() % (int)(maxi - mini + 1)));      //mendapatkan nilai random x1
    int ranx2 = (mini + (rand() % (int)(maxi - mini + 1)));      //mendapatkan nilai random x2

    double bestCurrent = -(abs(sin(ranx1)*cos(ranx2)*exp(abs(1-(sqrt(pow(ranx1, 2)+pow(ranx2, 2))/3.14)))));  //Fungsi yang akan dicari nilai minimumnya

    for( int a = 1; a <= T; a++ ){  // Perulangan untuk proses iterasi (atau mencari new state )

        int ranx3 = (mini + (rand() % (int)(maxi - mini + 1)));  //mendapatkan nilai random x3
        int ranx4 = (mini + (rand() % (int)(maxi - mini + 1)));  //mendapatkan nilai random x4

        double nextState = -(abs(sin(ranx3)*cos(ranx4)*exp(abs(1-(sqrt(pow(ranx3, 2)+pow(ranx4, 2))/3.14)))));   //next state dari fungsi yang diberikan

        double deltaE = nextState - bestCurrent;

        T = (int) (T * alpha);  //T = T * alpha yang digunakan untuk jadwal pendinginan

        if (deltaE < 0){

            bestCurrent = nextState;  //best-so-far yang didapat

        } else {

            double newRand = (int) rand()/RAND_MAX;   //mencari nilai random 0 s.d. 1
            double p = exp(-deltaE/T);

            if (p > newRand){
                bestCurrent = nextState;
            }
        }

    }
    cout << "nilai minimum :";
    cout << bestCurrent << endl;
    return 0;
    std::getchar();
}

