-- 코드를 입력하세요
SELECT
    FOOD_TYPE,
    REST_ID,
    REST_NAME,
    FAVORITES
FROM
    (
        SELECT 
            *,
            MAX(FAVORITES) OVER (PARTITION BY (FOOD_TYPE)) AS MAX_FAV
        FROM
            REST_INFO
    ) AS R
WHERE
    FAVORITES = MAX_FAV
ORDER BY
    FOOD_TYPE DESC