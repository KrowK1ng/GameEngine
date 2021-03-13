#!/bin/sh

otype="$1"
newname="$2"
classname="$3"
definename="$4"

cp scripts/objects/"$otype".h temp/"$newname".h
cp scripts/objects/"$otype".cpp temp/"$newname".cpp

sed "s/PLACE_HOLDER_FILE_NAME/${newname}/g" temp/"$newname".cpp -i
sed "s/PLACE_HOLDER_CLASS/${classname}/g" temp/"$newname".cpp -i
sed "s/PLACE_HOLDER_DEFINE/${definename}/g" temp/"$newname".cpp -i
sed "s/PLACE_HOLDER_CLASS/${classname}/g" temp/"$newname".h -i
sed "s/PLACE_HOLDER_DEFINE/${definename}/g" temp/"$newname".h -i

#pick destination with lf
newdir="$(pickdir)"
mv temp/"$newname".cpp "$newdir"/"$newname".cpp
mv temp/"$newname".h "$newdir"/"$newname".h
