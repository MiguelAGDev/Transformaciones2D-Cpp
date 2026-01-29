#ifndef MAPEO_H
#define MAPEO_H
#include <iostream>
using namespace std;


class Mapeo
{

    // Estas coordenadas son aquellas que se presentan
    /// en la realiadad en la ventada (Window) por ende
    /// puede tener escalas que no son enteroes, sino
    /// con dcimales.
    float XWmin, YWmin, XWmax, YWmax;

    /// Dichas coordenadas seran traspasada al puerto de vision
    /// (View Port), el cual transforma las coordenadas reales
    /// a cordenadas escalabes dentro de un espacion x,y determinado
    /// por el usuario
    int XVPmin, YVPmin, XVPmax, YVPmax;

public:
    //Mapeo();

    /// Este metodo recibe las cordenadasa reales y las representa
    /// de manera exacta en el view port. No importa si es demasiado
    /// pequenha que ocupa un espacion cas imperceptible o demasiado grande
    /// que no vemos sus dimensiones.
    void setWindow(float Xw1, float Yw1, float Xw2, float Yw2);


    ///Este recibe las cordenadas y las inicializa dentro de nuestro
    /// campo de vision (View Port), el cual en este caso sera de
    /// 500px * 500px
    void setViewPort(int Xvp1,int Yvp1,int Xvp2,int Yvp2);

    /// Despeus de recibir las coordenadas reales, es decir cada punto
    /// del mundo real, se mapean para convertir cada punto de la ventana
    /// (Window) a un punto del puerto de vision (View Port).

    /// ESTE METODO ESCALA Y TRANSLADA LOS PUNTOS EN EL PUERTO DE VISION
    /// L Y M REPRESENTAN EL ORIGEN DESDE DONDE SE DIBUJARA
    void applyMap(int, int, int &Xvp, int &Yvp, int L, int M);


};

#endif // MAPEO_H
