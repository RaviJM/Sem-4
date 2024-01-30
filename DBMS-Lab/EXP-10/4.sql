(select e1.ename from emp e1 inner join emp e2 on e1.job = e2.job where e2.ename = "MILLER")
union
(select e1.ename from emp e1 inner join emp e2 on e1.sal > e2.sal where e2.ename = "ALLEN");