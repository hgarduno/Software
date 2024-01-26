#ifndef __QTIMPHISTORIALCOMPRAS_H__
#define __QTIMPHISTORIALCOMPRAS_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <qwidget.h>
#include <qtable.h>

class QtImpHistorialCompras : public QWidget
{
    Q_OBJECT
public:
    QtImpHistorialCompras();
    ~QtImpHistorialCompras();
public slots:
protected:
private:
    QTable *historial;
};

#endif

