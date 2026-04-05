#include <iostream>
#include <string>
using namespace std;

// ==========================================================
// CONFIGURACIÓN GLOBAL Y MOTOR DE MAPA
// ==========================================================
const int filas = 30;
const int columnas = 30;
char matriz[filas][columnas]; // Matriz bidimensional para renderizado CLI
char tecla;

// Variables de estado del Jugador (P) y Enemigo (E)
int x = 3, y = 3;
int enemigoX = 27, enemigoY = 3;
bool lvl_1 = false;
bool lvl_2 = false;
bool lvl_3 = false;
int vidas = 3;

// Coordenadas de los items de progresión (Llaves)
int llave1x = 26, llave1y = 26;
int llave2x = 4, llave2y = 23;
int llave3x = 20, llave3y = 15;

int contadoroLlaves = 0;
int contadorTurnos = 0; // Utilizado para controlar la velocidad de la IA

/**
 * Genera la estructura del laberinto y coloca los obstáculos (#)
 * @param laberinto Selector de nivel (1, 2 o 3)
 */
void inicializarMatriz(int laberinto)
{
    // Generación de límites (Paredes perimetrales)
    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            if (i == 0 || i == filas - 1 || j == 0 || j == columnas - 1)
            {
                matriz[i][j] = '#';
            }
            else
            {
                matriz[i][j] = ' '; // Espacio transitable
            }
        }
    }

    // DISEÑO LÓGICO DE NIVELES (Basado en coordenadas específicas)
    if (laberinto == 1)
    {
        // Renderizado manual de obstáculos para el Nivel 1
        matriz[1][6] = '#';
        matriz[1][12] = '#';
        matriz[1][13] = '#';
        matriz[1][15] = '#';
        matriz[1][17] = '#';
        matriz[1][22] = '#';
        matriz[2][6] = '#';
        matriz[2][7] = '#';
        matriz[2][8] = '#';
        matriz[2][9] = '#';
        matriz[2][10] = '#';
        matriz[2][13] = '#';
        matriz[2][15] = '#';
        matriz[2][17] = '#';
        matriz[2][18] = '#';
        matriz[2][19] = '#';
        matriz[2][20] = '#';
        matriz[2][22] = '#';
        matriz[2][23] = '#';
        matriz[2][24] = '#';
        matriz[2][25] = '#';
        matriz[2][26] = '#';
        matriz[2][27] = '#';
        matriz[3][6] = '#';
        matriz[3][10] = '#';
        matriz[3][11] = '#';
        matriz[3][13] = '#';
        matriz[3][15] = '#';
        matriz[3][25] = '#';
        matriz[3][27] = '#';
        matriz[4][6] = '#';
        matriz[4][7] = '#';
        matriz[4][8] = '#';
        matriz[4][11] = '#';
        matriz[4][13] = '#';
        matriz[4][15] = '#';
        matriz[4][17] = '#';
        matriz[4][18] = '#';
        matriz[4][19] = '#';
        matriz[4][20] = '#';
        matriz[4][22] = '#';
        matriz[4][23] = '#';
        matriz[4][25] = '#';
        matriz[4][27] = '#';
        matriz[5][6] = '#';
        matriz[5][8] = '#';
        matriz[5][9] = '#';
        matriz[5][11] = '#';
        matriz[5][13] = '#';
        matriz[5][17] = '#';
        matriz[5][23] = '#';
        matriz[5][27] = '#';
        matriz[6][1] = '#';
        matriz[6][2] = '#';
        matriz[6][4] = '#';
        matriz[6][5] = '#';
        matriz[6][6] = '#';
        matriz[6][8] = '#';
        matriz[6][11] = '#';
        matriz[6][13] = '#';
        matriz[6][15] = '#';
        matriz[6][16] = '#';
        matriz[6][17] = '#';
        matriz[6][19] = '#';
        matriz[6][20] = '#';
        matriz[6][21] = '#';
        matriz[6][23] = '#';
        matriz[6][24] = '#';
        matriz[6][25] = '#';
        matriz[6][27] = '#';
        matriz[7][2] = '#';
        matriz[7][4] = '#';
        matriz[7][8] = '#';
        matriz[7][10] = '#';
        matriz[7][11] = '#';
        matriz[7][13] = '#';
        matriz[7][15] = '#';
        matriz[7][19] = '#';
        matriz[7][21] = '#';
        matriz[7][25] = '#';
        matriz[7][27] = '#';
        matriz[8][6] = '#';
        matriz[8][7] = '#';
        matriz[8][8] = '#';
        matriz[8][11] = '#';
        matriz[8][15] = '#';
        matriz[8][17] = '#';
        matriz[8][18] = '#';
        matriz[8][19] = '#';
        matriz[8][21] = '#';
        matriz[8][22] = '#';
        matriz[8][23] = '#';
        matriz[8][25] = '#';
        matriz[8][27] = '#';
        matriz[9][2] = '#';
        matriz[9][4] = '#';
        matriz[9][6] = '#';
        matriz[9][10] = '#';
        matriz[9][11] = '#';
        matriz[9][13] = '#';
        matriz[9][14] = '#';
        matriz[9][15] = '#';
        matriz[9][17] = '#';
        matriz[9][21] = '#';
        matriz[9][25] = '#';
        matriz[10][1] = '#';
        matriz[10][2] = '#';
        matriz[10][4] = '#';
        matriz[10][6] = '#';
        matriz[10][7] = '#';
        matriz[10][8] = '#';
        matriz[10][17] = '#';
        matriz[10][19] = '#';
        matriz[10][20] = '#';
        matriz[10][21] = '#';
        matriz[10][23] = '#';
        matriz[10][24] = '#';
        matriz[10][25] = '#';
        matriz[10][26] = '#';
        matriz[10][27] = '#';
        matriz[11][4] = '#';
        matriz[11][10] = '#';
        matriz[11][14] = '#';
        matriz[11][16] = '#';
        matriz[11][17] = '#';
        matriz[11][21] = '#';
        matriz[12][2] = '#';
        matriz[12][3] = '#';
        matriz[12][4] = '#';
        matriz[12][5] = '#';
        matriz[12][6] = '#';
        matriz[12][8] = '#';
        matriz[12][9] = '#';
        matriz[12][10] = '#';
        matriz[12][11] = '#';
        matriz[12][12] = '#';
        matriz[12][13] = '#';
        matriz[12][14] = '#';
        matriz[12][19] = '#';
        matriz[12][20] = '#';
        matriz[12][21] = '#';
        matriz[12][22] = '#';
        matriz[12][23] = '#';
        matriz[12][24] = '#';
        matriz[12][25] = '#';
        matriz[12][27] = '#';
        matriz[12][28] = '#';
        matriz[13][6] = '#';
        matriz[13][8] = '#';
        matriz[13][16] = '#';
        matriz[13][17] = '#';
        matriz[13][18] = '#';
        matriz[13][19] = '#';
        matriz[13][25] = '#';
        matriz[14][1] = '#';
        matriz[14][2] = '#';
        matriz[14][4] = '#';
        matriz[14][6] = '#';
        matriz[14][8] = '#';
        matriz[14][10] = '#';
        matriz[14][11] = '#';
        matriz[14][12] = '#';
        matriz[14][13] = '#';
        matriz[14][14] = '#';
        matriz[14][15] = '#';
        matriz[14][16] = '#';
        matriz[14][21] = '#';
        matriz[14][22] = '#';
        matriz[14][23] = '#';
        matriz[14][24] = '#';
        matriz[14][25] = '#';
        matriz[14][27] = '#';
        matriz[14][28] = '#';
        matriz[15][4] = '#';
        matriz[15][18] = '#';
        matriz[15][19] = '#';
        matriz[15][25] = '#';
        matriz[16][1] = '#';
        matriz[16][2] = '#';
        matriz[16][3] = '#';
        matriz[16][4] = '#';
        matriz[16][5] = '#';
        matriz[16][6] = '#';
        matriz[16][7] = '#';
        matriz[16][9] = '#';
        matriz[16][11] = '#';
        matriz[16][12] = '#';
        matriz[16][13] = '#';
        matriz[16][16] = '#';
        matriz[16][19] = '#';
        matriz[16][20] = '#';
        matriz[16][21] = '#';
        matriz[16][22] = '#';
        matriz[16][23] = '#';
        matriz[16][24] = '#';
        matriz[16][25] = '#';
        matriz[16][26] = '#';
        matriz[16][27] = '#';
        matriz[17][7] = '#';
        matriz[17][9] = '#';
        matriz[17][10] = '#';
        matriz[17][11] = '#';
        matriz[17][15] = '#';
        matriz[17][16] = '#';
        matriz[17][17] = '#';
        matriz[17][25] = '#';
        matriz[18][2] = '#';
        matriz[18][3] = '#';
        matriz[18][4] = '#';
        matriz[18][6] = '#';
        matriz[18][7] = '#';
        matriz[18][9] = '#';
        matriz[18][13] = '#';
        matriz[18][14] = '#';
        matriz[18][15] = '#';
        matriz[18][17] = '#';
        matriz[18][18] = '#';
        matriz[18][19] = '#';
        matriz[18][20] = '#';
        matriz[18][21] = '#';
        matriz[18][22] = '#';
        matriz[18][24] = '#';
        matriz[18][25] = '#';
        matriz[18][27] = '#';
        matriz[18][28] = '#';
        matriz[19][2] = '#';
        matriz[19][7] = '#';
        matriz[19][8] = '#';
        matriz[19][9] = '#';
        matriz[19][11] = '#';
        matriz[19][12] = '#';
        matriz[19][13] = '#';
        matriz[19][22] = '#';
        matriz[19][25] = '#';
        matriz[19][27] = '#';
        matriz[20][2] = '#';
        matriz[20][4] = '#';
        matriz[20][5] = '#';
        matriz[20][7] = '#';
        matriz[20][11] = '#';
        matriz[20][15] = '#';
        matriz[20][16] = '#';
        matriz[20][17] = '#';
        matriz[20][18] = '#';
        matriz[20][19] = '#';
        matriz[20][20] = '#';
        matriz[20][21] = '#';
        matriz[20][22] = '#';
        matriz[20][23] = '#';
        matriz[20][27] = '#';
        matriz[21][2] = '#';
        matriz[21][5] = '#';
        matriz[21][6] = '#';
        matriz[21][7] = '#';
        matriz[21][9] = '#';
        matriz[21][10] = '#';
        matriz[21][11] = '#';
        matriz[21][13] = '#';
        matriz[21][14] = '#';
        matriz[21][15] = '#';
        matriz[21][23] = '#';
        matriz[21][25] = '#';
        matriz[21][26] = '#';
        matriz[21][27] = '#';
        matriz[22][2] = '#';
        matriz[22][3] = '#';
        matriz[22][4] = '#';
        matriz[22][5] = '#';
        matriz[22][9] = '#';
        matriz[22][17] = '#';
        matriz[22][18] = '#';
        matriz[22][19] = '#';
        matriz[22][20] = '#';
        matriz[22][21] = '#';
        matriz[22][23] = '#';
        matriz[23][3] = '#';
        matriz[23][7] = '#';
        matriz[23][8] = '#';
        matriz[23][9] = '#';
        matriz[23][11] = '#';
        matriz[23][12] = '#';
        matriz[23][13] = '#';
        matriz[23][14] = '#';
        matriz[23][15] = '#';
        matriz[23][16] = '#';
        matriz[23][17] = '#';
        matriz[23][21] = '#';
        matriz[23][23] = '#';
        matriz[23][24] = '#';
        matriz[23][25] = '#';
        matriz[23][26] = '#';
        matriz[23][27] = '#';
        matriz[23][28] = '#';
        matriz[24][2] = '#';
        matriz[24][3] = '#';
        matriz[24][4] = '#';
        matriz[24][5] = '#';
        matriz[24][9] = '#';
        matriz[24][14] = '#';
        matriz[24][19] = '#';
        matriz[24][23] = '#';
        matriz[25][5] = '#';
        matriz[25][6] = '#';
        matriz[25][7] = '#';
        matriz[25][9] = '#';
        matriz[25][10] = '#';
        matriz[25][11] = '#';
        matriz[25][12] = '#';
        matriz[25][16] = '#';
        matriz[25][17] = '#';
        matriz[25][19] = '#';
        matriz[25][21] = '#';
        matriz[25][22] = '#';
        matriz[25][23] = '#';
        matriz[26][2] = '#';
        matriz[26][9] = '#';
        matriz[26][14] = '#';
        matriz[26][16] = '#';
        matriz[26][19] = '#';
        matriz[27][2] = '#';
        matriz[27][4] = '#';
        matriz[27][5] = '#';
        matriz[27][6] = '#';
        matriz[27][7] = '#';
        matriz[27][8] = '#';
        matriz[27][9] = '#';
        matriz[27][11] = '#';
        matriz[27][12] = '#';
        matriz[27][13] = '#';
        matriz[27][14] = '#';
        matriz[27][16] = '#';
        matriz[27][17] = '#';
        matriz[27][18] = '#';
        matriz[27][19] = '#';
        matriz[27][21] = '#';
        matriz[27][22] = '#';
        matriz[27][23] = '#';
        matriz[28][2] = '#';
        matriz[28][11] = '#';
        matriz[28][16] = '#';
        matriz[28][23] = '#';
    }
    else if (laberinto == 2 || laberinto == 3)
    {
        // En esta implementación, los niveles 2 y 3 comparten el layout del 1
        // pero pueden ser modificados para aumentar la dificultad.
        inicializarMatriz(1);
    }

    // Colocación de los items objetivo (Llaves)
    matriz[llave1y][llave1x] = 'L';
    matriz[llave2y][llave2x] = 'L';
    matriz[llave3y][llave3x] = 'L';
}

