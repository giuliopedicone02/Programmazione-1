/*Quando si passano array multidimensionali allocati staticamente o automaticamente,
 è necessario specificare tutte dimensioni a partire dalla seconda:
*/

/*#define M 5
#define N 8
#define O 4
void print_array(int v[][N]);
void print_array(int v[][N][O]);
void print_array(int v[M][N][O]);
//void print_array(int v[][][O]); //errore
//void print_array(int v[][][]); //errore*/

#include <iostream>
using namespace std;

void print_static(int x[3][3])
{
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            cout << "x[" << i << "][" << j << "]=" << x[i][j] << endl;
    cout << endl;
}

void print_dynamic(int **x, int rows, int cols)
{
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            cout << "x[" << i << "][" << j << "]=" << x[i][j] << endl;
    cout << endl;
}

void print_mixed(int *x[], int rows, int cols)
{
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            cout << "x[" << i << "][" << j << "]=" << x[i][j] << endl;
    cout << endl;
}

int main()
{
    int s[3][3] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    print_static(s);

    int k = 1;
    int **d = new int *[5]; //Creiamo una matrice 5x3
    for (int i = 0; i < 5; i++)
    {
        d[i] = new int[3];
        for (int j = 0; j < 3; j++)
        {
            d[i][j] = k++;
        }
    }

    print_dynamic(d, 5, 3);
    //In questo modo è possibile passare ad una funzione una matrice senza sapere a priori le dimensioni

    //print_mixed(d,5,3); Funziona ugualmente
}