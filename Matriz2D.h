#ifndef IOSTREAM_H
    #define IOSTREAM_H
    #include <iostream>
#endif

#ifndef ALGORITHM_H
    #define ALGORITHM_H
    #include <algorithm>
#endif

#ifndef STRING_H
    #define STRING_H
    #include <string>
#endif

#ifndef MATRIZ_2D_H
#define MATRIZ_2D_H

using namespace std;

template <class T>
class Matriz2D
{
private:
    size_t ROWS;        // Numero de Filas en la matriz
    size_t COLS;        // NUmero de Columnas en la matriz
    T **matrix;
public:
    Matriz2D( size_t ROWS, size_t COLS);
    ~Matriz2D();

    void setYX(T value, size_t ROW, size_t COL) const;
    T getYX(size_t ROW, size_t COL) const;

    size_t getNumRows() const{ return this->ROWS; }
    size_t getNumCols() const{ return this->COLS; }

    void print();
    Matriz2D<T> operator+(const Matriz2D<T> &b) const;
};


/**
 * Contructor()
 * ======================================================================================================================
 * En este contructor se le pasa como parametro el numero de filas y el numero de columnas de la matriz,  al  momento  de
 * entrar en el constructor separa espacio de memoria para crear una matriz de ROWS x COLS. Debido a que es una plantilla
 * cuando se usa este metodo los datos tendran basura.
 * ======================================================================================================================
 */
template <class T>
Matriz2D<T>::Matriz2D(size_t ROWS, size_t COLS)
{
    this->ROWS  = ROWS;
    this->COLS  = COLS;

    this->matrix = new T*[ROWS];

    for(size_t i=0; i < ROWS; i++)
    {
        this->matrix[i] = new T[COLS];
    }
}


/**
 * Destructor()
 * ======================================================================================================================
 * En este metodo se libera toda  la  memoria  que es apartada de manera dinamica por la clase, no es necesario  llamarlo
 * ya que se hace de manera implicita.
 * ======================================================================================================================
 */
template <class T>
Matriz2D<T>::~Matriz2D()
{
    for(size_t i = 0; i < this->ROWS; i++)
    {
        delete[] this->matrix[i];                   // Borramos las columnas de la matriz
    }
    delete[] this->matrix;                          // Borramos las filas de la matriz
}


/**
 * setYX()
 * ======================================================================================================================
 * Recordar que una matriz es una tabla, un arreglo bidimensional.. etc. Por lo tanto se decidio agregar este metodo para
 * acceder a los datos de la matriz de forma sencilla como si fuera un mapa en un plano cartesiano, NOTA: observar que el
 * metodo tiene como nombre Y y luego X, haciendo referencia a que primero se indica la coordenada Y y luego la X.Tambien
 * cabe aclarar que las coordenadas 0,0 empiezan en la esquina superior izquierda y las ultimas coordenadas son las de la
 * esquina inferior derecha.
 *
 * @param y     un entero positivo que indica el numero de la coordenada y (La FILA).
 * @param x     un entero positivo que indica el numero de la coordenada x (La COLUMNA).
 *
 * @return T    el tipo de dato que almacena (un objeto de class T).
 */
template <class T>
void Matriz2D<T>::setYX( T value, size_t ROW, size_t COL) const
{
    // SI LA COLUMNA EXCEDE LOS LIMITES DEL ARRAY
    if( COL > this->COLS || COL < 1)
    {
        throw "Intentaste acceder a una posicion mas alla de (x) en la matriz actual. Recuerda que Empieza en 1";
    }

    // SI LA FILA EXCEDE LOS LIMITES DEL ARRAY
    if( ROW > this->ROWS || ROW < 1)
    {
        throw "Intentaste acceder a una posicion mas alla de (y) en la matriz actual. Recuerda que Empieza en 1";
    }

    this->matrix[ROW-1][COL-1] = value;
}


template <class T>
T Matriz2D<T>::getYX( size_t ROW, size_t COL) const
{
    if( ROW > this->ROWS || ROW < 1)
    {
        throw "Intentaste acceder a una posicion mas alla de (y) en la matriz actual";
    }
    if( COL > this->COLS || COL < 1)
    {
        throw "Intentaste acceder a una posicion mas alla de (x) en la matriz actual";
    }
    return this->matrix[ROW-1][COL-1];
}


template <class T>
void Matriz2D<T>::print()
{
    for(size_t ROW = 0; ROW < this->ROWS; ROW++)
    {
        for(size_t COL = 0; COL < this->COLS; COL++)
        {
            cout << this->matrix[ROW][COL] << " ";
        }
        cout << "\n";
    }
}


//PENDIENTE VERIFICAR
template <class T>
Matriz2D<T> Matriz2D<T>::operator+(const Matriz2D<T> &b) const
{
    // CREAMOS UNA NUEVA MATRIX QUE VA A GUARDAR EL RESULTADO
    Matriz2D<T> r( this->ROWS, this->COLS);

    for(int ROW = 1; ROW <= this->ROWS; ROW++)
    {
        for(int COL = 1; COL <= this->COLS; COL++)
        {
            T a_xy;
            T b_xy;

            // INTENTAMOS LEER EL VALOR XY DE LA MATRIZ 1
            try {
                a_xy = this->getYX(ROW, COL);
            } catch (...)
            {

            }

            // INTENTAMOS LEER EL VALOR XY DE LA MATRIZ 2
            try {
                b_xy = b.getYX(ROW, COL);
            } catch (...) {

            }
            //cout << a_xy << " + " << b_xy << endl;

            r.setYX(a_xy + b_xy, ROW, COL);
        }
    }
    return r;
}
#endif // MATRIZ_2D_H
