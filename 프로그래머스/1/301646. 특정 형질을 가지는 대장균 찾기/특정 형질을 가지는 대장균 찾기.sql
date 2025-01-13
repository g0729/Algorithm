select count(*) as COUNT from ECOLI_DATA
where !(GENOTYPE & 2) and (GENOTYPE & 1 or GENOTYPE & 4)