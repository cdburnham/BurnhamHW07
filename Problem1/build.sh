#!/bin/bash

SetHIGH="GPIO60_high.cpp"
SetLOW="GPIO60_low.cpp"

echo "Building the files..."

sudo g++ $SetHIGH -o GPIO60_high
sudo g++ $SetLOW -o GPIO60_low

echo "Build finished..."
