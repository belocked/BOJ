-- 코드를 입력하세요
SELECT pt_name, pt_no, gend_cd, age, IFNULL(tlno, 'NONE') as tlno
from patient
where age < 13 and gend_cd = 'W'
order by age desc, pt_name asc