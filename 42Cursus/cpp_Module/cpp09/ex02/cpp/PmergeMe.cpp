#include "../hpp/PmergeMe.hpp"

PmergeMe::PmergeMe(): data(0), sortResult(0)
{

}

PmergeMe::PmergeMe(const PmergeMe &pmergeMe): data(pmergeMe.getData()), sortResult(pmergeMe.getResult())
{
	
}

PmergeMe &PmergeMe::operator=(const PmergeMe &pmergeMe){
	data = pmergeMe.getData();
	sortResult = pmergeMe.getResult();
	return *this;
}

PmergeMe::PmergeMe(const string argv)
{
 	string tmpStr(argv);
 	while(true)
 	{
 		size_t pos = tmpStr.rfind(" ", string::npos);
 		if (pos == string::npos)
 			break;
 		if (pos+1 == tmpStr.length())
 			throw ErrException();
 		string tok = tmpStr.substr(pos + 1);
		validateNumber(tok);
 		data.push_front(std::atoi(tok.c_str()));
 		tmpStr.erase(pos, string::npos);
 	}
 	string tok = tmpStr.substr(0);
	validateNumber(tok);
 	data.push_front(std::atoi(tok.c_str()));
	if (data.size() < 1)
		throw ErrException();
}

PmergeMe::~PmergeMe()
{
}

deque<int> PmergeMe::getData() const
{
	return data;
}

double PmergeMe::sortDeq()
{
	std::clock_t startT;
	std::clock_t endT;

	startT = std::clock();

	deque<int> result;
	deque<PmergeSub> dataFirst;
	int i = 0;
	int j = 0;

	deque<int>::iterator it = data.begin();
	while (it != data.end())
	{
		int arr[2];
		i = *it;
		PmergeSub tmp;
		if ((it+1) == data.end())
		{
			arr[0] = -1;
			arr[1] = *it;
			it++;
			dataFirst.push_back(PmergeSub(arr[0], arr[1]));
			break;
		}
		it++;
		j = *it;
		it++;
		if ( i < j )
		{
			arr[0] = j;
			arr[1] = i;
		}
		else
		{
			arr[0] = i;
			arr[1] = j;
		}
		dataFirst.push_back(PmergeSub(arr[0], arr[1]));
	}
	std::sort(dataFirst.begin(), dataFirst.end());

	// deque<PmergeSub>::iterator it2 = dataFirst.begin();

	// while (it2 != dataFirst.end())
	// {
	// 	cout<<"A: "<< (*it2).getA()<<"  B: "<< (*it2).getB()<<endl;
	// 	it2++;
	// }


	deque<PmergeSub>::iterator it2 = dataFirst.begin();

	while (it2 != dataFirst.end())
	{
		result.push_front((*it2).getA());
		it2++;
	}
	if (result.front() == -1){
		result.erase(result.begin());
	}
	
	it2 = dataFirst.begin();
	while (it2 != dataFirst.end())
	{
		int b = (*it2).getB();
		size_t begin = 0;
		size_t end = result.size() - 1;
		size_t mid = (begin + end) /2;
		while (end != begin)
		{
			mid = (begin + end)/2;
			if (result.at(mid) < b)
			{
				begin = mid + 1;
			}
			else if (result.at(mid) == b)
			{
				throw ErrException();
			}
			else 
			{
				end = mid;
			}
		}
		if (result.at(end) < b){
			result.insert(result.begin()+end+ 1, b);
		}
		else{
			result.insert(result.begin()+end, b);
		}
		it2++;
	}
	endT = std::clock();
	sortResult = result;
	return (double)1000.0*(endT - startT) / CLOCKS_PER_SEC;
}

