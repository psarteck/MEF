
#clear
#clear
#gfortran -c *.f
#gcc *.c ./fctTp2/*.c *.o -lm -lfortran
#gcc *.c ./fctTp2/*.c
#gcc -Wall *.c ./fctTp2/*.c *.o -L /usr/local/gfortran -lm
#gfortran -print-search-dirs


clear
clear
gfortran -c *.f
gcc -Wall *.c ./fctTp2/*.c *.o -L/opt/homebrew/Cellar/gcc/13.2.0/bin/../lib/gcc/current -lgfortran -lm && ./a.out



