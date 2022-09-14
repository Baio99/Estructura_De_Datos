/*****************************************
* UNIVERDIAD DE LAS FUERZAS ARMADAS ESPE *
*Clase sudoku                            *
*Autor Jonathan Maigua y Andrian Iza     *
*Fecha de creacion 25/03/2021            *
*Fecha de modificacion 
******************************************/
#include<iostream>
#include<math.h>

class sudoku
{
public:
    sudoku();
    void inicializarSudoku();
    void imprimirSudoku();
    bool resolverSudoku();
    bool findEmptyGridSlot(int &fila, int &col); //encontrar ranura de cuadrícula vacía 
    bool canPlaceNum(int fila, int col, int num); //colocar numeros
    bool numeroEnFila(int fila, int num);
    bool numeroEnColumna(int col, int num);
    bool numeroEnCasilla(int smallGridRow, int smallGridCol, int num);
    int grid[9][9];
};

sudoku::sudoku()
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            grid[i][j] = 0;
        }
    }
    std::cout << "\n Todas las ubicaciones de la cuadricula se inicializan a cero";
}

void sudoku::inicializarSudoku()
{
    char x = 'y';
    while (x == 'y')
    {
        int fila, col, var;
        std::cout
                << "\n Ingrese la fila, la columna y el numero entero en el cuadro ( 1-9 ) \n"<<endl;
        std::cout<< "\n Ingrese la fila"<<endl;
        std::cin >> fila;
        std::cout<< "\n Ingrese la columna"<<endl;
        std::cin >> col;
        std::cout<< "\n Ingrese el valor"<<endl;
        std::cin >> var;
        grid[fila][col] = var;
        std::cout
                << "\n Hay espacios donde desea ingresar nuevos numeros? Si desea presione _ Y _ ,si no desea preione _N_ \n";
        std::cin >> x;
    }
}

void sudoku::imprimirSudoku()
{
    std::cout << "\n";
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            std::cout << grid[i][j] << " ";
        }
        std::cout << "\n";
    }
}

bool sudoku::resolverSudoku()
{
    int fila, col;
    if (findEmptyGridSlot(fila, col))
    {
        for (int num = 1; num <= 9; num++)
        {
            if (canPlaceNum(fila, col, num))
            {
                grid[fila][col] = num;
                if (resolverSudoku()) //llamada recursiva 
                    return true;
                grid[fila][col] = 0;
            }
        }
        return false; //backtrack
    }
    else
        return true; //no hay espacios vacíos 
}

bool sudoku::numeroEnFila(int fila, int num)
{
    for (int i = 0; i < 9; i++)
    {
        if (num != 0 && grid[fila][i] == num)
            return true;
    }
    return false;
}

bool sudoku::numeroEnColumna(int col, int num)
{
    for (int i = 0; i < 9; i++)
    {
        if (num != 0 && grid[i][col] == num)
            return true;
    }
    return false;
}

bool sudoku::canPlaceNum(int fila, int col, int num)
{
    if (!numeroEnFila(fila, num))
    {
        if (!numeroEnColumna(col, num))
        {
            int smallGridRow = fila - fila % 3;
            int smallGridCol = col - col % 3;
            if (!numeroEnCasilla(smallGridRow, smallGridCol, num))
            {
                return true;
            }
        }
    }
    return false;
}

bool sudoku::numeroEnCasilla(int smallGridRow, int smallGridCol, int num)
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (grid[i + smallGridRow][j + smallGridCol] == num)
                return true;
        }
    }
    return false;
}

bool sudoku::findEmptyGridSlot(int &fila, int &col)
{
    for (fila = 0; fila < 9; fila++)
    {
        for (col = 0; col < 9; col++)
        {
            if (grid[fila][col] == 0)
                return true;
        }
    }
    return false;
}



