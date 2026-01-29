#include "transformaciones.h"
#include "ui_transformaciones.h"

Transformaciones::Transformaciones(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Transformaciones)
{
    ui->setupUi(this);

    // En el constructor o método de inicialización
    player = new QMediaPlayer(this);
    audioOutput = new QAudioOutput(this);

    player->setAudioOutput(audioOutput);
    player->setSource(QUrl("qrc:/msc/SpaceSong.mp3"));  // Asegúrate que coincida con el recurso

    audioOutput->setVolume(0.25);  // Volumen 50%

    connect(player, &QMediaPlayer::mediaStatusChanged, this, [this](QMediaPlayer::MediaStatus status){
        if (status == QMediaPlayer::EndOfMedia) {
            player->setPosition(0);
            player->play();
        }
    });

    player->play();


    setFigure();
    this->setFocusPolicy(Qt::StrongFocus);
    this->setFocus();  // Opcional: pedir el foco inmediatamente

    timer1 = new QTimer();
    connect(timer1, SIGNAL(timeout()), this, SLOT(rotarAnimacion1()));
    timer2 = new QTimer();
    connect(timer2, SIGNAL(timeout()), this, SLOT(rotarAnimacion2()));

}
int gradosNave = 0;
int evaluateGrados = 0;

Transformaciones::~Transformaciones()
{
    delete ui;
}

void Transformaciones::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    QPainter p(this);
    // Carga la imagen del recurso
    QPixmap fondo(":/img/Espacio.png");

    // Define el rectángulo destino de 500x500 en la esquina superior izquierda
    QRect areaFondo(0, 0, 500, 500);

    // Dibuja la imagen escalada a 500x500
    p.drawPixmap(areaFondo, fondo);

    // // 2. DIBUJO DEL PLANO
    // p.setPen(Qt::white);
    // p.drawLine(0, Ycenter, width, Ycenter);
    // p.drawLine(Xcenter, 0, Xcenter, height);

    // 3. TRIÁNGULO TRANSFORMADO
    Mapeo drawing;
    drawing.setWindow(0,0,width,height);
    drawing.setViewPort(0,0,width,height);

    p.setPen(QColor(255,255,255));
 float xwcenter = 22.5, ywcenter = 32.5;
    for (int i = 0; i < 28; ++i)
    {
        int x1, y1, x2, y2;
        drawing.applyMap(fig[i][0], fig[i][1], x1, y1, Xcenter - xwcenter, Ycenter + ywcenter);
        drawing.applyMap(fig[(i+1) % 28][0], fig[(i+1) % 28][1], x2, y2, Xcenter- xwcenter, Ycenter + ywcenter);
        p.drawLine(x1, y1, x2, y2);
    }
}

