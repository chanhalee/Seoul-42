#include "../hpp/PmergeMe.hpp"

int main(int argc, char **argv)
{
	string str("");
	int i = 0;

	if (argc<2)
	{
		cout<<"No args input"<<endl;
	}
	try {
		while(++i < argc)
		{
			str.append(argv[i]);
			if(i+1 != argc)
			{
				str.append(" ");
			}
		}
		PmergeMe pmergeMe(str);
		double sortDeqT = pmergeMe.sortDeq();
		double sortVecT = pmergeMe.sortVec();
		deque<int> data = pmergeMe.getData();
		deque<int> sortResult = pmergeMe.getResult();
		cout<<"Before: ";
		deque<int>::iterator it1 = data.begin();
		while(it1 != data.end()){
			cout<<" "<<*it1;
			it1++;
		}
		cout<<endl;
		cout<<"After: ";
		deque<int>::iterator it2 = sortResult.begin();
		while(it2 != sortResult.end()){
			cout<<" "<<*it2;
			it2++;
		}
		cout<<endl;
		cout<<"Time to process a range of "<<data.size()<<" elements with std::deque : "<<sortDeqT<<" ms"<<endl;
		cout<<"Time to process a range of "<<data.size()<<" elements with std::vector : "<<sortVecT<<" ms"<<endl;
	}
	catch(const std::exception& e)
	{
		cout << e.what() << '\n';
	}
	return 0;
}