select e.ename from emp e JOIN (select MAX(sal) as MAX_sal from emp where deptno =30) s ON e.sal = s.max_sal AND e.deptno = 30;