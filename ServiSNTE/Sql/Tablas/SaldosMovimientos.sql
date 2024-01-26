create table ConceptosEntradas(IdConcepto integer 
			       references ConceptosExistencias(idconceptosexistencias) unique);
create table ConceptosSalidas(IdConcepto integer  references 
			      ConceptosExistencias(idconceptosexistencias)  unique);


create table TipoVentaConceptoEntrada(IdTipoVenta integer references tipoventas(idtipoventa),
				      IdConcepto integer references ConceptosEntradas(idconcepto));

create table meses(idmes integer unique,
			  nombre varchar(20));
