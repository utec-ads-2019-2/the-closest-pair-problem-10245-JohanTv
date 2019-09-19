#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

class Punto{
private:
public:
    double xi, yi;
    Punto(double x, double y){
        xi=x;
        yi=y;

    }

    double getXi() const {
        return xi;
    }

    double getYi() const {
        return yi;
    }

};

double calcularDistancia(Punto* a, Punto* b){
    return sqrt(pow(a->getXi() - b->getXi(),2)+pow(a->getYi() - b->getYi(),2));
}

int main() {
    int numPunts;
    double a, b;

    vector<Punto*> puntos;
    double minDist;
    double temp;
    while(cin>>numPunts, numPunts != 0){

        if(numPunts == 1) {
            cin >> a >> b;
            cout<<"INFINITY"<<endl;
        }
        else {
            for (int i = 0; i < numPunts; ++i) {
                cin >> a >> b;
                puntos.push_back(new Punto(a, b));
            }

            minDist = calcularDistancia(puntos[0], puntos[1]);
            for (int i = 0; i < numPunts-1; ++i) {
                for (int j = i+1; j < numPunts; ++j) {
                    temp = calcularDistancia(puntos[i], puntos[j]);
                    if (minDist > temp) minDist = temp;
                }
            }
            if (minDist >= 10000) {cout << "INFINITY" << endl;}
            else {cout << fixed << setprecision(4) << minDist << endl;}

            puntos.clear();
        }
    }

}
