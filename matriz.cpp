#include "matriz.h"
#include <math.h>
#include <assert.h>

/// CONSTRUCTOR POR DEFECTO Y VALORES INICIALES
Matriz::Matriz(int numRow, int numCol, float value)
{
    row = numRow;
    col = numCol;  /// Corregido (antes tomaba numRow dos veces por error)

    /// Se crea un arreglo que contiene direcciones (*)
    /// de vectores. Por ejemplo, si inicializamos el numero
    /// de row = 3, seria algo asi
    ///     | * [0,1,2,3] | cada fila guarda la direccion
    /// m = | * [0,1,2,3] | de un vector, lo cual hace que
    ///     | * [0,1,2,3] | sea una matriz
    matriz = new float*[row];
    assert(matriz);

    for (int i = 0; i < row; ++i) {
        matriz[i] = new float[col];
        assert(matriz[i]);
    }

    /// Inicializa todos los elementos con el valor dado
    for (int i = 0; i < row; ++i)
        for (int j = 0; j < col; ++j)
            matriz[i][j] = value;
}

/// CONSTRUCTOR QUE COPIA LOS DATOS DE OTRA MATRIZ
Matriz::Matriz(int numRow, int numCol, float **m)
{
    row = numRow;
    col = numCol;

    matriz = new float *[row];
    assert(matriz);

    for (int i = 0; i < row; ++i) {
        matriz[i] = new float[col];
        assert(matriz[i]);
    }

    /// Copia los datos de la matriz externa m
    for (int i = 0; i < row; ++i)
        for (int j = 0; j < col; ++j)
            this->matriz[i][j] = m[i][j];
}

/// CONSTRUCTOR DE COPIA
Matriz::Matriz(Matriz &m)
{
    row = m.countRow();
    col = m.countColumn();

    matriz = new float*[row];
    assert(matriz);

    for (int i = 0; i < row; ++i) {
        matriz[i] = new float[col];
        assert(matriz[i]);
    }

    /// Copia cada elemento usando GET
    for (int i = 0; i < row; ++i)
        for (int j = 0; j < col; ++j)
            matriz[i][j] = m.GET(i, j);
}

/// DESTRUCTOR - libera la memoria dinámica
Matriz::~Matriz()
{
    /// Elimina cada vector al que se apunta
    for (int i = 0; i < row; ++i)
        delete[] matriz[i];

    /// Elimina el arreglo de punteros
    delete[] matriz;
}

/// INICIALIZA LA MATRIZ A UN TAMAÑO Y LLENA DE CEROS
void Matriz::Initialize(int R, int C)
{
    /// Si ya hay memoria asignada, liberar primero para evitar fuga
    if (matriz) {
        for (int i = 0; i < row; ++i)
            delete[] matriz[i];
        delete[] matriz;
    }

    row = R;
    col = C;

    matriz = new float*[row];
    assert(matriz);

    for (int i = 0; i < row; ++i) {
        matriz[i] = new float[col];
        assert(matriz[i]);
    }

    /// Inicializa con ceros
    for (int i = 0; i < row; ++i)
        for (int j = 0; j < col; ++j)
            matriz[i][j] = 0;
}

/// SOBRE CARGA DEL OPERADOR *= PARA MULTIPLICAR MATRICES
Matriz& Matriz::operator*=(Matriz &m)
{
    Matriz aux;
    aux.Initialize(row, m.countColumn());

    for (int i = 0; i < row; ++i)
    {
        for (int j = 0; j < m.countColumn(); ++j)
        {
            float suma = 0;
            for (int k = 0; k < col; ++k)
            {
                suma += (matriz[i][k] * m.GET(k, j));
            }
            aux.SET(i, j, suma);
        }
    }

    return *this = aux;
}

/// MULTIPLICACION DE MATRIZ POR ESCALAR
Matriz& Matriz::operator*(float val)
{
    Matriz* temp = new Matriz(row, col);

    for (int i = 0; i < row; ++i)
        for (int j = 0; j < col; ++j)
            temp->SET(i, j, matriz[i][j] * val);

    return *temp;
}

