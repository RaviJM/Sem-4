select pcode from part where cost > (select avg(cost) from part);