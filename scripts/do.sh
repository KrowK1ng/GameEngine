#!/bin/sh

file="object_manager.h"

make_includes(){
	cat lol | sed "s/\s*//g" | while read in
	do
		printf "\t\tcase %s:\n" "$in" >> "$file"
		printf "\t\t\ts%s->Render(_x,_y);\n\t\t\tbreak;\n" "$in" >> "$file"
	done
}

make_includes
