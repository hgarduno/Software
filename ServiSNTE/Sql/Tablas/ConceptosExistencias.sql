create table ConceptosExistencias(IdConceptosExistencias integer unique,
				  Conceptos varchar(128),
				  Abreviatura varchar(30),
			   	  EntradaSalida integer,
			   	  AfectaStock varchar(1),
				  FacturaFinanciadora varchar(1),
			     	  CuentaPorCobrar varchar(1),
			     	  CuentaPorPagar varchar(1));

create table EstatusConceptosExistencias(IdConceptosExistencias integer references ConceptosExistencias(IdConceptosExistencias),
					 IdEstatus integer references Estatus(IdEstatus)); 
