#include "../hpp/Span.hpp"

Span::Span():maxSize(0), data(0)
{
}
Span::Span(unsigned int n):maxSize(n), data(0)
{
}
Span::Span(const Span &span):maxSize(span.maxSize), data(0)
{
	data.resize(maxSize);
	std::copy(span.data.begin(), span.data.end(), data.begin());
}
Span &Span::operator=(const Span &span)
{
	if (this != &span)
	{
		maxSize = span.maxSize;
		data.clear();
		data.resize(maxSize);
		std::copy(span.data.begin(), span.data.end(), data.begin());
	}
	return (*this);
}

Span::~Span()
{
}

Span &Span::addNumber(int newOne)
{
	if (data.size() >= maxSize)
		throw Span::SpanFullException();
	data.push_back(newOne);
	return (*this);
}

Span &Span::addNumber(const vector<int>::iterator &begin,const  vector<int>::iterator &end)
{
	vector<int>::iterator &beginC = const_cast<vector<int>::iterator &>(begin);
	while (beginC != end)
	{
		addNumber(*beginC);
		beginC++;
	}
	return (*this);
}

unsigned int Span::shortestSpan()
{
	if (data.size() < 2)
		throw Span::SpanException();
	unsigned int minimum = UINT_MAX;
	unsigned int idx = 0;
	unsigned int cap = data.size();
	int prev;
	std::sort(data.begin(), data.end());
	prev = data.at(0);
	while(++idx < cap)
	{
		if (minimum > (unsigned)(data.at(idx) - prev))
			minimum = (data.at(idx) - prev);
		prev = data.at(idx);
	}
	return minimum;
}
unsigned int Span::longestSpan()
{
	if (data.size() < 2)
		throw Span::SpanException();
	return (*std::max_element(data.begin(), data.end()) - *std::min_element(data.begin(), data.end()));
}

const char *Span::SpanFullException::what() const throw()
{
	return "Span: SpanFullException";
}
const char *Span::SpanException::what() const throw()
{
	return "Span: SpanException";
}

void Span::printAll()
{
	vector<int>::iterator it = data.begin();
	cout<<"{";
	while(it != data.end())
	{
		cout<<*it<<", ";
		it++;
	}
	cout<<"}"<<endl;
}