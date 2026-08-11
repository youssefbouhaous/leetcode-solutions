-- Write your PostgreSQL query statement below
SELECT * ,
(CASE
WHEN X+Y<=Z OR X+Z<=Y OR Y+Z<=X THEN 'No'
ELSE 'Yes' end
) AS TRIANGLE FROM TRIANGLE;