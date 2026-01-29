#ifndef TRANSFORMACIONES_H
#define TRANSFORMACIONES_H

#include <QDialog>
#include <QPainter>
#include <QKeyEvent>
#include <QtGui>
#include <QTimer>
#include <QKeyEvent>

#include <QMediaPlayer>
#include <QAudioOutput>

#include "matriz.h"
#include "mapeo.h"


QT_BEGIN_NAMESPACE
namespace Ui {
class Transformaciones;
}
QT_END_NAMESPACE

class Transformaciones : public QDialog
{
    Q_OBJECT

public:
    Transformaciones(QWidget *parent = nullptr);
    ~Transformaciones();

    // METODOS
    void paintEvent(QPaintEvent *event);

    void setFigure();

    void setMappedFigure();

    // TRASFORMACIONES
    void translate(int tx,int ty);

    //  ESCALAR
    void escalate(double Sx, double Sy);

    // ESCALAR PIVOTE
    Matriz escalatePivot(Matriz fig, Matriz id, float sX, float sY, float ppX, float ppY);




    // AHORA CON TECLAS PAPITO
    void keyPressEvent(QKeyEvent *event);

private slots:
    void on_upButton_clicked();

    void on_leftButton_clicked();

    void on_rightButton_clicked();

    void on_downButton_clicked();

    void on_resetButton_clicked();

    void on_escalarButton_clicked();

    void on_rotationButton_clicked();

    void on_animacion1Button_clicked();

    void on_animacion2Button_clicked();

    void rotarAnimacion1();
    void rotarAnimacion2();

    void rotarPuntoFijo(int, int, int);

private:
    Ui::Transformaciones *ui;

    QMediaPlayer *player;
    QAudioOutput *audioOutput;
    QPainter *canvas;
    float fig[28][3], figAux[28][3];

    int width, height,
        Xcenter, Ycenter,
        tx, ty;

    QTimer * timer1, * timer2;
    QTimer *timer3;

    int bgColorR, bgColorG, bgColorB;
    double escalaAnim = 1.0;
    double factorEscala = 0.05;
    int anguloAnim = 0;
    int dx = 0, dy = 0;   // Movimiento hacia el centro


};
#endif // TRANSFORMACIONES_H
