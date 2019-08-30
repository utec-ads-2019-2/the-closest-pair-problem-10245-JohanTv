#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

vector<double> distancias;
double A1, A2;
double B1, B2;
double it;

double calcularDistancia(){
	double x = sqrt(pow(A1-B1,2)+pow(A2-B2,2));
    return x;
}

int main() {
    int numeros=0;
    while(scanf("%u",&numeros)==1 && numeros!=0){
        cin>>A1>>A2;
        for(int i = 1; i<numeros; ++i){
            cin>>B1>>B2;
            distancias.push_back(calcularDistancia());
            A1=B1;
            A2=B2;
        }
        

        it =  *min_element(distancias.begin(), distancias.end());
        
        if(it<10000) cout<< it << endl;
        else cout<<"INFINITY"<<endl;
	
		
        distancias.clear();
    }

    return 0;
}
