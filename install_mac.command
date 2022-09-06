#!/bin/sh

cd `dirname $0`
cmake -S . -B build
cmake --build build

cp build/simpleclockwidget /usr/local/bin/simpleclockwidget
