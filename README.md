# PDP-1 Playground

## Dependencies
```
sudo apt-get install git build-essential flex bison texinfo libgmp3-dev libmpfr-dev libmpc-dev simh dejagnu
```

## Building binutils
```
cd pdp1-binutils
./configure --target=pdp1-elf --disable-sim
make -j $(nproc)
sudo make install
```

## Building gcc
```
mkdir -p build-gcc
cd build-gcc
../pdp1-gcc/configure --target=pdp1-elf --enable-languages=c --disable-bootstrap --enable-gcov=no --enable-shared=no
make -j $(nproc) all-gcc
make -j $(nproc) all-target-libgcc
```

## Building and running samples

```
cd c-print-for-loop
make main.s main.rim run
```

## Running tests
```
runtest --srcdir $(pwd)
```
