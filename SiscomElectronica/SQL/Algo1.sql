select a.nombre   || 
                ' '      ||
                a.apaterno ||
                ' '      ||
                a.amaterno as completo,
                a.nombre,
                a.apaterno,
                a.amaterno,
                a.idpersona,
                ' '      ||
                ' '      ||
                ' '      ||
                ''   as direcciones,
                '' as telefonos,
                '' as correos,
                f.nombre as escuela,
                f.idescuela 
from personas as a left outer join  
     personanormalizada as g using(idpersona) left outer join
     alumnoescuela as e using(idpersona) left outer join 
     escuelas as f using(idescuela)
where g.nombre like '%HERZ%'
