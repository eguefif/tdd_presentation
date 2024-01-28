#!/bin/bash

cat map.ber > d1
./TDD map.ber > d2
diff -q d1 d2
rm d1 d2
