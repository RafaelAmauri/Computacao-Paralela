gcc sieve.c -fopenmp -lm


for i in {1..6}; do
	echo -e "Round $i:\n"
	
	perf stat -d -d -d -o dados.txt -x ":" ./a.out;

	cat dados.txt | awk -F ":" '/CPUs utilized/ {print "CPUs utilizadas: " $7}';
	cat dados.txt | awk -F ":" '/frontend cycles idle/ {print "Frontend Cycles Idle: " $7 "%"}';
	cat dados.txt | awk -F ":" '/backend cycles idle/ {print "Backend Cyles Idle: " $7 "%"}';
	cat dados.txt | awk -F ":" '/insn per cycle/ {print "IPC: " $7}';
	cat dados.txt | awk -F ":" '/msec/ {print "Tempo: " $1 "ms"}';

	echo -e "\n"
done
