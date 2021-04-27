#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{ 
    std::string line;
    std::vector<std::string> old_records;
		std::ifstream myRecords ("records.txt");
		if (myRecords.is_open())
		{
			while (std::getline (myRecords,line) )
			{
				old_records.push_back(line);
				std::cout<<line<<std::endl;
			}
			myRecords.close();
		}
 return 0;
}