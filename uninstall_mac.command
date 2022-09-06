#!/bin/sh

rm /usr/local/bin/simpleclockwidget

if [ $? -eq 0 ]; then
    echo uninstall succeeded
else
    echo not installed
fi
