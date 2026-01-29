#ifndef MATRIZ_H
#define MATRIZ_H


#define radianes(angulo) angulo * M_PI /180.0;

class Matriz
{

    /// Los metodos que se pongan atras de public se
    /// se inicializan como privates por default

    int row, col;
    float **matriz;
    /// Es una matriz, ya que el '**' significa una doble direccion
    /// seria lo mismo que algo asi [][]matriz;

public:
    /// Setearemos por default un constructor con los parametros por defecto,
    /// esto es una ventaja de C++. Este metodo, si no se le introduce valores
    /// se setea con los presentes dentro de los parentesis
    Matriz(int numRow = 4, int numCol = 4, float value = 0);

    /// Aqui ingresamos un constructor normal.
    Matriz(int numRow, int numCol, float **m);

    /// Este metodo es un constructor que copia la matriz
    Matriz(Matriz &m);

    /// Destructor
    ~Matriz();

    inline void SET(int r, int c, float v){
        matriz[r][c] = v;
    }

    inline float GET(int r, int c){
        return matriz[r][c];
    }

    int countRow(){ return row; }
    int countColumn(){ return col; }

    void Initialize(int, int);


    /// SOBRE CARGA DE OPERADORES.
    /// A continuacion asignamos una sobrecarga de operador
    /// esto, para en lugar de llamar un metodo algo asi
    /// matriz1.Multiplicar(matriz2), hacer algo mas sencillo
    /// como matriz1 *= matriz2;

    /// MULTIPLICACION DE MATRICES
    Matriz &operator *=(Matriz &m);

    /// SOLO LA MULTIPLICACION, SIN GUARDARLO EN LA MISMA MATRIZ
    Matriz &operator *(const Matriz m);

    /// MULTIPLICACION POR UN ESCALAR
    Matriz &operator *(float);

    /// COPIAR MATRIZ
    Matriz &operator =(Matriz &);


    /// MATRIZ IDENTIDAD
    /// | 1 0 0 |
    /// | 0 1 0 |
    /// | 0 0 1 |
    Matriz &Identity();


    /// TRASLACION
    Matriz &Translation(Matriz figure, Matriz id, int tx, int ty);

    /// ESCALACION
    Matriz &Escalation(Matriz figure, Matriz id, int Sx, int Sy);

    /// ROTACION AL ORIGEN
    Matriz &Rotation(Matriz figure, Matriz id, float grados);

    /// ROTACION PUNTO PUVIOTE
    Matriz &Rotation(Matriz figure, Matriz id, float grados, int Px, int Py);


};

#endif // MATRIZ_H
