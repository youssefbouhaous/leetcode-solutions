-- Write your PostgreSQL query statement below
SELECT * FROM CINEMA C WHERE C.ID%2=1 AND DESCRIPTION<>'boring' ORDER BY RATING DESC; 