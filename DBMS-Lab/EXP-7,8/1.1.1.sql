create table EMP(
EMPNO int primary key,
ENAME char(15),
JOB char(15),
MGR int,
HIREDATE date,
SAL int,
COMM int,
DEPTNO int,
constraint cfk1 foreign key(DEPTNO) references DEPT(DEPTNO)
);
desc EMP;
