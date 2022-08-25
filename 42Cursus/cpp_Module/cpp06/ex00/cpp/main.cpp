#include <iostream>
#include <limits>
#include <climits>
#include <cfloat>
#include <iomanip>

using std::cout;
using std::endl;
using std::string;

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		cout<<"Not enough arguments!"<<endl;
		return (0);
	}
	string input = argv[1];
	int count_dot = 0;
	int startIndex = -1;
	int endIndex;
	bool nanFlag = false;
	bool infFlag = false;
	bool inffFlag = false;
	bool minusFlag = false;
	int resI = INT_MAX;
	char resC;
	float resF;
	double resD;
	while(argv[1][++startIndex] == ' ')
		;
	if (argv[1][startIndex] == '\0')
		nanFlag = true;
	startIndex--;
	if (argv[1][startIndex + 1] == '-' || argv[1][startIndex + 1] == '+')
	{
		if (argv[1][startIndex + 1] == '-')
			minusFlag = true;
		startIndex++;
	}
	endIndex = startIndex;
	while (argv[1][++endIndex] != '\0')
	{
		if (argv[1][endIndex] >= '0' && argv[1][endIndex] <= '9')
			continue;
		else if (argv[1][endIndex] =='.')
		{
			if (count_dot != 0 || startIndex == (endIndex - 1))
			{
				nanFlag = true;
				break;
			}
			count_dot++;
			continue;
		}
		else if ((argv[1][endIndex] == 'f' ||argv[1][endIndex] == 'F') && argv[1][endIndex + 1] == '\0')
			break;
		else
		{
			if (argv[1][endIndex] == 'i' && argv[1][endIndex + 1] == 'n' && argv[1][endIndex + 2] == 'f')
			{
				if (argv[1][endIndex + 3] == '\0')
				{
					inffFlag = true;
					infFlag = true;
					break ;
				}
				if (argv[1][endIndex + 3] == 'f' && argv[1][endIndex + 4] == '\0')
				{
					inffFlag = true;
					break;
				}
			}
			nanFlag = true;
			break;
		}
	}
	if (!nanFlag)
	{
		if (infFlag)
			resI = static_cast<int>(DBL_MAX);
		else if (inffFlag)
			resI = static_cast<int>(FLT_MAX);
		else
		{
			try 
			{
				resI = std::stoi(input);
			}
			catch(const std::exception& e)
			{
				nanFlag = true;
			}
		}
	}
	cout <<"char: ";
	if (nanFlag || resI > 127 || resI < 0)
	{
		cout <<"impossible"<<endl;
	}
	else if (resI >= 32 && resI <= 126)
	{
		resC = static_cast<char>(resI);
		cout <<"'" << resC <<"'"<<endl;
	}
	else
	{
		cout <<"Non displayable"<<endl;
	}
	cout <<"int: ";
	if (nanFlag)
	{
		cout <<"impossible"<<endl;
	}
	else
	{
		cout<<resI<<endl;
	}
	cout <<"float: ";
	if (!nanFlag && !infFlag)
	{
		if (inffFlag)
		{
			if (minusFlag)
				resF = -FLT_MAX;
			else
				resF = FLT_MAX;
			cout<<resF;
			if (resF == static_cast<float>(resI))
				cout<<".0f"<<endl;
			else 
				cout<<"f"<<endl;
		}
		else
		{
			try
			{
				resF = std::stof(input);
				cout<<resF;
				if (resF == static_cast<float>(resI))
					cout<<".0f"<<endl;
				else 
					cout<<"f"<<endl;
			}
			catch(const std::exception& e)
			{
				cout<<"nanf"<<endl;
			}
		}
	}
	else
		cout<<"nanf"<<endl;
	cout <<"double: ";
	if (!nanFlag)
	{
		if (infFlag)
		{
			if (minusFlag)
				resD = -DBL_MAX;
			else
				resD = DBL_MAX;
			cout<<resD;
			if (resD == static_cast<double>(resI))
				cout<<".0"<<endl;
			else 
				cout<<endl;
		}
		else if (inffFlag)
		{
			if (minusFlag)
				resD = -static_cast<double>(FLT_MAX);
			else
				resD = static_cast<double>(FLT_MAX);
			cout<<resD;
			if (resD == static_cast<double>(resI))
				cout<<".0"<<endl;
			else 
				cout<<endl;
		}
		else{
			try
			{
				resD = std::stod(input);
				cout<<resD;
				if (resD == static_cast<double>(resI))
					cout<<".0"<<endl;
				else 
					cout<<endl;
			}
			catch(const std::exception& e)
			{
				cout<<"nan"<<endl;
			}
		}
	}
	else
		cout<<"nan"<<endl;
	return (0);
}