double PmergeMe::sortVec()
{
	std::clock_t startT;
	std::clock_t endT;

	startT = std::clock();

	vector<int> result;
	vector<PmergeSub> dataFirst;
	int i = 0;
	int j = 0;

	deque<int>::iterator it = data.begin();
	while (it != data.end())
	{
		int arr[2];
		i = *it;
		PmergeSub tmp;
		if ((it+1) == data.end())
		{
			arr[0] = -1;
			arr[1] = *it;
			it++;
			dataFirst.push_back(PmergeSub(arr[0], arr[1]));
			break;
		}
		it++;
		j = *it;
		it++;
		if ( i < j )
		{
			arr[0] = j;
			arr[1] = i;
		}
		else
		{
			arr[0] = i;
			arr[1] = j;
		}
		dataFirst.push_back(PmergeSub(arr[0], arr[1]));
	}
	std::sort(dataFirst.begin(), dataFirst.end());

	// deque<PmergeSub>::iterator it2 = dataFirst.begin();

	// while (it2 != dataFirst.end())
	// {
	// 	cout<<"A: "<< (*it2).getA()<<"  B: "<< (*it2).getB()<<endl;
	// 	it2++;
	// }


	vector<PmergeSub>::iterator it2 = dataFirst.begin();

	while (it2 != dataFirst.end())
	{
		result.insert(result.begin(),(*it2).getA());
		it2++;
	}
	if (result.front() == -1){
		result.erase(result.begin());
	}
	
	it2 = dataFirst.begin();
	while (it2 != dataFirst.end())
	{
		int b = (*it2).getB();
		size_t begin = 0;
		size_t end = result.size() - 1;
		size_t mid = (begin + end) /2;
		while (end != begin)
		{
			mid = (begin + end)/2;
			if (result.at(mid) < b)
			{
				begin = mid + 1;
			}
			else if (result.at(mid) == b)
			{
				throw ErrException();
			}
			else 
			{
				end = mid;
			}
		}
		if (result.at(end) < b){
			result.insert(result.begin()+end+ 1, b);
		}
		else{
			result.insert(result.begin()+end, b);
		}
		it2++;
	}
	endT = std::clock();
	return (double)1000.0*(endT - startT) / CLOCKS_PER_SEC;
}

string PmergeMe::toStr(int data)
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

deque<int> PmergeMe::getResult() const
{
	return sortResult;
}


void PmergeMe::validateNumber(string num)
{
	size_t it = 0;
	const char *str(num.c_str());
	if (num.length() < 1)
		throw ErrException();
	while(it < num.length())
	{
		if (str[it] >= '0' && str[it] <= '9')
		{
			it++;
			continue;
		}
		throw ErrException();
	}
}


const char *PmergeMe::ErrException::what() const throw()
{
	return "Error";
}



PmergeMe::PmergeSub::PmergeSub():a(0), b(0)
{
	
}
PmergeMe::PmergeSub::PmergeSub(const PmergeSub &pmergeSub):a(pmergeSub.a), b(pmergeSub.b){

}
PmergeMe::PmergeSub::PmergeSub(int aa, int bb):a(aa), b(bb){

}
PmergeMe::PmergeSub& PmergeMe::PmergeSub::operator=(const PmergeSub &pmergeSub){
	a = pmergeSub.a;
	b = pmergeSub.b;
	return *this;
}

bool PmergeMe::PmergeSub::operator<(const PmergeSub &pmergeSub) const {
	return a > pmergeSub.getA();
}

bool PmergeMe::PmergeSub::operator>(const PmergeSub &pmergeSub) const {
	return a < pmergeSub.getA();
}

PmergeMe::PmergeSub::~PmergeSub(){

}

int PmergeMe::PmergeSub::getA() const
{
	return a;
}

int PmergeMe::PmergeSub::getB() const
{
	return b;
}

void PmergeMe::PmergeSub::setA(int newA)
{
	a = newA;
}

void PmergeMe::PmergeSub::setB(int newB)
{
	b = newB;
}


ostream &operator <<(ostream &os, const PmergeMe &pmergeMe)
{
	deque<int> data = (pmergeMe.getData());
	string str;
	while(!data.empty())
	{
		str.append(PmergeMe::toStr(data.front()));
		data.erase(data.begin());
		if (data.size() != 0)
			str.append(" ");
	}
	os<<"data: "<<str<<endl;
	return (os);
}

ostream &operator <<(ostream &os, const PmergeMe::PmergeSub &pmergeSub)
{
	os<<"a: "<<pmergeSub.getA()<<"|  b: "<<pmergeSub.getB()<<endl;
	return (os);
}