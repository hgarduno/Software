/****************************************************************************
** Form interface generated from reading ui file 'UI/Precios.ui'
**
** Created: Fri Apr 12 21:36:40 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef PRECIOS_H
#define PRECIOS_H

#include <qvariant.h>
#include <qwidget.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QTextEdit;
class QLineEdit;
class QTable;
class QPushButton;

class Precios : public QWidget
{
    Q_OBJECT

public:
    Precios( QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~Precios();

    QLabel* textLabel9;
    QTextEdit* QTEDsc;
    QLabel* textLabel8;
    QLineEdit* QLENombre;
    QLabel* textLabel10;
    QTable* QTDatos;
    QPushButton* QPBRegistra;
    QPushButton* pushButton4;
    QPushButton* pushButton5;

protected:
    QGridLayout* PreciosLayout;
    QVBoxLayout* layout18;
    QHBoxLayout* layout19;
    QSpacerItem* spacer3;
    QVBoxLayout* layout17;
    QHBoxLayout* layout20;

protected slots:
    virtual void languageChange();

};

#endif // PRECIOS_H
