#include <UtilizacionVentas.h>

CQSisPerfilVentas *UtilizacionNivelDos()
{
CQSisPerfilVentas *lCQSPVentas;
	lCQSPVentas=new CQSisPerfilVentas;
	lCQSPVentas->EdoClientes(1);
	lCQSPVentas->EdoContacto(1);
	lCQSPVentas->EdoFormaPago(1);
	lCQSPVentas->EdoPrecios(1);
return lCQSPVentas;

}
void NivelDosPrincipal(void *pCQSLMenu)
{
/*
 *
 *
 * CQSisPerfilPrincipal lCQSPPrincipal((CQSisLstMenu *)pCQSLMenu);
 *
 *
 */



}
void SiscomValidaAutenticidad(const char *pchrPtrCPUInfo)
{
const char *lchrPtrCPUInfo=
"processor	: 0\n\
vendor_id	: GenuineIntel\n\
cpu family	: 15\n\
model		: 2\n\
model name	: Intel(R) Pentium(R) 4 CPU 2.40GHz\n\
stepping	: 9\n\
cpu MHz		: 2399.940\n\
cache size	: 512 KB\n\
fdiv_bug	: no\n\
hlt_bug		: no\n\
f00f_bug	: no\n\
coma_bug	: no\n\
fpu		: yes\n\
fpu_exception	: yes\n\
cpuid level	: 2\n\
wp		: yes\n\
flags		: fpu vme de pse tsc msr pae mce cx8 apic sep mtrr pge mca cmov pat pse36 clflush dts acpi mmx fxsr sse sse2 ss ht tm pbe pebs bts sync_rdtsc cid xtpr\n\
bogomips	: 4790.21\n\
clflush size	: 64\n\
\n\
";
/*
 *
 *
if(strcmp(pchrPtrCPUInfo,lchrPtrCPUInfo))
{
printf("Sistema no autorizado\n");
exit(0);
}

*/
}
void SiscomValidaMacAddres(const char *pchrPtrMacAddress)
{
/*const char *lchrPtrMacAddress="00:11:43:04:05:21"; */
const char *lchrPtrMacAddress="00:18:8b:2a:55:02";
if(strcmp(pchrPtrMacAddress,lchrPtrMacAddress))
{
printf("MAC ADDRESS Invalida\n");
exit(0);
}
}

int SiscomEsSistemaMultiUsuario()
{
  return 1;
}
