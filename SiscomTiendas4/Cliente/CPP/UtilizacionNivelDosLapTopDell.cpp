#include <UtilizacionNivelDosLapTopDell.h>
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
/*
const char *lchrPtrCPUInfo=
"processor	: 0\n\
vendor_id	: GenuineIntel\n\
cpu family	: 6\n\
model		: 13\n\
model name	: Intel(R) Pentium(R) M processor 1.73GHz\n\
stepping	: 8\n\
cpu MHz		: 1729.210\n\
cache size	: 2048 KB\n\
fdiv_bug	: no\n\
hlt_bug		: no\n\
f00f_bug	: no\n\
coma_bug	: no\n\
fpu		: yes\n\
fpu_exception	: yes\n\
cpuid level	: 2\n\
wp		: yes\n\
flags		: fpu vme de pse tsc msr pae mce cx8 apic sep mtrr pge mca cmov pat clflush dts acpi mmx fxsr sse sse2 ss tm pbe nx est tm2\n\
bogomips	: 3460.31\n\
clflush size	: 64\n\
\n\
";
*/
/*
const char *lchrPtrCPUInfo=
"processor	: 0\n\
vendor_id	: GenuineIntel\n\
cpu family	: 6\n\
model		: 13\n\
model name	: Intel(R) Pentium(R) M processor 1.73GHz\n\
stepping	: 8\n\
cpu MHz		: 1729.148\n\
cache size	: 2048 KB\n\
fdiv_bug	: no\n\
hlt_bug		: no\n\
f00f_bug	: no\n\
coma_bug	: no\n\
fpu		: yes\n\
fpu_exception	: yes\n\
cpuid level	: 2\n\
wp		: yes\n\
flags		: fpu vme de pse tsc msr pae mce cx8 apic sep mtrr pge mca cmov pat clflush dts acpi mmx fxsr sse sse2 ss tm pbe nx bts est tm2\n\
bogomips	: 3460.31\n\
clflush size	: 64\n\
\n\
";
if(strcmp(pchrPtrCPUInfo,lchrPtrCPUInfo))
{
printf("ValidandoCPU\n");
exit(0);
}
*/
/*
 * Debido a la problematica que se ha observado, que los valores
 * del cpuinfo cambian cada vez que se inicia la maquina, se determina realizar
 * la validacion solo con el mac address de la maquina
 *
 */
printf("No se realizara la validacion del CPUInfo\n");
}
void SiscomValidaMacAddres(const char *pchrPtrMacAddress)
{
//const char *lchrPtrMacAddress="00:14:22:db:f4:f4"; 
/* Molino Zuniga Visitacion */
//const char *lchrPtrMacAddress="00:06:5b:2c:d9:52";
/* Molino Zuniga Visitacion  01*/
/*const char *lchrPtrMacAddress="00:60:b0:a1:aa:30"; 
if(strcmp(pchrPtrMacAddress,lchrPtrMacAddress))
{
printf("MAC ADDRESS Invalida\n");
exit(0);
} 

*/
}

int SiscomEsSistemaMultiUsuario()
{
  return 1;
}
