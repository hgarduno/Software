#ifndef __SISCOMNORMALIZACION_H__
#define __SISCOMNORMALIZACION_H__

void SiscomNormaliza2(const char *,
		     unsigned char *,
		     unsigned char **);

void SiscomNormaliza(const char *,
		     unsigned char *,
		     unsigned char **);
unsigned char *SiscomCaracteresCambiados();

void SiscomCambiaMayusculas(char *);
void SiscomQuitaMasDeUnEspacio(char *);

#endif
