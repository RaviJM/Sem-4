select deptno, avg(sal) from emp group by deptno having avg(sal) < (select avg(sal) from emp);