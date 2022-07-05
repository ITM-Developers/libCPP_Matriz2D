# Cpp_Class_Matriz2D
Es una clase que permite crear matrices de diferentes tipos de datos, la idea es tener un conjunto de metodos comunes asociados a las matrices en esta clase y que pueda ser utilizada con facilidad.

La manera de utlizar la clase es primero importarla en el archivo que deseas usarla, por ejemplo:
```cpp
#include "Matriz2D.h"
```
Despues se debe crear una instancia de la clase, en el ejemplo de abajo se crean dos matrices de int's y dos de float's todas de (3x3) 3 filas por 3 columnas:
```cpp
Matriz<int> a(3,3);
Matriz<int> b(3,3);

Matriz<float> c(3,3);
Matriz<float> d(3,3);
```

## Metodo setYX()
Asigna un valor en la poscicion YX de la matriz, es muy importante notar que primero se especifica la Y (fila) y luego la X (Columna). El siguiente ejemplo llena una matriz de 3x3 con valores de 1 en todas sus filas y columnas.
```cpp
Matriz<int> a(3,3);
Matriz<int> b(3,3);

int valor = 1;
for(int i=1; i<=3; i++)
{
    for(int j=1; j<=3; j++)
    {
        a.setYX(valor, i, j);
        b.setYX(valor, i, j);
        valor++;
    }
}
```
## Metodo getYX()
Obtiene el valor de una posicion en la matriz.

```cpp
Matriz<int> a(3,3);
Matriz<int> b(3,3);

int valor = 1;
for(int i=1; i<=3; i++)
{
    for(int j=1; j<=3; j++)
    {
        a.setYX(valor, i, j);
        b.setYX(valor, i, j);
        valor++;
    }
}

cout << endl << b.getYX(1,1);
cout << endl << b.getYX(1,2);
cout << endl << b.getYX(1,3);
cout << endl << b.getYX(2,1);
cout << endl << b.getYX(2,2);
cout << endl << b.getYX(2,3);
cout << endl << b.getYX(3,1);
cout << endl << b.getYX(3,2);
cout << endl << b.getYX(3,3);
```
## Metodo print()
Sirve para imprimir todos los valores de la matriz en la pantalla (STANDARD OUTPUT).
```cpp
Matriz<int> a(3,3);
Matriz<int> b(3,3);

int valor = 1;
for(int i=1; i<=3; i++)
{
    for(int j=1; j<=3; j++)
    {
        a.setYX(valor, i, j);
        b.setYX(valor, i, j);
        valor++;
    }
}

cout << "Matriz a" << endl;
a.print();

cout << "Matriz b" << endl;
b.print();
```
