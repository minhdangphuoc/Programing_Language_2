#include <vector>
#include <string>
#include <fstream>

template <typename T>
std::vector<T> &operator+=(std::vector<T> &A, const std::vector<T> &B)
{
    A.reserve(A.size() + B.size());                // preallocate memory without erase original data
    A.insert(A.end(), B.begin(), B.end());         // add B;
    return A;                                        // here A could be named AB
}

class Logger
{
	std::vector<std::string> records;
public:
	int points, gems=0, moves=0, levels; //tracking

	//add new record
	void AddToRecord(std::string logData) {
		time_t now = time(0);
		struct tm tstruct;
		char buffer[80];
		tstruct = *localtime(&now);
		strftime(buffer, 80, "[%Y.%m.%d-%X]", &tstruct);
		records.push_back(std::string(buffer) + " " + logData);
	}

	Logger() {
		
	}

	void DeleteAllRecords(){
		records.clear();
	};

	std::vector<std::string> GetAllRecord() { return records; }
};

