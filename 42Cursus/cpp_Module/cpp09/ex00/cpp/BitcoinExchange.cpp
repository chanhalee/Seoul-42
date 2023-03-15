#include "../hpp/BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(){

}

BitcoinExchange::BitcoinExchange(const char *args){

	std::ifstream dataIn;
	std::ifstream csvIn;
	std::string csvFile;
	std::string to;
	std::string line;

	inputFile = string(args);
	csvFile = "data.csv";
	dataIn.open(inputFile);
	if (!dataIn.is_open())
	{
		std::cout<<"input file open error!"<<std::endl;
		throw ErrException();
	}
	csvIn.open(csvFile);
	if (!csvIn.is_open())
	{
		dataIn.close();
		std::cout<<"csv file open error!"<<std::endl;
		throw ErrException();
	}
	std::getline(csvIn, line);
	while (! csvIn.eof()){
		std::getline(csvIn, line);
		size_t tmp = line.find(",");
		// cout<<line.substr(0, tmp)<<endl;
		// cout<<line.substr(tmp+1)<<endl;
		if(! csvIn.eof())
			dataMap.insert(std::pair<string, float>(line.substr(0, tmp), std::atof(line.substr(tmp+1).c_str())));
	}
	csvIn.close();
	dataIn.close();
}


int	BitcoinExchange::validateLine(string lined)
{
	int count = 0;
	string line(lined);
	size_t i = 0;
	size_t prevI = 0;
	bool firstC = false;
	bool secC = false;
	while (i < line.length())
	{
		if (line[i] == '-'){
			count++;
		}
		if (count == 1 && !firstC){
			firstC = true;
			if (std::atoi(line.substr(0, i).c_str()) < 2009 | std::atoi(line.substr(0, i).c_str()) > 2023 )
			{
				std::cout << "Error: bad input5" << std::endl;
				return 0;
			}
			prevI = i;
		}
		if (count == 2 && !secC){
			secC = true;
			
			if (std::atoi(line.substr(prevI+2, i).c_str()) < 1 | std::atoi(line.substr(prevI+2, i).c_str()) > 12 )
			{
				std::cout << "Error: bad input6" << std::endl;
				return 0;
			}
			prevI = i;
		}
		i++;
	}

	if (count != 2) {
		std::cout << "Error: bad input4" << std::endl;
		return 0;
	}
	
	i = line.find("|");
	if (i == 0) {
		std::cout << "Error: bad input3" << std::endl;
		return 0;
	}

	if (std::atoi(line.substr(prevI+1, i-1).c_str()) < 1 | std::atoi(line.substr(prevI+1, i-1).c_str()) > 31 )
	{
		std::cout << "Error: bad input7" << std::endl;
		return 0;
	}
	prevI = i;

	string num = line.substr(line.find("|")+2, line.length());
	
	// bool firstDot = false;
	// size_t it = 0;
	if (num.length() < 1){
		std::cout << "Error: bad input2" << std::endl;
		return 0;
	}
	// while(it < num.length() - 1)
	// {
	// 	if (num[it] == '.')
	// 	{
	// 		if (!firstDot){
	// 			firstDot = true;
	// 			it++;
	// 			continue;
	// 		}
	// 		else{
	// 			std::cout << "Error: bad input" << std::endl;
	// 			return 0;
	// 		}
	// 	}
	// 	if (num[it] >= '0' && num[it] <= '9')
	// 	{
	// 		it++;
	// 		continue;
	// 	}
	// 	// cout<<"/"<<it<<" "<<num<<" "<<num[it]<<"/"<<endl;
	// 	std::cout << "Error: bad input1" << std::endl;
	// 	return 0;
	// }
	// if (num > string("2147483648")){
	// 	std::cout << "Error: bad inputk" << std::endl;
	// 	return 0;
	// }
	return 1;
}


BitcoinExchange::~BitcoinExchange(){

}

const char *BitcoinExchange::ErrException::what() const throw()
{
	return "Error";
}

void BitcoinExchange::analysis()
{
	std::ifstream dataIn(inputFile);
	std::string lines;
	if (!dataIn.is_open())
	{
		std::cout<<"input file open error!"<<std::endl;
		throw ErrException();
	}
	getline(dataIn, lines);
	while (!dataIn.eof()){
		string line;
		getline(dataIn, line);
		if(!validateLine(line)){
			continue;
		}
		else{
			if (std::atof(line.substr(line.find("|")+1).c_str()) > 1000 || std::atof(line.substr(line.find("|")+1).c_str()) < 0){
				cout << "Error: bad input10" << std::endl;

				continue;
			}
			map<string, float>::iterator it = dataMap.end();
			size_t iter_idx = dataMap.size();
			float price = 0.0;
			while (it != dataMap.begin()){
				if (compStr((*it).first,line.substr(0, line.find(" |")))){
					price = (*it).second;
					break;
				}
				it--;
				iter_idx--;
			}
			string line2 = line.substr(line.find("|") + 2, line.length()-1);
			float su = std::atof(line2.c_str());
			cout<<line.substr(0, line.find(" |"))<<" => ";
			cout<<su;
			price = (price * std::atof(line.substr(line.find("|")+2).c_str()));
			cout<<" = ";
			cout << price<<endl;



		}
	}

	dataIn.close();
}

string BitcoinExchange::toStr(int data)
{
	string str = "";
	int i = 0;
	char tmp[2];
	tmp[0] = 0;
	tmp[1] = 0;
	while (data >= 10)
	{
		i = data % 10;
		tmp[0] = '0'+i;
		str.insert(0, tmp);
		data = data / 10;
	}
	i = data % 10;
	tmp[0] = '0'+i;
	str.insert(0,tmp);

	return str;
}
bool BitcoinExchange::compStr(string str1, string str2){
	size_t idx = 0;
	while(idx < str1.length() && idx < str2.length() && str1[idx] != '\n' && str2[idx] != '\n'){
		if (str1[idx] < str2[idx]){
			return true;
		}
		if(str1[idx] > str2[idx]){
			return false;
		}
		if (str1[idx] == str2[idx] && idx == 9){
			return true;
		}
		idx++;
	}
	return false;
}
BitcoinExchange::PmergeSub::PmergeSub():a(0), b(0)
{
	
}
BitcoinExchange::PmergeSub::PmergeSub(const PmergeSub &pmergeSub):a(pmergeSub.a), b(pmergeSub.b){

}
BitcoinExchange::PmergeSub::PmergeSub(int aa, int bb):a(aa), b(bb){

}
BitcoinExchange::PmergeSub& BitcoinExchange::PmergeSub::operator=(const PmergeSub &pmergeSub){
	a = pmergeSub.a;
	b = pmergeSub.b;
	return *this;
}

bool BitcoinExchange::PmergeSub::operator<(const PmergeSub &pmergeSub) const {
	return a > pmergeSub.getA();
}

bool BitcoinExchange::PmergeSub::operator>(const PmergeSub &pmergeSub) const {
	return a < pmergeSub.getA();
}

BitcoinExchange::PmergeSub::~PmergeSub(){

}

int BitcoinExchange::PmergeSub::getA() const
{
	return a;
}

int BitcoinExchange::PmergeSub::getB() const
{
	return b;
}

void BitcoinExchange::PmergeSub::setA(int newA)
{
	a = newA;
}

void BitcoinExchange::PmergeSub::setB(int newB)
{
	b = newB;
}
