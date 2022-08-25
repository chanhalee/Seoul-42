#include "../hpp/Data.hpp"

Data::Data():dataContain(0)
{
	cout<<"[Data] "<<"Default constructor called."<<endl;
}
Data::Data(const Data &data):dataContain(data.dataContain)
{
	
	cout<<"[Data] "<<"Copy constructor called."<<endl;
}
Data &Data::operator=(const Data &data)
{
	dataContain = data.dataContain;
	cout<<"[Data] "<<"Copy assignment operator called."<<endl;
	return(*this);
}
Data::~Data()
{
	cout<<"[Data] "<<"Destructor called."<<endl;
}

void Data::printData() const
{
	cout<<"Data: "<<dataContain<<endl;
}

uintptr_t serialize(Data* ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}
Data* deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data *>(raw));
}
