#include<iostream>
using namespace std;
int main(){
    int m1, p1;
    cout<<"Enter rows and columns of first matrix: ";
    cin>>m1>>p1;
    cout<<"Enter rows and columns of second matrix: ";
    int p2, n2;
    cin>>p2>>n2;

    if (p1 != p2){
        cout<<"Matrix multiplication not possible!"<<endl;
        return 0;
    }

    int A[m1][p1], B[p1][n2], C[m1][n2];

    cout<<"Enter elements of first matrix: "<<endl;
    for (int i = 0; i < m1; i++){
        for (int j = 0; j < p1; j++){
            cin>>A[i][j];
        }
    }    
    cout<<"Enter elements of second matrix: "<<endl;
    for (int i = 0; i < p1; i++){
        for (int j = 0; j < n2; j++){
            cin>>B[i][j];
        }
    }

    for (int i = 0; i < m1; i++){
        for (int j = 0; j < n2; j++){
            C[i][j] = 0;
            for (int k = 0; k < p1; k++){
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    cout<<"Resultant matrix: "<<endl;
    for (int i = 0; i < m1; i++){
        for (int j = 0; j < n2; j++){
            cout << C[i][j] << " ";
        }
        cout<<endl;
    }
}