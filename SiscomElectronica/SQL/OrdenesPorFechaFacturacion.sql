
select * 
from ventas
where fechahora::date>='2007-06-06' and
      fechahora::date<='2007-06-07' and
      edoventa=0;


select sum(importe) as Total,
       fechahora::date,
       idventa,
       cliente,
       nombre,
       apaterno,
       amaterno
from ventas inner join personas as a on idpersona=cliente
where fechahora::date>='2007-06-06' and
      fechahora::date<='2007-06-07' and
      edoventa=0
group by fechahora::date,
	 idventa,
	 cliente,
	 nombre,
	 apaterno,
	 amaterno
  
