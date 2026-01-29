#include "mapeo.h"
#include <math.h>

//Mapeo::Mapeo() {}



void Mapeo::setWindow(float Xw1, float Yw1, float Xw2, float Yw2)
{
    /// Como el mismo nombre del metodo lo dice
    /// seteamos todas las cordenas en las variables que tenemos
    /// siendo X y Y minimo, el punto mas pequenho para despues
    /// X y Y maximo, el punto mas alto.
    XWmin = Xw1;
    YWmin = Yw1;
    XWmax = Xw2;
    YWmax = Yw2;

}

void Mapeo::setViewPort(int Xvp1, int Yvp1, int Xvp2, int Yvp2)
{
    /// Este metodo hace lo mismo que el anterior, solamente recibe las coordenasa
    /// y las inicializa en las variables que tenemso

    XVPmin = Xvp1;
    YVPmin = Yvp1;
    XVPmax= Xvp2;
    YVPmax= Yvp2;


}

void Mapeo::applyMap(int Xw, int Yw, int &Xvp, int &Yvp, int L, int M)
{

    /// El metodo de mapero loq ue hace es escalar los puntos recibidos en las variables
    /// de ventada y los translada al puerto de vision, es decir, por cada punto en el
    /// mundo real, se genera uno en el View Port

    float Sx, Sy;

    // Lo que hace esta operacion es solamente obtener el multiplicador, para escalar la imagen
    // al valor exacto para verlo en nuestro View Port

    Sx = (XVPmax - XVPmin) / (XWmax - XWmin);
    Sy = (YVPmax - YVPmin) / (YWmax - YWmin);

    cout<<"Factor de escalacion X: "<<Sx<<endl;
    cout<<"Factor de escalacion Y: "<<Sy<<endl;


    // L y M representan el origen desde donde ibujamos
    Xvp = int(round(Sx*(Xw-XWmin) )+ XVPmin + L);
    Yvp = int(round(Sy*(YWmin-Yw) ) - YVPmin + M);


}