/**
 * Renderiza el frame actual en consola
 */
void mostrarMatriz()
{
    system("clear || cls");
    cout << "Consigue todas las llaves 'L' para ganar!!!" << endl;
    cout << "Evita a los enemigos 'E'" << endl
         << endl;
    cout << "Usa WASD para moverte | Salir: Q" << endl;
    cout << "---------------------------" << endl;

    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            if (i == y && j == x)
            {
                cout << 'P' << ' '; // Jugador
            }
            else if (i == enemigoY && j == enemigoX)
            {
                cout << 'E' << ' '; // Enemigo
            }
            else
            {
                cout << matriz[i][j] << ' ';
            }
        }
        cout << endl;
    }
    cout << "Llaves: " << contadoroLlaves << " | Vidas: " << vidas << endl;
}

/**
 * Lógica de recolección de items
 */
void verificarLlave()
{
    if ((x == llave1x && y == llave1y) || (x == llave2x && y == llave2y) || (x == llave3x && y == llave3y))
    {
        if (matriz[y][x] == 'L')
        {
            contadoroLlaves++;
            matriz[y][x] = '.'; // Marcar llave como recogida
        }
    }
}

/**
 * IA del Enemigo: Implementa un algoritmo de persecución simple
 * hacia las coordenadas del Jugador cada 3 turnos.
 */
