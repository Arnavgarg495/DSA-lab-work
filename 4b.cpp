#include<iostream>
using namespace std;
int main(){
    int x, y;
    cout<<"Enter rows and columns of first matrix: ";
    cin>>x>>y;
    cout<<"Enter rows and columns of second matrix: ";
    int p2, n2;
    cin>>p2>>n2;

    if (y != p2){
        cout<<"Matrix multiplication not possible!"<<endl;
        return 0;
    }

    int A[x][y], B[y][n2], C[x][n2];

    cout<<"Enter elements of first matrix: "<<endl;
    for (int i = 0; i < x; i++){
        for (int j = 0; j < y; j++){
            cin>>A[i][j];
        }
    }    
    cout<<"Enter elements of second matrix: "<<endl;
    for (int i = 0; i < y; i++){
        for (int j = 0; j < n2; j++){
            cin>>B[i][j];
        }
    }

    for (int i = 0; i < x; i++){
        for (int j = 0; j < n2; j++){
            C[i][j] = 0;
            for (int k = 0; k < y; k++){
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    cout<<"Resultant matrix: "<<endl;
    for (int i = 0; i < x; i++){
        for (int j = 0; j < n2; j++){
            cout << C[i][j] << " ";
        }
        cout<<endl;
    }
}
