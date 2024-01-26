create table CentroTrabajo(idpersona integer references personas(IdPersona),
			   CentroTrabajo varchar(11),
			   ClavePresupuestal varchar(13));
