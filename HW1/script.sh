rm -r readelf_logs
rm *.o
rm *.out

gcc main.c -c
gcc quicksort.c -c
gcc selectionsort.c -c 
gcc bubblesort.c -c
gcc main.c

mkdir readelf_logs
mkdir readelf_logs/unoptimized
mkdir readelf_logs/optimized

readelf -a main.o >readelf_logs/unoptimized/elflog_main.txt
readelf -a bubblesort.o >readelf_logs/unoptimized/elflog_bubble.txt
readelf -a quicksort.o >readelf_logs/unoptimized/elflog_quick.txt
readelf -a selectionsort.o >readelf_logs/unoptimized/elflog_sel.txt
readelf -a a.out >readelf_logs/unoptimized/elflog_exec.txt

rm *.o
rm *.out

gcc main.c -cO
gcc quicksort.c -cO
gcc selectionsort.c -cO
gcc bubblesort.c -cO
gcc main.c -O

readelf -a main.o >readelf_logs/optimized/elflog_main.txt
readelf -a bubblesort.o >readelf_logs/optimized/elflog_bubble.txt
readelf -a quicksort.o >readelf_logs/optimized/elflog_quick.txt
readelf -a selectionsort.o >readelf_logs/optimized/elflog_sel.txt
readelf -a a.out >readelf_logs/optimized/elflog_exec.txt