void Transformaciones::setFigure()
{
    /// AQUI INDICAMOS LOS PUNTOS QUE TIENE
    /// NUESTRO ARREGLO. ES DECIR, CREAMOS LA FIGRA
    /// EN ESTE CASO, COMO YA LO MENCIONE, FUNCIONA
    /// ASI
    ///          | x1 y1 h1 |
    /// figura = | x2 y2 h2 |
    ///          | x3 y3 h3 |

    fig[0][0] = 5;     fig[0][1] = 5;     fig[0][2] = 1; // 0: A
    fig[1][0] = 5;     fig[1][1] = 25;    fig[1][2] = 1; // 1: B
    fig[2][0] = 10;    fig[2][1] = 25;    fig[2][2] = 1; // 2: C
    fig[3][0] = 10;    fig[3][1] = 50;    fig[3][2] = 1; // 3: D
    fig[4][0] = 15;    fig[4][1] = 50;    fig[4][2] = 1; // 4: E
    fig[5][0] = 15;    fig[5][1] = 55;    fig[5][2] = 1; // 5: F
    fig[6][0] = 20;    fig[6][1] = 55;    fig[6][2] = 1; // 6: G
    fig[7][0] = 20;    fig[7][1] = 60;    fig[7][2] = 1; // 7: H
    fig[8][0] = 25;    fig[8][1] = 60;    fig[8][2] = 1; // 8: I
    fig[9][0] = 25;    fig[9][1] = 55;    fig[9][2] = 1; // 9: J
    fig[10][0] = 30;   fig[10][1] = 55;   fig[10][2] = 1; // 10: K
    fig[11][0] = 30;   fig[11][1] = 50;   fig[11][2] = 1; // 11: L
    fig[12][0] = 35;   fig[12][1] = 50;   fig[12][2] = 1; // 12: M
    fig[13][0] = 35;   fig[13][1] = 25;   fig[13][2] = 1; // 13: N
    fig[14][0] = 40;   fig[14][1] = 25;   fig[14][2] = 1; // 14: O
    fig[15][0] = 40;   fig[15][1] = 5;    fig[15][2] = 1; // 15: P
    fig[16][0] = 35;   fig[16][1] = 5;    fig[16][2] = 1; // 16: Q
    fig[17][0] = 35;   fig[17][1] = 10;   fig[17][2] = 1; // 17: R
    fig[18][0] = 30;   fig[18][1] = 10;   fig[18][2] = 1; // 18: S
    fig[19][0] = 30;   fig[19][1] = 15;   fig[19][2] = 1; // 19: T
    fig[20][0] = 25;   fig[20][1] = 15;   fig[20][2] = 1; // 20: U
    fig[21][0] = 25;   fig[21][1] = 10;   fig[21][2] = 1; // 21: V

    // --- BLOQUE 2: Puntos de (4, 2) a (2, 1) ---
    fig[22][0] = 20;   fig[22][1] = 10;   fig[22][2] = 1; // 22: W
    fig[23][0] = 20;   fig[23][1] = 15;   fig[23][2] = 1; // 23: Z
    fig[24][0] = 15;   fig[24][1] = 15;   fig[24][2] = 1; // 24: A₁
    fig[25][0] = 15;   fig[25][1] = 10;   fig[25][2] = 1; // 25: B₁
    fig[26][0] = 10;   fig[26][1] = 10;   fig[26][2] = 1; // 26: C₁
    fig[27][0] = 10;   fig[27][1] = 5;    fig[27][2] = 1; // 27: D₁

    /// CREAMOS UNA COPIA
    /// NUMERO DE RENGLONES Y DESPUES COLUMANS
    for (int i = 0; i < 28; ++i)
        for (int j = 0; j < 3; ++j)
            figAux[i][j] = fig[i][j];

    width = this->size().width() - ui->widget->width();
    height = this->size().height();

    Xcenter = width/2;
    Ycenter = height/2;

    tx = ty = 0;

}

void Transformaciones::setMappedFigure()
{
    canvas->setPen(QColor(255,0,0));

    /// DUBUJAMOS EL PLANO CARTESIANO
    canvas->drawLine(0,Ycenter,width,Ycenter);
    canvas->drawLine(Xcenter,0,Xcenter,height);

    Mapeo drawing;
    drawing.setWindow(0,0,width,height);
    drawing.setViewPort(0,0,width,height);

    int L = Xcenter;
    int M = Ycenter;
    canvas->setPen(QColor(0,0,255));
    int x1, y1, y2, x2;

    for (int i = 0; i < 27; ++i) {

        drawing.applyMap(fig[i][0],fig[i][1], x1,y1,L,M);
        drawing.applyMap(fig[i+1][0],fig[i+1][1], x2,y2,L,M);
        canvas->drawLine(x1,y1,x2,y2);
    }

}

void Transformaciones::translate(int tx, int ty)
{
    Matriz figNueva, id, figTrans;
    figNueva.Initialize(28,3);
    id.Initialize(3,3);
    figTrans.Initialize(28,3);

    for (int i = 0; i < figNueva.countRow(); ++i) {
        for (int j = 0; j < figNueva.countColumn(); ++j) {
            figNueva.SET(i,j, fig[i][j]);
        }
    }

    figTrans.Translation(figNueva,id,tx,ty);

    for (int i = 0; i < figTrans.countRow(); ++i) {
        for (int j = 0; j < figTrans.countColumn(); ++j) {
            fig[i][j] = figTrans.GET(i,j);
        }
    }

    update();

}

