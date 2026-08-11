-- Write your PostgreSQL query statement below
SELECT QUERY_NAME, ROUND(
    SUM(
        RATING::NUMERIC/POSITION
    )/COUNT(*),2
) AS QUALITY,
ROUND(100*
    SUM(
    CASE
    WHEN RATING <3 THEN 1 ELSE 0 END
    )::NUMERIC/COUNT(*),2
) AS poor_query_percentage
 FROM QUERIES Q GROUP BY QUERY_NAME;