select  a.idCompetencia,
	a.idGimnasta,
	b.Nombre              as NmbGimnasta,
	b.APaterno      as APatGimnasta,
	b.AMaterno      as AMatGimnasta,
	c.Nombre                as NmbEntrenador, 
	c.APaterno      as APatEntrenador,
	c.AMaterno      as AMatEntrenador,
	d.idClase,
	d.Clase,
	e.idNivel,
	e.nivel,
	idgimnasio,
	f.nombre                as gimnasio,
	g.edadinf,
	g.edadsup,
	g.grupo,
	h.ejecucion,
	h.dificultad,
	h.ejecucion+h.dificultad as notafinal
from    compitiendo             as a
	inner join personas   as b on (idgimnasta=b.idpersona)
	inner join personas     as c on (identrenador=c.idpersona)
	inner join catclase     as d using(idclase)
	inner join catnivel     as e on (a.idclase=e.idclase and
					 a.idnivel=e.idnivel   )
	inner join gimnasio   as f on (idgimnasiopqc=idgimnasio) 
	inner join grupos       as g using(idgrupo)
	left outer join calificaciones as h on (a.idgimnasta=h.idgimnasta and
	                                      a.idcompetencia=h.idcompetencia)
where   a.idCompetencia=1194956918 
order by g.grupo,
         d.clase,
	 e.nivel
