#ifndef __CLASESMENUS_H__
#define __CLASESMENUS_H__

#include <zSiscomVentana.h>

class QWorkspace;
class zVentanaPrueba:public zSiscomVentana
{
Q_OBJECT
public:
	zVentanaPrueba(zSiscomMenusVentana *pzSisMenuVentana);
private:
	void AreaTrabajo();
	void ClasePrueba();
	void ListaLibraryPaths();
private:
	QWorkspace *QWSATrabajo;
};

void CreaMenusVentana(zSiscomMenusVentana *pzSisMenusVentana);
#endif
