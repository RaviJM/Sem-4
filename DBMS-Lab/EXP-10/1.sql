select e1.* from emp e1 inner join (select ename, sal from emp) as e2 on e2.ename = "BLAKE" where e1.sal >e2.sal;