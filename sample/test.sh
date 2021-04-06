#!/bin/bash

make clean
make

./bin/fp 0.5 ../input_pa2/ami33.block ../input_pa2/ami33.nets mylogs
cat mylogs
rm mylogs
