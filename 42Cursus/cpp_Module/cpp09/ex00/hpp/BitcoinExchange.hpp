#ifndef BITCOIN_EXCHANGE_HPP
#define BITCOIN_EXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <algorithm>
#include <exception>
#include <map>
#include <ctime>
#include <functional>

using std::cout;
using std::endl;
using std::string;
using std::find;
using std::map;
using std::ostream;

class BitcoinExchange{

private:
	map<string, float> dataMap;
	string inputFile;
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange &bitcoinExchange);
	BitcoinExchange &operator=(const BitcoinExchange &bitcoinExchange);

public:
	BitcoinExchange(const char *args);
	~BitcoinExchange();
	void analysis();
	int validateLine(string line);
	bool compStr(string str1, string str2);
	string toStr(int data);
	
	class ErrException : public std::exception
	{
		public:
			const char *what() const throw();
	};

	class PmergeSub
	{
	private:
		int a;
		int b;
	public:
		PmergeSub();
		PmergeSub(const PmergeSub &pmergeSub);
		PmergeSub(int aa, int bb);
		PmergeSub &operator=(const PmergeSub &pmergeSub);
		bool operator< (const PmergeSub &pmergeSub) const;
		bool operator> (const PmergeSub &pmergeSub) const;
		~PmergeSub();
		int getA() const;
		int getB() const;
		void setA(int newA);
		void setB(int newB);
	};
};

#endif