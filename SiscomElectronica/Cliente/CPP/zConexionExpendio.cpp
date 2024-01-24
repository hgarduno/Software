
#include <zConexionExpendio.h>
#include <zExpendio.h>
zConexionExpendio::zConexionExpendio(zExpendio *pzExpendio):
			zSiscomConexion(pzExpendio->DirIp(),pzExpendio->PuertoInt()),
			zExpendio(pzExpendio)

			
{

}
