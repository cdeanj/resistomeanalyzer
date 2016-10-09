output: main.o annotation_reader.o resistome.o fasta_reader.o sam_reader.o record.o utility.o
	g++ -std=c++11 main.o annotation_reader.o resistome.o fasta_reader.o sam_reader.o record.o utility.o -o resistome
main.o: main.cpp
	g++ -c -std=c++11 main.cpp
annotation_reader.o: annotation_reader.cpp
	g++ -c -std=c++11 annotation_reader.cpp
resistome.o: resistome.cpp
	g++ -c -std=c++11 resistome.cpp
fasta_reader.o: fasta_reader.cpp
	g++ -c -std=c++11 fasta_reader.cpp
sam_reader.o: sam_reader.cpp
	g++ -c -std=c++11 sam_reader.cpp
record.o: record.cpp
	g++ -c -std=c++11 record.cpp
utility.o: utility.cpp
	g++ -c -std=c++11 utility.cpp
clean:
	rm *.o resistome
