Coverage Sampler: A simple tool for calculating the amount of a gene that is covered by a sample of alignments.

#### Installation
```
git clone https://github.com/cdeanj/coverage_sampler
cd coverage_sampler
make
./csa
```

#### Usage
Usage: csa [options]

Options:

    -ref_fp    STR/FILE	    ref file path
    -sam_fp    STR/FILE	    sam file path
    -min       INT      	starting sample level
    -max       INT	        ending sample level
    -skip      INT	        amount of sample levels to skip
    -t         INT	        gene fraction threshold
    -samples   INT	        iterations per sample level
    -out_fp    STR/FILE	    output file path

#### Output

The output is a tab delimited text file with five columns
```
Level   Iteration   Gene Id Gene Fraction   Hits
```

* Level: the sampling percent alignments were taken at
* Iteration: the ith iteration of the current sample level
* Gene Id: the reference sequence having a gene fraction greater than the threshold
* Gene Fraction: the number of bases covered by the sample of alignments
* Hits: the number of alignments that had bases cover the reference sequence