/// MULTIPLICACION DE MATRICES SIN GUARDAR EN LA MISMA MATRIZ
Matriz& Matriz::operator*(const Matriz m)
{
    Matriz* result = new Matriz(row, m.col);
    assert(result);

    for (int i = 0; i < row; ++i)
        for (int j = 0; j < m.col; ++j)
            for (int k = 0; k < col; ++k)
                result->matriz[i][j] += matriz[i][k] * m.matriz[k][j];

    return *result;
}

/// SOBRE CARGA DEL OPERADOR = PARA ASIGNACION PROFUNDA
Matriz& Matriz::operator=(Matriz &m)
{
    /// Liberar memoria anterior
    for (int i = 0; i < row; ++i)
        delete[] matriz[i];
    delete[] matriz;

    /// Asignar nuevo tamaño y reservar memoria
    row = m.countRow();
    col = m.countColumn();

    matriz = new float*[row];
    assert(matriz);

    for (int i = 0; i < row; ++i) {
        matriz[i] = new float[col];
        assert(matriz[i]);
    }

    /// Copiar los datos
    for (int i = 0; i < row; ++i)
        for (int j = 0; j < col; ++j)
            matriz[i][j] = m.matriz[i][j];

    return *this;
}

/// MATRIZ IDENTIDAD (1 en diagonal, 0 fuera)
Matriz& Matriz::Identity()
{
    for (int i = 0; i < row; ++i)
        for (int j = 0; j < col; ++j)
            matriz[i][j] = (i == j) ? 1 : 0;

    return *this;
}

/// MATRIZ TRASLACION
Matriz& Matriz::Translation(Matriz figure, Matriz id, int tx, int ty)
{
    id.Identity();

    /// ESTA MAL IMPLEMENTADA, PERO FUNCIONA PARA FIGURAS EN FILAS
    id.SET(2, 0, tx);
    id.SET(2, 1, ty);

    figure *= id;

    return *this = figure;
}

/// ESCALACION RESPECTO AL PRIMER PUNTO (PIVOTE)
Matriz& Matriz::Escalation(Matriz figure, Matriz id, int Sx, int Sy)
{
    int puntos = figure.countRow();

    float Xo = figure.GET(0, 0);
    float Yo = figure.GET(0, 1);

    for (int i = 0; i < puntos; ++i)
    {
        float x = figure.GET(i, 0);
        float y = figure.GET(i, 1);

        float x_n = (x - Xo) * Sx + Xo;
        float y_n = (y - Yo) * Sy + Yo;

        figure.SET(i, 0, x_n);
        figure.SET(i, 1, y_n);
    }

    return *this = figure;
}

/// ROTACIÓN AL ORIGEN (0,0)
Matriz& Matriz::Rotation(Matriz figure, Matriz id, float grados)
{
    float rad = grados * M_PI / 180.0;

    float c = cos(rad);
    float s = sin(rad);

    /// Matriz identidad base
    id.Identity();

    /// Matriz de rotación correcta:
    /// | cos -sin  0 |
    /// | sin  cos  0 |
    /// |  0    0   1 |

    id.SET(0,0, c);
    id.SET(0,1,-s);
    id.SET(1,0, s);
    id.SET(1,1, c);

    /// MULTIPLICA LA FIGURA POR LA MATRIZ DE ROTACIÓN
    figure *= id;

    return *this = figure;
}

Matriz &Matriz::Rotation(Matriz figure, Matriz id, float grados, int Px, int Py)
{

    /// Matriz identidad base
    id.Identity();

    float rad = grados * M_PI / 180.0;

    float c = cos(rad);
    float s = sin(rad);

    /// Matriz de rotación correcta:
    /// | cos -sin  0 |
    /// | sin  cos  0 |
    /// |  0    0   1 |

    id.SET(0,0, c);
    id.SET(0,1,-s);
    id.SET(1,0, s);
    id.SET(1,1, c);
    float reng2_0 = Px* (1 - c) - Py * s;
    float reng2_1 = Py* (1 - c) + Px * s;

    id.SET(2,0, reng2_0);
    id.SET(2,1, reng2_1);

    /// MULTIPLICA LA FIGURA POR LA MATRIZ DE ROTACIÓN
    figure *= id;

    return *this = figure;

}
