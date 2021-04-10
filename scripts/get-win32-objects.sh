#!/bin/sh

find src/objects | sed -n "/.cpp$/p" | sed "s/.cpp$/.o/;s/src/win32-temp/" | while read file; do
    if [[ "$file" = */* ]]; then
        mkdir -p "${file%/*}"; >> /dev/null
    fi;
done

find src/objects | sed -n "/.cpp$/p" | sed "s/.cpp$/.o/;s/src/win32-temp/"
#find src/objects | sed -n "/.cpp$/p" 
