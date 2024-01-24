#ifndef __CFRMFIRMAUSUARIO2_H__
#define __CFRMFIRMAUSUARIO2_H__

#include <frmFirmaUsuario2.h>
#include <qxml.h>
class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QComboBox;
class QLineEdit;
class QPushButton;
class CSISCOMDatComunicaciones;
class CQSisServidor
{
	public:
		CQSisServidor(const char *,int );
		const char *ObtenDirIpSvr();
		int ObtenPtoCom();
	private:
		const char *chrPtrDirIpSvr;
		int intPtoCom;
};
class CQSisUsuario
{
	public:
		CQSisUsuario(const char *,const char *,int ,int);
		const char *ObtenTipoLetra();
		const char *ObtenFirma();
		int ObtenTamanoLetra();
		int ObtenNegrita();
	private:
		const char *chrPtrFirma;
		const char *chrPtrTipoLetra;
		int intTamano;
		int intNegrita;
};
class CQSisUsuarios:public QPtrList<CQSisUsuario>
{
	public:
		CQSisUsuarios();
		const CQSisUsuarios &operator<<(CQSisUsuario *);
		CQSisUsuario *operator[](int );
		CQSisUsuario *operator[](const char *);
		bool operator==(CQSisUsuario *);

};
class CQSisServidores:public QPtrList<CQSisServidor>
{
	public:
		CQSisServidores();
		const CQSisServidores &operator<<(CQSisServidor *);
		CQSisServidor *operator[](int );
		bool operator==(CQSisServidor *);
	private:
};
class CQSisLeeArchivoConf:public QXmlDefaultHandler
{

	public:
		CQSisLeeArchivoConf();
		bool startDocument();
		bool startElement(const QString &,
				  const QString &,
				  const QString &,
				  const QXmlAttributes &);
		bool endElement(const QString &,const QString &,const QString &);
		void ObtenUsuarios(CQSisUsuarios &);
		void ObtenServidores(CQSisServidores &);
	private:
		CQSisUsuarios CQSUsuarios;
		CQSisServidores CQSServidores;
		const char *chrPtrSistema;
		const char *chrPtrServidor;
		const char *chrPtrDireccion;
		int intPuerto;
		const char *chrPtrUsuario;
		const char *chrPtrTipoLetra;
		int intTamano;
		int intNegrita;
};
class CfrmFirmaUsuario2 : public frmFirmaUsuario2
{
    Q_OBJECT
public:
    CfrmFirmaUsuario2(const char *, QWidget* parent = 0, const char* name = 0, bool modal = FALSE, WFlags fl = 0 );
    ~CfrmFirmaUsuario2();
    CSISCOMDatComunicaciones *ObtenDatosDeComunicaciones();
    void PonNombreAplicacion(const char *);
    const char *ObtenIdAplicacion();

private:
    void LeeArchivoUsuarios();
    void ConectaSlots();
    void IniciaConfiguracion();
    void EscribeArchivo();
    void CreaServidor(const char *,const char *,int,QString &);
    void CreaUsuario(const char *,const char *,int,int,QString &);
    void ValidaServidor();
    void ValidaUsuario();
    void MuestraContenido();
    void MuestraUsuarios();
    void MuestraServidores();
    void closeEvent(QCloseEvent *);
private:
    QLineEdit *QLEComboUsuarios;
    QLineEdit *QLEComboServidores;
    QFont QFTipoLetra;
    int intLeyoArchivo;
    CQSisServidores CQSServidores;
    CQSisUsuarios CQSUsuarios;
    CQSisLeeArchivoConf CQSLArchivoConf;
    CSISCOMDatComunicaciones *CSisDatCom;
    const char *chrPtrNmbAplicacion;
    const char *chrPtrIdAplicacion;
private slots:
	void SlotPasaFocoPassword();
	void SlotPasaFocoDirServidor();
	void SlotPasaFocoPtoCom();
	void SlotTipoLetra();
	void SlotPasaFocoTipoLetra();
	void SlotAceptar();
};

#endif 
