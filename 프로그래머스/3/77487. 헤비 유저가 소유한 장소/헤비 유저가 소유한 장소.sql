-- 코드를 입력하세요
SELECT
    *
FROM
    PLACES P
WHERE 
    P.HOST_ID IN (
        SELECT
            HOST_ID
        FROM
            PLACES
        GROUP BY
            HOST_ID
        HAVING
            COUNT(*) >=2
    )
ORDER BY
    ID