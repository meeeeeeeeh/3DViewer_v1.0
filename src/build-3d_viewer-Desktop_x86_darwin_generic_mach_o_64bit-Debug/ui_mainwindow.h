/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "glwidget.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_2;
    QPushButton *file_path;
    QLabel *label_4;
    QLabel *label_file;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label;
    QLabel *label_vert;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_2;
    QLabel *label_edges;
    QSpacerItem *verticalSpacer;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QDoubleSpinBox *X;
    QDoubleSpinBox *Y;
    QDoubleSpinBox *Z;
    QPushButton *move;
    QHBoxLayout *horizontalLayout_4;
    QDoubleSpinBox *R_X;
    QDoubleSpinBox *R_Y;
    QDoubleSpinBox *R_Z;
    QPushButton *rotate;
    QSlider *horizontalSlider;
    QPushButton *resize;
    QCheckBox *checkBox;
    QPushButton *quit;
    GLWidget *GLwidget;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(921, 735);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(800, 600));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        file_path = new QPushButton(centralwidget);
        file_path->setObjectName(QString::fromUtf8("file_path"));

        verticalLayout_2->addWidget(file_path);

        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy1);

        verticalLayout_2->addWidget(label_4);

        label_file = new QLabel(centralwidget);
        label_file->setObjectName(QString::fromUtf8("label_file"));

        verticalLayout_2->addWidget(label_file);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_7->addWidget(label);

        label_vert = new QLabel(centralwidget);
        label_vert->setObjectName(QString::fromUtf8("label_vert"));

        horizontalLayout_7->addWidget(label_vert);


        verticalLayout_2->addLayout(horizontalLayout_7);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_8->addWidget(label_2);

        label_edges = new QLabel(centralwidget);
        label_edges->setObjectName(QString::fromUtf8("label_edges"));

        horizontalLayout_8->addWidget(label_edges);


        verticalLayout_2->addLayout(horizontalLayout_8);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        X = new QDoubleSpinBox(centralwidget);
        X->setObjectName(QString::fromUtf8("X"));
        X->setMinimum(-99.000000000000000);

        horizontalLayout_2->addWidget(X);

        Y = new QDoubleSpinBox(centralwidget);
        Y->setObjectName(QString::fromUtf8("Y"));
        Y->setMinimum(-99.000000000000000);

        horizontalLayout_2->addWidget(Y);

        Z = new QDoubleSpinBox(centralwidget);
        Z->setObjectName(QString::fromUtf8("Z"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(Z->sizePolicy().hasHeightForWidth());
        Z->setSizePolicy(sizePolicy2);
        Z->setMinimum(-99.000000000000000);
        Z->setValue(0.000000000000000);

        horizontalLayout_2->addWidget(Z);


        verticalLayout->addLayout(horizontalLayout_2);

        move = new QPushButton(centralwidget);
        move->setObjectName(QString::fromUtf8("move"));

        verticalLayout->addWidget(move);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        R_X = new QDoubleSpinBox(centralwidget);
        R_X->setObjectName(QString::fromUtf8("R_X"));

        horizontalLayout_4->addWidget(R_X);

        R_Y = new QDoubleSpinBox(centralwidget);
        R_Y->setObjectName(QString::fromUtf8("R_Y"));

        horizontalLayout_4->addWidget(R_Y);

        R_Z = new QDoubleSpinBox(centralwidget);
        R_Z->setObjectName(QString::fromUtf8("R_Z"));
        R_Z->setMinimum(0.000000000000000);
        R_Z->setValue(0.000000000000000);

        horizontalLayout_4->addWidget(R_Z);


        verticalLayout->addLayout(horizontalLayout_4);

        rotate = new QPushButton(centralwidget);
        rotate->setObjectName(QString::fromUtf8("rotate"));

        verticalLayout->addWidget(rotate);

        horizontalSlider = new QSlider(centralwidget);
        horizontalSlider->setObjectName(QString::fromUtf8("horizontalSlider"));
        sizePolicy2.setHeightForWidth(horizontalSlider->sizePolicy().hasHeightForWidth());
        horizontalSlider->setSizePolicy(sizePolicy2);
        horizontalSlider->setMinimum(-5);
        horizontalSlider->setMaximum(5);
        horizontalSlider->setSingleStep(1);
        horizontalSlider->setPageStep(10);
        horizontalSlider->setValue(0);
        horizontalSlider->setSliderPosition(0);
        horizontalSlider->setOrientation(Qt::Horizontal);

        verticalLayout->addWidget(horizontalSlider);

        resize = new QPushButton(centralwidget);
        resize->setObjectName(QString::fromUtf8("resize"));

        verticalLayout->addWidget(resize);

        checkBox = new QCheckBox(centralwidget);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));

        verticalLayout->addWidget(checkBox);


        verticalLayout_2->addLayout(verticalLayout);

        quit = new QPushButton(centralwidget);
        quit->setObjectName(QString::fromUtf8("quit"));

        verticalLayout_2->addWidget(quit);


        horizontalLayout->addLayout(verticalLayout_2);

        GLwidget = new GLWidget(centralwidget);
        GLwidget->setObjectName(QString::fromUtf8("GLwidget"));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(GLwidget->sizePolicy().hasHeightForWidth());
        GLwidget->setSizePolicy(sizePolicy3);

        horizontalLayout->addWidget(GLwidget);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);
        QObject::connect(quit, &QPushButton::released, MainWindow, qOverload<>(&QMainWindow::close));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        file_path->setText(QCoreApplication::translate("MainWindow", "Choose file", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "File name:", nullptr));
        label_file->setText(QString());
        label->setText(QCoreApplication::translate("MainWindow", "Vertices:", nullptr));
        label_vert->setText(QString());
        label_2->setText(QCoreApplication::translate("MainWindow", "Edges:", nullptr));
        label_edges->setText(QString());
        move->setText(QCoreApplication::translate("MainWindow", "Move", nullptr));
        rotate->setText(QCoreApplication::translate("MainWindow", "Rotate", nullptr));
        resize->setText(QCoreApplication::translate("MainWindow", "Resize", nullptr));
        checkBox->setText(QCoreApplication::translate("MainWindow", "Wireframe", nullptr));
        quit->setText(QCoreApplication::translate("MainWindow", "Quit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
