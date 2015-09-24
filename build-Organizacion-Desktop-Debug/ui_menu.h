/********************************************************************************
** Form generated from reading UI file 'menu.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MENU_H
#define UI_MENU_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Menu
{
public:
    QWidget *centralWidget;
    QPushButton *agregar_datos_main;
    QPushButton *modificar_datos_main;
    QPushButton *eliminar_datos_main;
    QPushButton *listar_datos_main;
    QPushButton *hacer_llamada_main;
    QPushButton *button_salir_main;
    QMenuBar *menuBar;
    QMenu *menuSimulador_de_llamadas;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Menu)
    {
        if (Menu->objectName().isEmpty())
            Menu->setObjectName(QStringLiteral("Menu"));
        Menu->resize(561, 307);
        centralWidget = new QWidget(Menu);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        agregar_datos_main = new QPushButton(centralWidget);
        agregar_datos_main->setObjectName(QStringLiteral("agregar_datos_main"));
        agregar_datos_main->setGeometry(QRect(10, 0, 181, 121));
        modificar_datos_main = new QPushButton(centralWidget);
        modificar_datos_main->setObjectName(QStringLiteral("modificar_datos_main"));
        modificar_datos_main->setGeometry(QRect(190, 0, 181, 121));
        eliminar_datos_main = new QPushButton(centralWidget);
        eliminar_datos_main->setObjectName(QStringLiteral("eliminar_datos_main"));
        eliminar_datos_main->setGeometry(QRect(368, 0, 181, 121));
        listar_datos_main = new QPushButton(centralWidget);
        listar_datos_main->setObjectName(QStringLiteral("listar_datos_main"));
        listar_datos_main->setGeometry(QRect(10, 120, 181, 121));
        hacer_llamada_main = new QPushButton(centralWidget);
        hacer_llamada_main->setObjectName(QStringLiteral("hacer_llamada_main"));
        hacer_llamada_main->setGeometry(QRect(190, 120, 181, 121));
        button_salir_main = new QPushButton(centralWidget);
        button_salir_main->setObjectName(QStringLiteral("button_salir_main"));
        button_salir_main->setGeometry(QRect(370, 120, 181, 121));
        Menu->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(Menu);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 561, 25));
        menuSimulador_de_llamadas = new QMenu(menuBar);
        menuSimulador_de_llamadas->setObjectName(QStringLiteral("menuSimulador_de_llamadas"));
        Menu->setMenuBar(menuBar);
        mainToolBar = new QToolBar(Menu);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        Menu->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(Menu);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        Menu->setStatusBar(statusBar);

        menuBar->addAction(menuSimulador_de_llamadas->menuAction());

        retranslateUi(Menu);

        QMetaObject::connectSlotsByName(Menu);
    } // setupUi

    void retranslateUi(QMainWindow *Menu)
    {
        Menu->setWindowTitle(QApplication::translate("Menu", "Menu", 0));
        agregar_datos_main->setText(QApplication::translate("Menu", "Agregar Dato", 0));
        modificar_datos_main->setText(QApplication::translate("Menu", "Modificar Dato", 0));
        eliminar_datos_main->setText(QApplication::translate("Menu", "Eliminar Dato", 0));
        listar_datos_main->setText(QApplication::translate("Menu", "Listar Datos", 0));
        hacer_llamada_main->setText(QApplication::translate("Menu", "Realizar Llamada", 0));
        button_salir_main->setText(QApplication::translate("Menu", "Salir", 0));
        menuSimulador_de_llamadas->setTitle(QApplication::translate("Menu", "Simulador de llamadas", 0));
    } // retranslateUi

};

namespace Ui {
    class Menu: public Ui_Menu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MENU_H
