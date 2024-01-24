create table EscuelaOrden(
	 idventa integer ,
	 idExpendio integer,
	 idEscuela integer references escuelas(idEscuela),
	 fecha timestamp without time zone);
	
