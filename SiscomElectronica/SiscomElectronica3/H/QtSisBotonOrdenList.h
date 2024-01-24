#ifndef __QTSISBOTONORDENLIST_H__
#define __QTSISBOTONORDENLIST_H__
#include <qptrlist.h>

class QtSisBotonOrden;
class QtSisBotonOrdenList:public QPtrList<QtSisBotonOrden>
{
public:
	QtSisBotonOrdenList();
	~QtSisBotonOrdenList();
	void Agrega(QtSisBotonOrden*);
};

#endif
