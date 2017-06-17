gcc -c -O -fpic -Wwrite-strings ExtFuns.c
ld -G ExtFuns.o -lm -lc -o ExtFuns.so
gcc -c -O -fpic -Wwrite-strings Ping.c
ld -G Ping.o -lm -lc -o Ping.so
sudo cp ExtFuns.so Ping.so /usr/lib/firebird/UDF