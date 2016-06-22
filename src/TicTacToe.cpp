#include "TicTacToe.h"
#include <cstdlib>
using namespace std;

void cuadro();
void turno_jugador();
bool gameover();

char turno;
bool draw = false;
char tablero[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};

int main()
{
    cout << "Tic Tac Toe \n";
    cout << "Jugador 1 [X] --- Jugador 2 [O]\n";
    turno = 'X';

    while (!gameover())
    {
        cuadro();
        turno_jugador();
        gameover();
    }

    if (turno == 'O' && !draw)
    {
        cuadro();
        cout << endl << endl << "Jugador 1 [X] Gana! Game Over!\n";
    }
    else if (turno == 'X' && !draw)
    {
        cuadro();
        cout << endl << endl << "Jugador 2 [O] Gana! Game Over!\n";
    }
    else
    {
        cuadro();
        cout << endl << endl << "Es un empate! Game Over!\n";
    }
}

void cuadro()
{
    cout << "---------------------" << endl << endl;
    cout << "     |     |     " << endl;
    cout << "  " << tablero[0][0] << "  |  " << tablero[0][1] << "  |  " << tablero[0][2] << endl;
    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;
    cout << "  " << tablero[1][0] << "  |  " << tablero[1][1] << "  |  " << tablero[1][2] << endl;
    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;
    cout << "  " << tablero[2][0] << "  |  " << tablero[2][1] << "  |  " << tablero[2][2] << endl;
    cout << "     |     |     " << endl;
}

void turno_jugador()
{
    int choice;
    int fila = 0, columna = 0;

    if (turno == 'X')
    {
        cout << "Turno del jugador 1  [X]: ";
    }
    else if (turno == 'O')
    {
        cout << "Turno del jugador 2  [O]: ";
    }
    cin >> choice;

    switch (choice)
    {
        case 1: fila = 0; columna = 0; break;
        case 2: fila = 0; columna = 1; break;
        case 3: fila = 0; columna = 2; break;
        case 4: fila = 1; columna = 0; break;
        case 5: fila = 1; columna = 1; break;
        case 6: fila = 1; columna = 2; break;
        case 7: fila = 2; columna = 0; break;
        case 8: fila = 2; columna = 1; break;
        case 9: fila = 2; columna = 2; break;
        default:
            cout << "Ingresa un numero correcto! Intentalo de nuevo\n";
            turno_jugador();
    }

    if (turno == 'X' && tablero[fila][columna] != 'X' && tablero[fila][columna] != 'O')
    {
        tablero[fila][columna] = 'X';
        turno = 'O';
    }
    else if (turno == 'O' && tablero[fila][columna] != 'X' && tablero[fila][columna] != 'O')
    {
        tablero[fila][columna] = 'O';
        turno = 'X';
    }
    else
    {
        cout << "Ya esa celda esta usada! Intentalo de nuevo\n";
        turno_jugador();
    }

}

bool gameover()
{
    for (int i = 0; i < 3; i++)//Chequea quien gana
    {
        if ((tablero[i][0] == tablero[i][1] && tablero[i][1] == tablero[i][2]) || (tablero[0][i] == tablero[1][i] && tablero[1][i] == tablero[2][i]) || (tablero[0][0] == tablero[1][1] && tablero[1][1] == tablero[2][2]) || (tablero[0][2] == tablero[1][1] && tablero[1][1] == tablero[2][0]))
        {
            return true;
        }
    }

    for (int i = 0; i < 3; i++)//Chequea por empates
    {
        for (int j = 0; j < 3; j++)
        {
            if (tablero[i][j] != 'X' && tablero[i][j] != 'O')
            {
                return false;
            }
        }
    }
    draw = true;
    return true;
}
