#include <zDatosPersonales.h>
#include <string.h>
zDatosPersonales::zDatosPersonales()
{

}
zDatosPersonales::zDatosPersonales(const char *pchrPtrNombre,
				   const char *pchrPtrAPaterno,
				   const char *pchrPtrAMaterno)
{
chrPtrNombre=pchrPtrNombre;
chrPtrAPaterno=pchrPtrAPaterno;
chrPtrAMaterno=pchrPtrAMaterno;
}

const char *zDatosPersonales::Nombre()
{
return chrPtrNombre;

}

const char *zDatosPersonales::APaterno()
{
return chrPtrAPaterno;

}

const char *zDatosPersonales::AMaterno()
{
return chrPtrAMaterno;
}
