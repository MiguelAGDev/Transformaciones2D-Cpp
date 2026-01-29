/********************************************************************************
** Form generated from reading UI file 'transformaciones.ui'
**
** Created by: Qt User Interface Compiler version 6.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TRANSFORMACIONES_H
#define UI_TRANSFORMACIONES_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Transformaciones
{
public:
    QWidget *widget;
    QLabel *titlLabel;
    QLabel *tx_label;
    QSpinBox *spinTx;
    QSpinBox *spinTy;
    QLabel *ty_label;
    QPushButton *upButton;
    QPushButton *downButton;
    QPushButton *leftButton;
    QPushButton *rightButton;
    QPushButton *resetButton;
    QSpinBox *spinSy;
    QLabel *sx_label;
    QSpinBox *spinSx;
    QLabel *sy_label;
    QPushButton *escalarButton;
    QSpinBox *thetaSpin;
    QLabel *thetha;
    QPushButton *rotationButton;
    QLabel *tx_label_2;
    QSpinBox *spinPy;
    QLabel *ty_label_2;
    QSpinBox *spinPx;
    QPushButton *animacion1Button;
    QPushButton *animacion2Button;
    QPushButton *animacion3Button;

    void setupUi(QDialog *Transformaciones)
    {
        if (Transformaciones->objectName().isEmpty())
            Transformaciones->setObjectName("Transformaciones");
        Transformaciones->resize(700, 500);
        widget = new QWidget(Transformaciones);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(500, 0, 200, 500));
        widget->setStyleSheet(QString::fromUtf8("background-color: rgb(60, 60, 60);"));
        titlLabel = new QLabel(widget);
        titlLabel->setObjectName("titlLabel");
        titlLabel->setGeometry(QRect(10, 10, 180, 30));
        titlLabel->setStyleSheet(QString::fromUtf8("font: 700 16pt \"Arial\";"));
        titlLabel->setAlignment(Qt::AlignmentFlag::AlignCenter);
        tx_label = new QLabel(widget);
        tx_label->setObjectName("tx_label");
        tx_label->setGeometry(QRect(20, 40, 30, 30));
        tx_label->setStyleSheet(QString::fromUtf8("font: 700 12pt \"Arial\";"));
        tx_label->setAlignment(Qt::AlignmentFlag::AlignCenter);
        spinTx = new QSpinBox(widget);
        spinTx->setObjectName("spinTx");
        spinTx->setGeometry(QRect(60, 40, 131, 21));
        spinTx->setStyleSheet(QString::fromUtf8("\n"
"font: 12pt \"Arial\";"));
        spinTx->setAlignment(Qt::AlignmentFlag::AlignCenter);
        spinTy = new QSpinBox(widget);
        spinTy->setObjectName("spinTy");
        spinTy->setGeometry(QRect(60, 70, 131, 21));
        spinTy->setStyleSheet(QString::fromUtf8("font:  12pt \"Arial\";"));
        spinTy->setAlignment(Qt::AlignmentFlag::AlignCenter);
        ty_label = new QLabel(widget);
        ty_label->setObjectName("ty_label");
        ty_label->setGeometry(QRect(20, 60, 30, 30));
        ty_label->setStyleSheet(QString::fromUtf8("font: 700 12pt \"Arial\";"));
        ty_label->setAlignment(Qt::AlignmentFlag::AlignCenter);
        upButton = new QPushButton(widget);
        upButton->setObjectName("upButton");
        upButton->setEnabled(true);
        upButton->setGeometry(QRect(80, 160, 40, 40));
        upButton->setStyleSheet(QString::fromUtf8("font: 14pt \"Arial\";"));
        downButton = new QPushButton(widget);
        downButton->setObjectName("downButton");
        downButton->setEnabled(true);
        downButton->setGeometry(QRect(80, 200, 40, 40));
        downButton->setStyleSheet(QString::fromUtf8("font: 14pt \"Arial\";"));
        leftButton = new QPushButton(widget);
        leftButton->setObjectName("leftButton");
        leftButton->setEnabled(true);
        leftButton->setGeometry(QRect(40, 200, 40, 40));
        leftButton->setStyleSheet(QString::fromUtf8("font: 14pt \"Arial\";"));
        rightButton = new QPushButton(widget);
        rightButton->setObjectName("rightButton");
        rightButton->setEnabled(true);
        rightButton->setGeometry(QRect(120, 200, 40, 40));
        rightButton->setStyleSheet(QString::fromUtf8("font: 14pt \"Arial\";"));
        resetButton = new QPushButton(widget);
        resetButton->setObjectName("resetButton");
        resetButton->setGeometry(QRect(10, 460, 180, 25));
        resetButton->setStyleSheet(QString::fromUtf8("font: 700 12pt \"Arial\";"));
        spinSy = new QSpinBox(widget);
        spinSy->setObjectName("spinSy");
        spinSy->setGeometry(QRect(50, 290, 131, 20));
        spinSy->setStyleSheet(QString::fromUtf8("font:  12pt \"Arial\";"));
        spinSy->setAlignment(Qt::AlignmentFlag::AlignCenter);
        sx_label = new QLabel(widget);
        sx_label->setObjectName("sx_label");
        sx_label->setGeometry(QRect(10, 260, 30, 20));
        sx_label->setStyleSheet(QString::fromUtf8("font: 700 12pt \"Arial\";"));
        sx_label->setAlignment(Qt::AlignmentFlag::AlignCenter);
        spinSx = new QSpinBox(widget);
        spinSx->setObjectName("spinSx");
        spinSx->setGeometry(QRect(50, 260, 131, 20));
        spinSx->setStyleSheet(QString::fromUtf8("\n"
"font: 12pt \"Arial\";"));
        spinSx->setAlignment(Qt::AlignmentFlag::AlignCenter);
        sy_label = new QLabel(widget);
        sy_label->setObjectName("sy_label");
        sy_label->setGeometry(QRect(10, 290, 30, 20));
        sy_label->setStyleSheet(QString::fromUtf8("font: 700 12pt \"Arial\";"));
        sy_label->setAlignment(Qt::AlignmentFlag::AlignCenter);
        escalarButton = new QPushButton(widget);
        escalarButton->setObjectName("escalarButton");
        escalarButton->setGeometry(QRect(10, 320, 180, 25));
        escalarButton->setStyleSheet(QString::fromUtf8("font: 700 12pt \"Arial\";"));
        thetaSpin = new QSpinBox(widget);
        thetaSpin->setObjectName("thetaSpin");
        thetaSpin->setGeometry(QRect(70, 360, 111, 20));
        thetaSpin->setStyleSheet(QString::fromUtf8("\n"
"font: 12pt \"Arial\";"));
        thetaSpin->setAlignment(Qt::AlignmentFlag::AlignCenter);
        thetaSpin->setMinimum(-360);
        thetaSpin->setMaximum(360);
        thetha = new QLabel(widget);
        thetha->setObjectName("thetha");
        thetha->setGeometry(QRect(10, 360, 51, 20));
        thetha->setStyleSheet(QString::fromUtf8("font: 700 12pt \"Arial\";"));
        thetha->setAlignment(Qt::AlignmentFlag::AlignCenter);
        rotationButton = new QPushButton(widget);
        rotationButton->setObjectName("rotationButton");
        rotationButton->setGeometry(QRect(10, 390, 180, 25));
        rotationButton->setStyleSheet(QString::fromUtf8("font: 700 12pt \"Arial\";"));
        tx_label_2 = new QLabel(widget);
        tx_label_2->setObjectName("tx_label_2");
        tx_label_2->setGeometry(QRect(20, 100, 30, 30));
        tx_label_2->setStyleSheet(QString::fromUtf8("font: 700 12pt \"Arial\";"));
        tx_label_2->setAlignment(Qt::AlignmentFlag::AlignCenter);
        spinPy = new QSpinBox(widget);
        spinPy->setObjectName("spinPy");
        spinPy->setGeometry(QRect(60, 130, 131, 21));
        spinPy->setStyleSheet(QString::fromUtf8("font:  12pt \"Arial\";"));
        spinPy->setAlignment(Qt::AlignmentFlag::AlignCenter);
        spinPy->setMinimum(-250);
        spinPy->setMaximum(250);
        ty_label_2 = new QLabel(widget);
        ty_label_2->setObjectName("ty_label_2");
        ty_label_2->setGeometry(QRect(20, 120, 30, 30));
        ty_label_2->setStyleSheet(QString::fromUtf8("font: 700 12pt \"Arial\";"));
        ty_label_2->setAlignment(Qt::AlignmentFlag::AlignCenter);
        spinPx = new QSpinBox(widget);
        spinPx->setObjectName("spinPx");
        spinPx->setGeometry(QRect(60, 100, 131, 21));
        spinPx->setStyleSheet(QString::fromUtf8("\n"
"font: 12pt \"Arial\";"));
        spinPx->setAlignment(Qt::AlignmentFlag::AlignCenter);
        spinPx->setMinimum(-250);
        spinPx->setMaximum(250);
        animacion1Button = new QPushButton(widget);
        animacion1Button->setObjectName("animacion1Button");
        animacion1Button->setGeometry(QRect(10, 430, 55, 25));
        animacion1Button->setStyleSheet(QString::fromUtf8("font: 700 12pt \"Arial\";"));
        animacion2Button = new QPushButton(widget);
        animacion2Button->setObjectName("animacion2Button");
        animacion2Button->setGeometry(QRect(75, 430, 55, 25));
        animacion2Button->setStyleSheet(QString::fromUtf8("font: 700 12pt \"Arial\";"));
        animacion3Button = new QPushButton(widget);
        animacion3Button->setObjectName("animacion3Button");
        animacion3Button->setGeometry(QRect(140, 430, 50, 25));
        animacion3Button->setStyleSheet(QString::fromUtf8("font: 700 12pt \"Arial\";"));

        retranslateUi(Transformaciones);

        QMetaObject::connectSlotsByName(Transformaciones);
    } // setupUi

    void retranslateUi(QDialog *Transformaciones)
    {
        Transformaciones->setWindowTitle(QCoreApplication::translate("Transformaciones", "Transformaciones", nullptr));
        titlLabel->setText(QCoreApplication::translate("Transformaciones", "Transformacion", nullptr));
        tx_label->setText(QCoreApplication::translate("Transformaciones", "Tx:", nullptr));
        ty_label->setText(QCoreApplication::translate("Transformaciones", "Ty:", nullptr));
        upButton->setText(QCoreApplication::translate("Transformaciones", "\360\237\224\274", nullptr));
        downButton->setText(QCoreApplication::translate("Transformaciones", "\360\237\224\275", nullptr));
        leftButton->setText(QCoreApplication::translate("Transformaciones", "\342\227\200\357\270\217", nullptr));
        rightButton->setText(QCoreApplication::translate("Transformaciones", "\342\226\266\357\270\217", nullptr));
        resetButton->setText(QCoreApplication::translate("Transformaciones", "Reiniciar ", nullptr));
        sx_label->setText(QCoreApplication::translate("Transformaciones", "Sx:", nullptr));
        sy_label->setText(QCoreApplication::translate("Transformaciones", "Sy:", nullptr));
        escalarButton->setText(QCoreApplication::translate("Transformaciones", "Escalar", nullptr));
        thetha->setText(QCoreApplication::translate("Transformaciones", "Theta:", nullptr));
        rotationButton->setText(QCoreApplication::translate("Transformaciones", "Rotar", nullptr));
        tx_label_2->setText(QCoreApplication::translate("Transformaciones", "Px:", nullptr));
        ty_label_2->setText(QCoreApplication::translate("Transformaciones", "Py:", nullptr));
        animacion1Button->setText(QCoreApplication::translate("Transformaciones", "1", nullptr));
        animacion2Button->setText(QCoreApplication::translate("Transformaciones", "2", nullptr));
        animacion3Button->setText(QCoreApplication::translate("Transformaciones", "3", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Transformaciones: public Ui_Transformaciones {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRANSFORMACIONES_H
