#include "../hpp/BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	std::ofstream fout;
	std::ifstream fin;
	std::string txtFile;
	std::string csvFile;
	std::string to;
	std::string line;

	if (argc != 2)
	{
		std::cout<<"argument error!"<<std::endl;
		return (0);
	}
	txtFile = argv[1];
	try{
		BitcoinExchange bit(argv[1]);
		bit.analysis();
	} 
	catch(const std::exception& e)
	{
		cout << e.what() << '\n';
	}
	return (0);
	

}