void moverEnemigo()
{
    if (contadorTurnos % 3 == 0)
    {
        if (enemigoX < x)
            enemigoX++;
        else if (enemigoX > x)
            enemigoX--;

        if (enemigoY < y)
            enemigoY++;
        else if (enemigoY > y)
            enemigoY--;
    }
    contadorTurnos++;
}

/**
 * Gestión de colisiones y ciclo de vida del jugador
 */
void verificarColisionYRestarVidas()
{
    if (x == enemigoX && y == enemigoY)
    {
        vidas--;
        if (vidas == 0)
        {
            // Reiniciar estado por Game Over
            vidas = 3;
            contadoroLlaves = 0;
            x = 3;
            y = 3;
            enemigoX = 27;
            enemigoY = 3;

            system("clear || cls");
            cout << "GAME OVER - Reiniciando..." << endl;
            inicializarMatriz(1);
        }
    }
}

/**
 * Lógica de transición de niveles (Progresión)
 */
void Siguientelvl1a2()
{
    if (contadoroLlaves == 3)
    {
        system("clear || cls");
        cout << "Lograste pasar el primer laberinto..." << endl;
        // Reinicio de parámetros para Nivel 2
        inicializarMatriz(2);
        x = 3;
        y = 3;
        enemigoX = 28;
        enemigoY = 2;
        vidas = 3;
        contadoroLlaves = 0;
        lvl_1 = false;
        lvl_2 = true;
    }
}

