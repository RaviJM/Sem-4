select e_emp.* from EMP e_emp, EMP e_mgr where e_emp.hiredate<e_mgr.hiredate and e_emp.mgr=e_mgr.empno;