#include "../hpp/RPN.hpp"

RPN::RPN():result(0.0)
{
	cout<<"Constructor RPN"<<endl;
}

RPN::RPN(const RPN &rpn):data(rpn.data)
{
	result = rpn.result;
	cout<<"Copy constructor RPN"<<endl;
}

RPN::RPN(const string argv)
{
	cout<<"Argument constructor RPN"<<endl;
	string tmpStr(argv);
	string errStr("consecutive spaces are not allowed");
	while(true)
	{
		size_t pos = tmpStr.rfind(" ", string::npos);
		if (pos == string::npos)
			break;
		if (pos+1 == tmpStr.length())
			throw ErrException();
		string tok = tmpStr.substr(pos + 1);
		data.push(tok);
		tmpStr.erase(pos, string::npos);
	}
	string tok = tmpStr.substr(0);
	data.push(tok);
}

RPN& RPN::operator=(const RPN &rpn)
{
	cout<<"Copy assignment operator RPN"<<endl;
	data = rpn.data;
	result = rpn.result;
	return (*this);
}

RPN::~RPN()
{
	cout<<"Destructor RPN"<<endl;
}

float RPN::calculate()
{
	stack<float> operands;
	while(!data.empty())
	{
		if(data.top() == "+")
		{
			if (operands.size() < 2)
				throw ErrException();
			int a = operands.top();
			operands.pop();
			int b = operands.top();
			operands.pop();
			operands.push(b+a);
			data.pop();
		}else if(data.top() == "-")
		{
			if (operands.size() < 2)
				throw ErrException();
			int a = operands.top();
			operands.pop();
			int b = operands.top();
			operands.pop();
			operands.push(b-a);
			data.pop();
		}else if(data.top() == "*")
		{
			if (operands.size() < 2)
				throw ErrException();
			int a = operands.top();
			operands.pop();
			int b = operands.top();
			operands.pop();
			operands.push(b*a);
			data.pop();
		}else if(data.top() == "/")
		{
			if (operands.size() < 2)
				throw ErrException();
			int a = operands.top();
			operands.pop();
			int b = operands.top();
			operands.pop();
			if (a == 0.0)
				throw ErrException();
			operands.push(b/a);
			data.pop();
		}else {
			validateNumber(data.top());
			operands.push(std::atof(data.top().c_str()));
			data.pop();
		}
	}
	if (operands.size() >= 2)
		throw ErrException();
	float result = operands.top();
	operands.pop();
	return result;
}

void RPN::validateNumber(string num)
{
	bool first = true;
	bool firstPoint = true;
	size_t it = 0;
	const char *str(num.c_str());
	while(it < num.size())
	{
		if (first && str[it] == '-')
		{
			first = false;
			it++;
			continue;
		}
		first = false;
		if (str[it] >= '0' || str[it] <= '9')
		{
			it++;
			continue;
		}
		if (firstPoint && str[it] <= '.' )
		{
			firstPoint = false;
			it++;
			continue;
		}
		throw ErrException();
	}
}

const char *RPN::ErrException::what() const throw()
{
	return "error";
}