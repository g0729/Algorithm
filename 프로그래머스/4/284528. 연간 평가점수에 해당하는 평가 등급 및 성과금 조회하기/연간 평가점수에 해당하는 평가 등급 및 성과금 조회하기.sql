WITH TEMP AS (SELECT
                EMP_NO,
                CASE
                    WHEN SUM(SCORE) >= 192 THEN "S"
                    WHEN SUM(SCORE) >= 180 THEN "A"
                    WHEN SUM(SCORE) >= 160 THEN "B"
                    ELSE "C"
                 END AS GRADE
                FROM
                    HR_GRADE
                GROUP BY
                    EMP_NO
)
SELECT
    B.EMP_NO,
    B.EMP_NAME,
    R.GRADE,
    CASE
        WHEN R.GRADE = "S" THEN SAL * 0.20
        WHEN R.GRADE = "A" THEN SAL * 0.15
        WHEN R.GRADE = "B" THEN SAL * 0.1
        ELSE 0
    END AS BONUS
FROM 
    HR_EMPLOYEES B
JOIN
    TEMP R
ON
    B.EMP_NO = R.EMP_NO
ORDER BY
    B.EMP_NO