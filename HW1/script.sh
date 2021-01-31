gcc main.c -c
gcc quicksort.c -c
gcc selectionsort.c -c 
gcc bubblesort.c -c
gcc main.c

mkdir readelf_logs/

readelf -a main.o >readelf_logs/elflog_main.txt
readelf -a bubblesort.o >readelf_logs/elflog_bubble.txt
readelf -a quicksort.o >readelf_logs/elflog_quick.txt
readelf -a selectionsort.o >readelf_logs/elflog_sel.txt
readelf -a a.out >readelf_logs/elflog_exec.txt
