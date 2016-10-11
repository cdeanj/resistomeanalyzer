# Resistome Analyzer

## Overview
Resistome Analyzer is a simple tool for analyzing the resistome of large metagenomic dataets. This program takes in as input a ([SAM](http://samtools.github.io/hts-specs/SAMv1.pdf)) formatted alignment file, a [FASTA](https://en.wikipedia.org/wiki/FASTA_format) formatted reference database, and a [CSV](https://en.wikipedia.org/wiki/Comma-separated_values) formatted annotation database. The alignment file is treated as the sample resistome. This is done by counting each alignment for each target gene found in the alignment file. 
## Output
The output consists of four [TSV](https://en.wikipedia.org/wiki/Tab-separated_values) text files, one for each level of the annotation database hierarchy (gene, group, mechanism, class). Within each file, the first column lists the sample that was analyzed (SAM file), the second column lists the gene, group, mechanism or class that was identified, and the third column gives the total count of reads that aligned to the target gene, group, mechanism or class. For the gene-level output, there is a fourth column that describes the gene fraction, which can be defined as the proportion of nucleotides in the reference sequence that were aligned to by at least one sequence read. This threshold is user-defined, however, it is recommended to set this parameter to a value of 80 in order to decrease the amount of false positive gene identifications.

| Sample    | Group        | Hits |  Sample     |
| ----------|:------------:|:----:| :----------:|
| alignment | AAC6-PRIME   | 3    |  alignment  |
| alignment | ACT          | 1    |  alignment  |
| alignment | ANT2-DPRIME  | 1    |  alignment  |
 
## Installation
```bash
$ git clone https://github.com/cdeanj/resistomeanalyzer.git
$ cd resistomeanalyzer
$ make
$ ./resistome
```

## Usage
```bash
$ ./resistome [options]
```

## Options

##### `-ref_fp`
Path to fasta formatted reference sequence
```bash
$ -amr_fp /path/to/your/reference_sequence.fasta
```

##### `-annot_fp`
Path to CSV formatted annotations database
```
$ -annot_fp /path/to/your/annotation_database.csv
```

##### `-sam_fp`
Path to SAM formatted alignment file
```bash
$ -sam_fp /path/to/your/alignment.sam
```
