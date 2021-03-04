#!/bin/sh

file="object_manager.h"
cppfile="object_manager.cpp"

make_includes(){
	find src/objects | sed -n "/.h$/p" | while read in
	do
		printf "#include \"%s\"\n" "$(echo "$in" | sed "s/src\///")" >> "$file"
	done
}

make_list(){
	find src/objects | sed -n "/.h$/p" | while read in
	do
		sed -n "/class/p;/^\/\/GAME-ENGINE-IGNORE/q" "$in" | sed "s/.*class\s*//;s/\s*:.*//;s/\s.*//" | while read name
		do
			printf "\t\tif (name == \"%s\") return new %s(x,y);\n" $name $name >> "$cppfile"
		done
	done
} 

delete_files(){
	find include/objects/objects | sed -n "/.cpp$/p" | while read in
	do
		rm -rf "$in"
	done
}

rm -rf include/objects/*


printf "#include \"gengine.h\"\n" >> "$file"
make_includes
printf "\nnamespace object{\n" >> "$file"
printf "\tObject* CreateObject(std::string name, int x, int y);\n" >> "$file"
printf "}\n" >> "$file"
mv "$file" include/objects/"$file"

# object_control.cpp

printf "#include \"%s\"\n" "$file" >> "$cppfile"
printf "\nnamespace object{\n" >> "$cppfile"
printf "\tObject* CreateObject(std::string name, int x, int y){\n" >> "$cppfile"
make_list
printf "\t\tstd::cout << \"Unable to find \" << name << \". Look again at object name.\" << std::endl;\n" >> "$cppfile"
printf "\t\treturn new Object(x,y);\n" >> "$cppfile"
printf "\t}\n" >> "$cppfile"
printf "}\n" >> "$cppfile"
mv "$cppfile" include/objects/"$cppfile"


cp -r src/objects include/objects/objects
delete_files
