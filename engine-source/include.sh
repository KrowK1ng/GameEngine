#!/bin/sh

rm gengine.h

ls *.h | while read in
do
	echo "#include \"$in\"" >> gengine.h
done;

mv gengine.h ../include/
