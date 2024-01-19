#ifndef __SISCOMMACROSOPERACIONES_H__
#define __SISCOMMACROSOPERACIONES_H__
#include <SiscomLogOperaciones.h>

#define SiscomAsociadosArgumentoLog(pchrPtrArgumento,		\
				    pchrPtrAsociado,		\
				    pchrPtrBuffer,		\
				    pSiscomOpPtrDat)		\
	SiscomMuestraAsociadosArgumento(__FILE__,		\
					__FUNCTION__,		\
					__LINE__,		\
					pchrPtrArgumento,	\
					pchrPtrAsociado,	\
					pchrPtrBuffer,		\
					pSiscomOpPtrDat);

#define SiscomArgumentoLog(pchrPtrArgumento,		\
				    pchrPtrBuffer,		\
				    pSiscomOpPtrDat)		\
	SiscomMuestraArgumento(__FILE__,		\
					__FUNCTION__,		\
					__LINE__,		\
					pchrPtrArgumento,	\
					pchrPtrBuffer,		\
					pSiscomOpPtrDat);


#define SiscomAsociadoRespuestaLog(pchrPtrAsociado,		\
				   pchrPtrBuffer,		\
				   pSiscomOpePtrDat)		\
	SiscomAsociadoRespuesta(__FILE__,			\
				__FUNCTION__,			\
				__LINE__,			\
				pchrPtrAsociado,		\
				pchrPtrBuffer,			\
				pSiscomOpePtrDat);



#define SiscomAsociadoEntradaLog(pchrPtrAsociado,		\
				   pchrPtrBuffer,		\
				   pSiscomOpePtrDat)		\
	SiscomAsociadoEntrada(__FILE__,			\
				__FUNCTION__,			\
				__LINE__,			\
				pchrPtrAsociado,		\
				pchrPtrBuffer,			\
				pSiscomOpePtrDat);


#define SiscomRegistroEntradaLog(pchrPtrBuffer,		\
				pSiscomOpePtrDat)	\
	SiscomRegistroEntrada(__FILE__,			\
			      __FUNCTION__,		\
			      __LINE__,			\
			      pchrPtrBuffer,		\
			      pSiscomOpePtrDat)
#define SiscomRegistroRegresoLog(pchrPtrBuffer,		\
				pSiscomOpePtrDat)	\
	SiscomRegistroRegreso(__FILE__,			\
			      __FUNCTION__,		\
			      __LINE__,			\
			      pchrPtrBuffer,		\
			      pSiscomOpePtrDat)

#define SiscomAsociadoAsociadoLog(pchrPtrCampo, 		\
				  pchrPtrAsociado,		\
				  pchrPtrBuffer,		\
				  pSisOpePtrDato)		\
	SiscomAsociadoAsociadoEntradaAlLog(pchrPtrCampo,	\
					   pchrPtrAsociado,	\
					   __FILE__,		\
					   __FUNCTION__,	\
					   __LINE__,		\
					   pchrPtrBuffer,	\
					   pSisOpePtrDato)

#endif
