WITH MAX_VIEWS_BOARD AS(
    SELECT
        BOARD_ID 
    FROM 
        USED_GOODS_BOARD
    WHERE
        VIEWS = ( SELECT
                    MAX(VIEWS)
                 FROM
                    USED_GOODS_BOARD
        )
)

SELECT
    CONCAT("/home/grep/src/",U.BOARD_ID,"/",U.FILE_ID,FILE_NAME,FILE_EXT) AS FILE_PATH
FROM
    USED_GOODS_FILE AS U
JOIN
    MAX_VIEWS_BOARD AS M
ON
    U.BOARD_ID = M.BOARD_ID
ORDER BY
    U.FILE_ID DESC