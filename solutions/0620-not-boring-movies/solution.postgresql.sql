-- Write your PostgreSQL query statement below
SELECT * FROM CINEMA C
WHERE DESCRIPTION<>'boring' AND ID%2=1 ORDER BY RATING DESC;