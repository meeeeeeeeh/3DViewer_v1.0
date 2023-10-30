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
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
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
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_4;
    QLabel *label_file;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label;
    QLabel *label_vert;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_2;
    QLabel *label_edges;
    QSpacerItem *verticalSpacer;
    QLabel *label_7;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_6;
    QSpinBox *dot_size;
    QLabel *label_3;
    QHBoxLayout *horizontalLayout_10;
    QRadioButton *radioButton_3;
    QRadioButton *radioButton_2;
    QRadioButton *radioButton;
    QPushButton *color_vert;
    QSpacerItem *verticalSpacer_2;
    QLabel *label_8;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_5;
    QSpinBox *line_size;
    QLabel *label_9;
    QHBoxLayout *horizontalLayout_9;
    QRadioButton *radioButton_5;
    QRadioButton *radioButton_4;
    QPushButton *color_lines;
    QSpacerItem *verticalSpacer_3;
    QPushButton *move;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QDoubleSpinBox *X;
    QDoubleSpinBox *Y;
    QDoubleSpinBox *Z;
    QPushButton *rotate;
    QHBoxLayout *horizontalLayout_4;
    QDoubleSpinBox *R_X;
    QDoubleSpinBox *R_Y;
    QDoubleSpinBox *R_Z;
    QPushButton *resize;
    QSlider *recize_val;
    QPushButton *color_back;
    QSpacerItem *verticalSpacer_4;
    QHBoxLayout *horizontalLayout_11;
    QPushButton *image;
    QPushButton *gif;
    QRadioButton *radioButton_bmp;
    QRadioButton *radioButton_jpeg;
    QPushButton *quit;
    GLWidget *GLwidget;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1200, 1000);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(1200, 1000));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        file_path = new QPushButton(centralwidget);
        file_path->setObjectName(QString::fromUtf8("file_path"));

        verticalLayout_2->addWidget(file_path);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy1);

        horizontalLayout_5->addWidget(label_4);

        label_file = new QLabel(centralwidget);
        label_file->setObjectName(QString::fromUtf8("label_file"));

        horizontalLayout_5->addWidget(label_file);


        verticalLayout_2->addLayout(horizontalLayout_5);

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

        label_7 = new QLabel(centralwidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        verticalLayout_2->addWidget(label_7);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        horizontalLayout_6->addWidget(label_6);

        dot_size = new QSpinBox(centralwidget);
        dot_size->setObjectName(QString::fromUtf8("dot_size"));

        horizontalLayout_6->addWidget(dot_size);


        verticalLayout_2->addLayout(horizontalLayout_6);

        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout_2->addWidget(label_3);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        radioButton_3 = new QRadioButton(centralwidget);
        radioButton_3->setObjectName(QString::fromUtf8("radioButton_3"));

        horizontalLayout_10->addWidget(radioButton_3);

        radioButton_2 = new QRadioButton(centralwidget);
        radioButton_2->setObjectName(QString::fromUtf8("radioButton_2"));

        horizontalLayout_10->addWidget(radioButton_2);

        radioButton = new QRadioButton(centralwidget);
        radioButton->setObjectName(QString::fromUtf8("radioButton"));

        horizontalLayout_10->addWidget(radioButton);


        verticalLayout_2->addLayout(horizontalLayout_10);

        color_vert = new QPushButton(centralwidget);
        color_vert->setObjectName(QString::fromUtf8("color_vert"));

        verticalLayout_2->addWidget(color_vert);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_2);

        label_8 = new QLabel(centralwidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        verticalLayout_2->addWidget(label_8);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_3->addWidget(label_5);

        line_size = new QSpinBox(centralwidget);
        line_size->setObjectName(QString::fromUtf8("line_size"));

        horizontalLayout_3->addWidget(line_size);


        verticalLayout_2->addLayout(horizontalLayout_3);

        label_9 = new QLabel(centralwidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        verticalLayout_2->addWidget(label_9);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        radioButton_5 = new QRadioButton(centralwidget);
        radioButton_5->setObjectName(QString::fromUtf8("radioButton_5"));

        horizontalLayout_9->addWidget(radioButton_5);

        radioButton_4 = new QRadioButton(centralwidget);
        radioButton_4->setObjectName(QString::fromUtf8("radioButton_4"));

        horizontalLayout_9->addWidget(radioButton_4);


        verticalLayout_2->addLayout(horizontalLayout_9);

        color_lines = new QPushButton(centralwidget);
        color_lines->setObjectName(QString::fromUtf8("color_lines"));

        verticalLayout_2->addWidget(color_lines);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_3);

        move = new QPushButton(centralwidget);
        move->setObjectName(QString::fromUtf8("move"));

        verticalLayout_2->addWidget(move);

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

        rotate = new QPushButton(centralwidget);
        rotate->setObjectName(QString::fromUtf8("rotate"));

        verticalLayout->addWidget(rotate);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        R_X = new QDoubleSpinBox(centralwidget);
        R_X->setObjectName(QString::fromUtf8("R_X"));
        R_X->setMaximum(360.990000000000009);

        horizontalLayout_4->addWidget(R_X);

        R_Y = new QDoubleSpinBox(centralwidget);
        R_Y->setObjectName(QString::fromUtf8("R_Y"));
        R_Y->setMaximum(360.990000000000009);

        horizontalLayout_4->addWidget(R_Y);

        R_Z = new QDoubleSpinBox(centralwidget);
        R_Z->setObjectName(QString::fromUtf8("R_Z"));
        R_Z->setMinimum(0.000000000000000);
        R_Z->setMaximum(360.990000000000009);
        R_Z->setValue(0.000000000000000);

        horizontalLayout_4->addWidget(R_Z);


        verticalLayout->addLayout(horizontalLayout_4);

        resize = new QPushButton(centralwidget);
        resize->setObjectName(QString::fromUtf8("resize"));

        verticalLayout->addWidget(resize);

        recize_val = new QSlider(centralwidget);
        recize_val->setObjectName(QString::fromUtf8("recize_val"));
        sizePolicy2.setHeightForWidth(recize_val->sizePolicy().hasHeightForWidth());
        recize_val->setSizePolicy(sizePolicy2);
        recize_val->setMinimum(-5);
        recize_val->setMaximum(5);
        recize_val->setSingleStep(1);
        recize_val->setPageStep(10);
        recize_val->setValue(0);
        recize_val->setSliderPosition(0);
        recize_val->setOrientation(Qt::Horizontal);

        verticalLayout->addWidget(recize_val);

        color_back = new QPushButton(centralwidget);
        color_back->setObjectName(QString::fromUtf8("color_back"));

        verticalLayout->addWidget(color_back);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_4);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        image = new QPushButton(centralwidget);
        image->setObjectName(QString::fromUtf8("image"));

        horizontalLayout_11->addWidget(image);

        gif = new QPushButton(centralwidget);
        gif->setObjectName(QString::fromUtf8("gif"));

        horizontalLayout_11->addWidget(gif);


        verticalLayout->addLayout(horizontalLayout_11);


        verticalLayout_2->addLayout(verticalLayout);

        radioButton_bmp = new QRadioButton(centralwidget);
        radioButton_bmp->setObjectName(QString::fromUtf8("radioButton_bmp"));

        verticalLayout_2->addWidget(radioButton_bmp);

        radioButton_jpeg = new QRadioButton(centralwidget);
        radioButton_jpeg->setObjectName(QString::fromUtf8("radioButton_jpeg"));

        verticalLayout_2->addWidget(radioButton_jpeg);

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
        label_7->setText(QCoreApplication::translate("MainWindow", "Customize vertices:", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Size:", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Display method:", nullptr));
        radioButton_3->setText(QCoreApplication::translate("MainWindow", "none", nullptr));
        radioButton_2->setText(QCoreApplication::translate("MainWindow", "square", nullptr));
        radioButton->setText(QCoreApplication::translate("MainWindow", "round", nullptr));
        color_vert->setText(QCoreApplication::translate("MainWindow", "color", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "Customize edges:", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Thickness:", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "Type:", nullptr));
        radioButton_5->setText(QCoreApplication::translate("MainWindow", "solid", nullptr));
        radioButton_4->setText(QCoreApplication::translate("MainWindow", "dashed", nullptr));
        color_lines->setText(QCoreApplication::translate("MainWindow", "color", nullptr));
        move->setText(QCoreApplication::translate("MainWindow", "Move", nullptr));
        rotate->setText(QCoreApplication::translate("MainWindow", "Rotate", nullptr));
        resize->setText(QCoreApplication::translate("MainWindow", "Resize", nullptr));
        color_back->setText(QCoreApplication::translate("MainWindow", "background color", nullptr));
        image->setText(QCoreApplication::translate("MainWindow", "image", nullptr));
        gif->setText(QCoreApplication::translate("MainWindow", "gif", nullptr));
        radioButton_bmp->setText(QCoreApplication::translate("MainWindow", "bmp", nullptr));
        radioButton_jpeg->setText(QCoreApplication::translate("MainWindow", "jpeg", nullptr));
        quit->setText(QCoreApplication::translate("MainWindow", "Quit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
