#!/bin/bash
echo "BENCHMARKING OF "$1>>$2
echo "PROBLEM SIZE 64: ">>$2

#/usr/bin/time --output=$2 --append  ./$1 64 >>$2;
perf stat -a ./$1 64 >>$2 2>&1
#valgrind --log-fd=9 9>>$2 ./$1 64 >>$2;
echo "=======================================">>$2
echo "PROBLEM SIZE 128: ">>$2
#/usr/bin/time --output=$2 --append  ./$1 128 >>$2;
perf stat -a ./$1 128 >>$2 2>&1
valgrind --log-fd=9 9>>$2 ./$1 128 >>$2;
echo "=======================================">>$2
echo "PROBLEM SIZE 512: ">>$2
#/usr/bin/time --output=$2 --append  ./$1 512 >>$2;
perf stat -a ./$1 512 >>$2 2>&1
#valgrind --log-fd=9 9>>$2 ./$1 512 >>$2;
echo "=======================================">>$2
echo "PROBLEM SIZE 1024: ">>$2
#/usr/bin/time --output=$2 --append  ./$1 1024 >>$2;
perf stat -a ./$1 1024 >>$2 2>&1
#valgrind --log-fd=9 9>>$2 ./$1 1024 >>$2;
echo "=======================================">>$2
echo "PROBLEM SIZE 2048: ">>$2
#/usr/bin/time --output=$2 --append  ./$1 2048 >>$2;
perf stat -a ./$1 2048 >>$2 2>&1
#valgrind --log-fd=9 9>>$2 ./$1 2048 >>$2;
echo "PROBLEM SIZE 64: ">>$2

/usr/bin/time --output=$2 --append  ./$1 64 >>$2;
perf stat -a ./$1 64 >>$2 2>&1

echo "=======================================">>$2
echo "PROBLEM SIZE 128: ">>$2
#/usr/bin/time --output=$2 --append  ./$1 128 >>$2;
perf stat -a ./$1 128 >>$2 2>&1
valgrind --log-fd=9 9>>$2 ./$1 128 >>$2;
echo "=======================================">>$2
echo "PROBLEM SIZE 512: ">>$2
#/usr/bin/time --output=$2 --append  ./$1 512 >>$2;
perf stat -a ./$1 512 >>$2 2>&1

echo "=======================================">>$2
echo "PROBLEM SIZE 1024: ">>$2
#/usr/bin/time --output=$2 --append  ./$1 1024 >>$2;
perf stat -a ./$1 1024 >>$2 2>&1

echo "=======================================">>$2
echo "PROBLEM SIZE 2048: ">>$2
#/usr/bin/time --output=$2 --append  ./$1 2048 >>$2;
perf stat -a ./$1 2048 >>$2 2>&1

echo "PROBLEM SIZE 64: ">>$2

#/usr/bin/time --output=$2 --append  ./$1 64 >>$2;
perf stat -a ./$1 64 >>$2 2>&1
echo "=======================================">>$2
echo "PROBLEM SIZE 128: ">>$2
#/usr/bin/time --output=$2 --append  ./$1 128 >>$2;
perf stat -a ./$1 128 >>$2 2>&1
 
echo "=======================================">>$2
echo "PROBLEM SIZE 512: ">>$2
#/usr/bin/time --output=$2 --append  ./$1 512 >>$2;
perf stat -a ./$1 512 >>$2 2>&1
valgrind --log-fd=9 9>>$2 ./$1 512 >>$2;
echo "=======================================">>$2
echo "PROBLEM SIZE 1024: ">>$2
#/usr/bin/time --output=$2 --append  ./$1 1024 >>$2;
perf stat -a ./$1 1024 >>$2 2>&1

echo "=======================================">>$2
echo "PROBLEM SIZE 2048: ">>$2
#/usr/bin/time --output=$2 --append  ./$1 2048 >>$2;
perf stat -a ./$1 2048 >>$2 2>&1

