void print_strmat(string **S, int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << '\t' << S[i][j];
        }
        cout << endl;
    }
}

int main()
{
    string **matrice = new string *[3];

    string parole[9] = {"nepal", "Cane", "Albero", "Rossi", "Gelato", "Limone", "Sale", "Olio", "Pelato"};
    int i = 0;

    for (int r = 0; r < 3; r++)
    {
        matrice[r] = new string[3];
        for (int c = 0; c < 3; c++)
        {
            matrice[r][c] = parole[i];
            i++;
        }
    }

    print_strmat(matrice, 3, 3);
    cout << "Risultato: " << func(matrice, 3, 3, 2); //(ne)pal === ca(ne)
}