#ifndef __SQLCATALOGOS_H__
#define __SQLCATALOGOS_H__
#include <SiscomProtocoloComunicaciones.h>
#include <SiscomOperaciones.h>
#include <SiscomArchivosIni.h>
int SqlFrecuenciaPagos(SiscomOperaciones *pSiscomOpePtrDat);
int SqlTipoVivienda(SiscomOperaciones *pSiscomOpePtrDat);
int SqlConceptosExistencias(SiscomOperaciones *pSiscomOpePtrDat);
int SqlTiendasEntrega(SiscomOperaciones *pSiscomOpePtrDat);
int SqlVendedores(SiscomOperaciones *pSiscomOpePtrDat);
int SqlPerfiles(SiscomOperaciones *pSiscomOpePtrDat);
int SqlPlazos(SiscomOperaciones *pSiscomOpePtrDat);
int SqlCamiones(SiscomOperaciones *pSiscomOpePtrDat);
int SqlProveedores(SiscomOperaciones *pSiscomOpePtrDat);
int SqlProductos(SiscomOperaciones *pSiscomOpePtrDat);
int SqlProductosCodigoBarras(SiscomOperaciones *pSiscomOpePtrDat);
int SqlProductoCodigoBarras(SiscomOperaciones *pSiscomOpePtrDat);
int SqlProductoProveedor(SiscomOperaciones *pSiscomOpePtrDat);
int SqlProductosCodigoBarrasFechaCompra(SiscomOperaciones *pSiscomOpePtrDat);
int SqlProductosCodigoBarrasTodos(SiscomOperaciones *pSiscomOpePtrDat);
int SqlDepartamentos(SiscomOperaciones *pSiscomOpePtrDat);
int SqlTipoDocumentos(SiscomOperaciones *pSiscomOpePtrDat);
int SqlEstados(SiscomOperaciones *pSiscomOpePtrDat);
int SqlFormasEntrega(SiscomOperaciones *pSiscomOpePtrDat);
int SqlTipoVentas(SiscomOperaciones *pSiscomOpePtrDat);
int SqlFinanciadoras(SiscomOperaciones *pSiscomOpePtrDat);
int SqlFrecuenciaTransaccional(SiscomOperaciones *pSiscomOpePtrDat);
int SqlTiposFolio(SiscomOperaciones *pSiscomOpePtrDat);
#endif
