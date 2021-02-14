#include <iostream>

int main(){
	int a = 5;
	int* lol = &a;

	if(lol)
		std::cout << "yas" ;
	else
		std::cout << "no" ;
}
