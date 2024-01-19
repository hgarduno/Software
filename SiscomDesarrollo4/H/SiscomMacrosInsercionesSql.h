#ifndef __SISCOMMACROSINSERCIONESSQL_H__
#define __SISCOMMACROSINSERCIONESSQL_H__

#define SiscomArgumentoInsercionSqlLog(pchrPtrArgumento,	\
					 pchrPtrBuffer,		\
					 pSiscomOpePtrDato)	\
	SiscomMuestraAsociadosArgumento(__FILE__,		\
					__FUNCTION__,		\
					__LINE__,		\
					pchrPtrArgumento,	\
					"SentenciasSql",	\
					pchrPtrBuffer,		\
					pSiscomOpePtrDato);




#endif
