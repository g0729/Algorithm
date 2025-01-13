-- 코드를 작성해주세요
SELECT B.ID
    ,B.GENOTYPE
    ,R.GENOTYPE as PARENT_GENOTYPE
FROM ECOLI_DATA B
JOIN ECOLI_DATA R
ON B.PARENT_ID = R.ID
WHERE (B.GENOTYPE ^ R.GENOTYPE) & R.GENOTYPE  = 0 
ORDER BY B.ID
