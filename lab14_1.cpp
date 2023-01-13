#include <iostream>
#include <cmath>
using namespace std;

void stat(const double[],int,double[]);

int main(){
    double A[] = {1.2,3.5,6.9,7.8,12.5,0.5};
    int N = sizeof(A)/sizeof(A[0]);
    double B[6];
    stat(A,N,B);
    cout << "Arithmetic Mean = " << B[0];
    cout << "\nStandard Deviation = " << B[1];
    cout << "\nGeometric Mean = " << B[2];
    cout << "\nHarmonic Mean = " << B[3];
    cout << "\nMax = " << B[4];
    cout << "\nMin = " << B[5];
    return 0;
}

void stat(const double A[], int N, double B[]){
    double A_sum = 0;
    double Asquared_sum = 0;
    double pre_GM = 1;
    double pre_HM = 0;
    double min = A[0], max = A[0];
    for(int i = 0; i < N; i++){
        A_sum += A[i];
        Asquared_sum += pow(A[i], 2);
        pre_GM *= A[i];
        pre_HM += 1/A[i];
        if(A[i] < min) min = A[i];
        if(A[i] > max) max = A[i];
    }

    B[0] = A_sum / N;

    B[1] = sqrt((Asquared_sum / N) - pow(B[0], 2));

    B[2] = pow(pre_GM, (double) 1/N);

    B[3] = N / pre_HM;

    B[4] = max;

    B[5] = min;
}
