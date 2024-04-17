/****************************************************************************
** Form interface generated from reading ui file 'UI/ProductosSimilares.ui'
**
** Created: Fri Apr 12 21:25:58 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef PRODUCTOSSIMILARES_H
#define PRODUCTOSSIMILARES_H

#include <qvariant.h>
#include <qdialog.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QTextEdit;
class QTable;
class QPushButton;

class ProductosSimilares : public QDialog
{
    Q_OBJECT

public:
    ProductosSimilares( QWidget* parent = 0, const char* name = 0, bool modal = FALSE, WFlags fl = 0 );
    ~ProductosSimilares();

    QLabel* textLabel1_3;
    QTextEdit* QTEDescripcion;
    QLabel* textLabel1;
    QTable* QTProductos;
    QPushButton* QPBAceptar;

protected:
    QGridLayout* ProductosSimilaresLayout;
    QVBoxLayout* layout5_3;
    QVBoxLayout* layout45;

protected slots:
    virtual void languageChange();

};

#endif // PRODUCTOSSIMILARES_H
