#!/bin/sh

file="$1"

make_includes(){
	find src/objects | sed -n "/.h$/p" | while read in
	do
		printf "#include \"%s\"\n" "$(echo "$in" | sed "s/src\///")" >> "$file"
	done
}

make_list(){
	find src/objects | sed -n "/.h$/p" | while read in
	do
		sed -n "/class/p" "$in" | sed "s/.*class\s*//;s/\s*:.*//" | while read name
		do
			printf "\t\tif (name == \"%s\") return new %s(x,y);\n" $name $name >> "$file"
		done
	done
} 

delete_files(){
	find include/objects/objects | sed -n "/.cpp$/p" | while read in
	do
		rm -rf "$in"
	done
}

printf "#include \"gengine.h\"\n" >> "$file"
make_includes
printf "\nnamespace object{\n" >> "$file"
printf "\tObject* CreateObject(std::string name, int x, int y){\n" >> "$file"
make_list
printf "\t\tstd::cout << \"Unable to find \" << name << \". Look again at object name.\" << std::endl;\n" >> "$file"
printf "\t\treturn new Object(x,y);\n" >> "$file"
printf "\t}\n" >> "$file"
printf "}\n" >> "$file"

mv "$file" include/objects/"$file"
cp -r src/objects include/objects/objects
delete_files
