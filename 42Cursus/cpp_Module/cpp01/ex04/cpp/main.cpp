#include <iostream>
#include <fstream>

int main(int argc, char **argv)
{
	std::ofstream fout;
	std::ifstream fin;
	std::string outputFileName;
	std::string from;
	std::string to;
	std::string line;
	size_t lastPos;

	if (argc != 4)
	{
		std::cout<<"argument error!"<<std::endl;
		return (0);
	}
	outputFileName = argv[1];
	from = argv[2];
	to = argv[3];
	outputFileName.append(".replace");
	fin.open(argv[1]);
	if (!fin.is_open())
	{
		std::cout<<"input file open error!"<<std::endl;
		return (0);
	}
	fout.open(outputFileName, std::ios::trunc);
	if (!fout.is_open())
	{
		fin.close();
		std::cout<<"output file open error!"<<std::endl;
		return (0);
	}
	while (! fin.eof()){
		std::getline(fin, line);
		if ((! fin.eof()))
			line.append("\n");
		lastPos = 0;
		while(true)
		{
			lastPos = line.find(from, lastPos);
			if (lastPos == std::string::npos)
				break;
			line.erase(lastPos, from.length());
			line.insert(lastPos, to);
		}
		fout<<line;
	}
	fin.close();
	fout.close();
	return (0);
}