void Transformaciones::escalate(double Sx, double Sy)
{

    Matriz figNueva, id, figEsc;

    figNueva.Initialize(28,3);
    id.Initialize(3,3);
    figEsc.Initialize(28,3);

    for (int i = 0; i < figNueva.countRow(); ++i) {
        for (int j = 0; j < figNueva.countColumn(); ++j) {
            figNueva.SET(i,j, fig[i][j]);
        }
    }

    figEsc.Escalation(figNueva,id,Sx,Sy);
    for (int i = 0; i < figEsc.countRow(); ++i) {
        for (int j = 0; j < figEsc.countColumn(); ++j) {
            fig[i][j] = figEsc.GET(i,j);
        }
    }

    update();
}

Matriz Transformaciones::escalatePivot(Matriz fig, Matriz id, float sX, float sY, float ppX, float ppY)
{
    id.Identity();
    id.SET(0,0,sX);
    id.SET(1,1,sY);

    float escPPX=ppX*(1-sX);
    float escPPY=ppY *(1-sY);
    id.SET(2,0,escPPX);
    id.SET(2,1,escPPY);
    fig*=id;
    //*this. fig;

    return fig;

}


void Transformaciones::keyPressEvent(QKeyEvent *event)
{
    int tx = ui->spinTx->value();
    int ty = ui->spinTy->value();

    // Normaliza evaluateGrados para manejar equivalentes negativos y 360


    if(evaluateGrados == 360 || evaluateGrados == 0)
        evaluateGrados = 0;
    else if(evaluateGrados == 270 || evaluateGrados == -90)
        evaluateGrados = 270;
    else if(evaluateGrados == 180 || evaluateGrados == -180)
        evaluateGrados = 180;
    else if(evaluateGrados == 90 || evaluateGrados == -270)
        evaluateGrados = 90;

    switch (event->key()) {
    case Qt::Key_Right:

            gradosNave = 45;   // Rota hacia la derecha en 45 grados
            on_rotationButton_clicked();

        break;

    case Qt::Key_Left:
            gradosNave = -45;  // Rota hacia la izquierda en 45 grados
            on_rotationButton_clicked();
        break;

    case Qt::Key_Up:
        switch (evaluateGrados) {
        case 0:
            translate(0,ty);
            break;

        case 45:
            translate(tx,ty);
            break;

        case 90:
            translate(tx,0);
            break;

        case 135:
            translate(tx,-ty);
            break;

        case 180:
            translate(0,-ty);
            break;

        case 225:
            translate(-tx,-ty);
            break;

        case 270:
            translate(-tx,0);
            break;

        case 315 :case -45:
            translate(-tx,ty);
            break;

            break;
        }

        break;

    case Qt::Key_Down:
        switch (evaluateGrados) {
        case 0:
            translate(0,-ty);
            break;

        case 45:
            translate(-tx,-ty);
            break;

        case 90:
            translate(-tx,0);
            break;

        case 135:
            translate(-tx,ty);
            break;

        case 180:
            translate(0,ty);
            break;

        case 225:
            translate(tx,ty);
            break;

        case 270:
            translate(tx,0);
            break;

        case 315 :case -45:
            translate(tx,-ty);
            break;

            break;
        }

        break;


    default:
        QDialog::keyPressEvent(event);
        break;
    }
}


void Transformaciones::on_upButton_clicked()
{
    int ty = ui->spinTy->value();
    translate(0, ty);
}

void Transformaciones::on_downButton_clicked()
{
    int ty = ui->spinTy->value();
    translate(0, -ty);
}

void Transformaciones::on_rightButton_clicked()
{
    int tx = ui->spinTx->value();
    translate(tx, 0);
}

void Transformaciones::on_leftButton_clicked()
{
    int tx = ui->spinTx->value();
    translate(-tx, 0);
}

void Transformaciones::on_resetButton_clicked()
{

     gradosNave = 0;
     evaluateGrados = 0;
    timer1->stop();
    timer2->stop();
    setFigure();
 //   setMappedFigure();
    update();
}


void Transformaciones::on_escalarButton_clicked()
{
    double Sx = ui->spinSx->value();
    double Sy = ui->spinSy->value();

    escalate(Sx,Sy);

}




