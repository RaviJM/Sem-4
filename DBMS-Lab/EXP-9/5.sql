select deptno, count(Empno) as No_of_Emp from Emp group by Deptno having count(empno) > 3;