// [Aquí seguirían las funciones Siguientelvl2a3 y final]

int main()
{
    int Opciones;
    // Título en ASCII Art
    cout << "BIENVENIDO A ADVENTURE LAB" << endl;
    cout << "1. Iniciar Juego" << endl;
    cout << "2. Creditos" << endl;
    cin >> Opciones;

    if (Opciones == 1)
    {
        inicializarMatriz(1);
        lvl_1 = true;

        while (lvl_1 || lvl_2 || lvl_3)
        {
            mostrarMatriz();
            cin >> tecla;

            // Lógica de entrada del usuario (Control de colisiones con paredes)
            if (tecla == 'q')
                break;
            if (tecla == 'w' && y > 1 && matriz[y - 1][x] != '#')
                y--;
            if (tecla == 'a' && x > 1 && matriz[y][x - 1] != '#')
                x--;
            if (tecla == 's' && y < filas - 1 && matriz[y + 1][x] != '#')
                y++;
            if (tecla == 'd' && x < columnas - 1 && matriz[y][x + 1] != '#')
                x++;

            verificarLlave();
            moverEnemigo();
            verificarColisionYRestarVidas();
            if (lvl_1)
                Siguientelvl1a2();
        }
    }
    else if (Opciones == 2)
    {
        cout << "Creado por: Mireles Zaragoza Emiliano" << endl;
    }

    return 0;
}