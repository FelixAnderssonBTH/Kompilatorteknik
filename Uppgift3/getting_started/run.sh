#!/bin/bash
make clean
make compiler
./compiler test.txt
make tree
