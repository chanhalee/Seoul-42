#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <algorithm>
#include <exception>
#include <stack>
#include <deque>
#include <vector>
#include <ctime>

using std::cout;
using std::endl;
using std::string;
using std::find;
using std::deque;
using std::vector;
using std::ostream;

class PmergeMe{

private:
	deque<int> data;
	deque<int> sortResult;

public:
	PmergeMe();
	PmergeMe(const PmergeMe &pmergeMe);
	PmergeMe(const string argv);
	PmergeMe &operator=(const PmergeMe &pmergeMe);
	~PmergeMe();

	deque<int> getData() const;
	deque<int> getResult() const;
	double sortDeq();
	double sortVec();
	string static toStr(int data);

	void validateNumber(string num);


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
ostream &operator <<(ostream &os, const PmergeMe &pmergeMe);
ostream &operator <<(ostream &os, const PmergeMe::PmergeSub &pmergeSub);

#endif