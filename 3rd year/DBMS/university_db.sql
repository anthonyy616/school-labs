USE university_db;

-- 1
SELECT COUNT(*) AS total_courses, AVG(credits) AS avg_credits
FROM course;

-- 2
SELECT COUNT(DISTINCT course_id) AS distinct_courses, COUNT(*) AS total_sections
FROM section WHERE semester = 'Spring' AND year = 2024;

-- 3
SELECT dept_name, COUNT(ID) AS num_instructors, AVG(salary) AS avg_salary
FROM instructor GROUP BY dept_name ORDER BY avg_salary DESC;

-- 4
SELECT dept_name, COUNT(ID) AS num_students, AVG(tot_cred) AS avg_credits
FROM student GROUP BY dept_name ORDER BY num_students DESC;

-- 5
SELECT building, COUNT(*) AS num_sections, AVG(capacity) AS avg_capacity
FROM section s JOIN classroom c ON s.building = c.building AND s.room_number = c.room_number
WHERE semester = 'Fall' AND year = 2023 GROUP BY building;

-- 6
SELECT dept_name FROM student GROUP BY dept_name HAVING AVG(tot_cred) > 25;

-- 7
SELECT dept_name, COUNT(ID) AS num_students, AVG(tot_cred) AS avg_credits
FROM student GROUP BY dept_name HAVING num_students > 5;

-- 8
SELECT d.dept_name, SUM(i.salary) AS total_salary, d.budget
FROM department d LEFT JOIN instructor i ON d.dept_name = i.dept_name
GROUP BY d.dept_name, d.budget HAVING total_salary > d.budget;