#include "../hpp/Data.hpp"

int main(void)
{
	Data 		*data;
	Data		*convert;
	uintptr_t	raw;

	data = new Data();
	raw = serialize(data);
	cout<<raw<<endl;
	cout<<data<<endl;
	convert = deserialize(raw);
	convert->printData();
	delete data;
	return (0);
}
