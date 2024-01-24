	killall -s30  DemonioDeConexiones.bin
	
	DemonioDeConexiones.bin -A1640 -BRNProcesoAtiende.bin -C20 -DlibRNDllIniciaDemonio.so -ECargaProcesosYDll -FIniciaMemSHM -G1641 -H200.39.214.3
		DemonioDeConexiones.bin -A1641 -BADProcesoAtiendeCliente.bin -C20 #-D$SISCOM/Binarios/ADDllIniciaDemonio.so -EADDllGeneraArgumentos -FADDllConexionBDYCopiaSHM
