#include <iostream>

int main(void)
{
	std::string str1 = "HI THIS IS BRAIN";
	std::string	*strPtr = &str1;
	std::string &strRef = str1;

	std::cout<<"The memory address of the string variable"<<std::endl;
	std::cout<<"&str1: "<<&str1<<std::endl;
	std::cout<<"The memory address held by stringPTR"<<std::endl;
	std::cout<<"strPtr: "<<strPtr<<std::endl;
	std::cout<<"The memory address held by stringREF"<<std::endl;
	std::cout<<"&strRef: "<<&strRef<<std::endl;
	std::cout<<"\n\n========================\n\n";
	std::cout<<"The value of the string variable"<<std::endl;
	std::cout<<"str1: "<<str1<<std::endl;
	std::cout<<"The value pointed to by stringPTR"<<std::endl;
	std::cout<<"*strPtr: "<<*strPtr<<std::endl;
	std::cout<<"The value pointed to by stringREF"<<std::endl;
	std::cout<<"strRef: "<<strRef<<std::endl;
	return (0);
}