#!/bin/sh

add_list(){
	find src/objects | sed -n "/.h$/p" | while read in
	do
		echo "$in"
	done
} 

add_list