void Transformaciones::on_rotationButton_clicked()
{
    // Calcula centro actual
    float sumX = 0;
    float sumY = 0;
    int n = 28;

    for (int i = 0; i < n; ++i) {
        sumX += fig[i][0];
        sumY += fig[i][1];
    }

    float centroX = sumX / n;
    float centroY = sumY / n;

    /// ORIGINAL PARA QUE GIRE EN PUNTO PIVOTE
    // Matriz figNueva, id, figRot;
    // int grados = ui->thetaSpin->value(),
    //     Px = ui->spinPx->value(),
    //     Py = ui->spinPy->value();

    Matriz figNueva, id, figRot;
    int grados = gradosNave,
        Px = centroX,
        Py = centroY;

    evaluateGrados += gradosNave;



    figNueva.Initialize(28,3);
    id.Initialize(3,3);
    figRot.Initialize(28,3);

    // Copiar fig[][] a figNueva
    for (int i = 0; i < 28; ++i)
        for (int j = 0; j < 3; ++j)
            figNueva.SET(i,j, fig[i][j]);

    // Aplicar la rotación
    figRot.Rotation(figNueva, id, grados, Px, Py);

    // Copiar resultado de regreso a fig[][]
    for (int i = 0; i < 28; ++i)
        for (int j = 0; j < 3; ++j)
            fig[i][j] = figRot.GET(i,j);

    update();

}


void Transformaciones::on_animacion1Button_clicked()
{
    timer2->stop();
    timer1->start(50);

}


void Transformaciones::on_animacion2Button_clicked()
{
    timer1->stop();
    timer2->start(50);

}

void Transformaciones::rotarAnimacion1()
{
    static int angulo = 0;
    static int cont = 0;

    if(cont <= 8){
        angulo = 45;

        if(cont == 8){

            angulo = 0;
            cont = 0;

        }
        double Px = ui->spinPx->value();//20;
        double Py = ui->spinPy->value();//20;
        rotarPuntoFijo(angulo, Px, Py);
        cont++;


    }
}

void Transformaciones::rotarAnimacion2()
{
    static bool dir = 1;
    static int angulo = 0;
    static int cont = 0;

    if(cont <= 9 && dir == 1){

        angulo = 45;
        double Px = 10;
        double Py = 10;
        rotarPuntoFijo(angulo, Px, Py);
        cont++;

        if(cont == 9) angulo = cont = dir = 0;
    }
    if(!dir){
        double Px = 10;
        double Py = 10;
        rotarPuntoFijo(angulo, Px, Py);
        cont++;

        if(cont == 9){

            angulo= cont = 0;
            dir = 1;
            this->rotarPuntoFijo(angulo, Px, Py);
        }
    }


}



void Transformaciones::rotarPuntoFijo(int angulo, int ppx, int ppy)
{
    // Calcula centro actual
    float sumX = 0;
    float sumY = 0;
    int n = 28;

    for (int i = 0; i < n; ++i) {
        sumX += fig[i][0];
        sumY += fig[i][1];
    }

    float centroX = sumX / n;
    float centroY = sumY / n;

    // Ignora parámetros ppx y ppy, los reemplaza por el centro
    ppx = static_cast<int>(centroX);
    ppy = static_cast<int>(centroY);

    Matriz figNueva, id, figRot;
    int grados = angulo;
    int Px = ppx;
    int Py = ppy;

    figNueva.Initialize(28,3);
    id.Initialize(3,3);
    figRot.Initialize(28,3);

    for (int i = 0; i < 28; ++i)
        for (int j = 0; j < 3; ++j)
            figNueva.SET(i,j, fig[i][j]);

    figRot.Rotation(figNueva, id, grados, Px, Py);

    for (int i = 0; i < 28; ++i)
        for (int j = 0; j < 3; ++j)
            fig[i][j] = figRot.GET(i,j);

    update();
}

/*
void Transformaciones::rotarPuntoFijo(int angulo, int ppx, int ppy)
{
    Matriz figNueva, id, figRot;
    int grados = angulo,
        Px = ppx,
        Py = ppy;



    figNueva.Initialize(28,3);
    id.Initialize(3,3);
    figRot.Initialize(28,3);

    // Copiar fig[][] a figNueva
    for (int i = 0; i < 28; ++i)
        for (int j = 0; j < 3; ++j)
            figNueva.SET(i,j, fig[i][j]);

    // Aplicar la rotación
    figRot.Rotation(figNueva, id, grados, Px, Py);

    // Copiar resultado de regreso a fig[][]
    for (int i = 0; i < 28; ++i)
        for (int j = 0; j < 3; ++j)
            fig[i][j] = figRot.GET(i,j);

    update();

}
*/
