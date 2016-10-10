# Resistome Analyzer

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
