#ifndef __SISCOMDESARROLLOMACROS_H__
#define __SISCOMDESARROLLOMACROS_H__
#include <SiscomManejoLog.h>
#include <SiscomErrores.h>


#if __GNUC__ > 2 || (__GNUC__ == 2 && __GNUC_MINOR__ > 95)
#define LogSiscom(...) SiscomMensajesLog4(__FILE__,__FUNCTION__,__LINE__,__VA_ARGS__)
#else
#define LogSiscom(...) SiscomMensajesLog4(__FILE__,__FUNCTION__,__LINE__,##args)
#endif

#define LogSiscomCadena(pchrPtrCadena) 									\
	SiscomMensajesLog4(__FILE__,__FUNCTION__,__LINE__,"%s (%x)",pchrPtrCadena,pchrPtrCadena)



#define SiscomGeneraError(pintCodigoError,pchrPtrMensajeError) 	\
	SiscomErrorG(__FILE__,				\
			    __FUNCTION__,			\
			    __LINE__,				\
			    pintCodigoError,			\
			    pchrPtrMensajeError);

#define SiscomImprimeCadenas(pchrPtrCadenas)			\
	SiscomArregloCadenasLog(__FILE__,			\
				__FUNCTION__,			\
				__LINE__,			\
				pchrPtrCadenas);

#define SiscomMuestraVariablesIni(pSiscomVILPtrDato)		\
	SiscomVariablesIniLog(__FILE__,				\
			      __FUNCTION__,			\
			      __LINE__,				\
			      pSiscomVILPtrDato);	

#define SiscomMuestraVariablesIniArreglo(pSiscomVIALPtrDato)	\
	SiscomVariablesArregloIniLog(__FILE__,			\
				    __FUNCTION__,		\
				    __LINE__,			\
				    pSiscomVIALPtrDato);
#define SiscomCamposProtocoloLog(pSiscomCamProLPtrDato)		\
	SiscomMuestraCamposProtocolo(__FILE__,			\
			      __FUNCTION__,			\
			      __LINE__,				\
			      pSiscomCamProLPtrDato);
#define SiscomCamposProtocoloLog2(pSiscomRegProLDato)		\
	SiscomMuestraCamposProtocolo2(__FILE__,			\
			      __FUNCTION__,			\
			      __LINE__,				\
			      pSiscomRegProLDato);


#define SiscomRegistroProtocoloLog(pchrPtrBuffer,pSiscomRegProLPtrDato)	\
	SiscomMuestraRegistrosProtocolo(__FILE__,			\
				       __FUNCTION__,			\
				       __LINE__,			\
				       pchrPtrBuffer,			\
				       pSiscomRegProLPtrDato);
#define SiscomRegistrosAsociadosLog(pchrPtrBuffer,			\
				    pchrPtrCampo,			\
				    pSiscomRegProLPtrActual)		\
	SiscomMuestraRegistrosAsociados(__FILE__,			\
					__FUNCTION__,			\
					__LINE__,			\
					pchrPtrBuffer,			\
					pchrPtrCampo,			\
					pSiscomRegProLPtrActual);

#if __GNUC__ > 2 || (__GNUC__ == 2 && __GNUC_MINOR__ > 95)
#define SiscomSocketProtocoloLog(...) 					 \
 	 SiscomSocketProtocolo(__FILE__,__FUNCTION__,__LINE__,__VA_ARGS__)
#else
#define SiscomSocketProtocoloLog(...) 					\
	 SiscomSocketProtocolo(__FILE__,__FUNCTION__,__LINE__,##args)
#endif

#if __GNUC__ > 2 || (__GNUC__ == 2 && __GNUC_MINOR__ > 95)
#define LogSiscomErrorNo(...) 					 \
 	 SiscomMensajesLog4(__FILE__,__FUNCTION__,__LINE__,__VA_ARGS__)
#else
#define SiscomSocketProtocoloLog(...) 					\
	 SiscomSocketProtocolo(__FILE__,__FUNCTION__,__LINE__,##args)
#endif


#define LogSiscomCadenas(pchrPtrCadenas) 					\
        SiscomCadenasLog(__FILE__,__FUNCTION__,__LINE__,pchrPtrCadenas)

#endif
