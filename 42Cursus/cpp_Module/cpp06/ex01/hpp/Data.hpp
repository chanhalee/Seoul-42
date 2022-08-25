#ifndef DATA_HPP
#define DATA_HPP


#include <iostream>

using std::cout;
using std::endl;
using std::string;

class Data
{
private:
	int dataContain;
public:
	Data();
	Data(const Data &data);
	Data &operator=(const Data &data);
	void printData() const;
	~Data();
};
uintptr_t serialize(Data* ptr);
Data* deserialize(uintptr_t raw);

#endif