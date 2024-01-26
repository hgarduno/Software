#ifndef __QT3_SISCOMIRDENT_H__
#define __QT3_SISCOMIRDENT_H__
#include <cstddef>
#include <zSiscomVentana.h>

class QWorkspace;
class zSiscomConexion;
class QtSiscomServiSNTE:public zSiscomVentana
{
Q_OBJECT
public:
	QtSiscomServiSNTE(zSiscomConexion *pzSisConexion,
				zSiscomMenusVentana *pzSisMenusV);



};


#endif 
