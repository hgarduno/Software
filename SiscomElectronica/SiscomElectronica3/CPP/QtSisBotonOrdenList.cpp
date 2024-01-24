#include <QtSisBotonOrdenList.h>
#include <QtSisBotonOrden.h>

QtSisBotonOrdenList::QtSisBotonOrdenList()
{

}
QtSisBotonOrdenList::~QtSisBotonOrdenList()
{

}
void QtSisBotonOrdenList::Agrega(QtSisBotonOrden *pQtSisBtnOrden)
{
  append(pQtSisBtnOrden);
}
