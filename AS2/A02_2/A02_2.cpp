#include <iostream>
#include <cstring>
using namespace std;
class Map {
private:
	int width;
	int height;
	char* row;
public:
    //Constructor
	Map(int w, int h) {
		width = w;
		height = h;
		row = new char [h];
		for (int k = 0; k < h; k++) {
			row[k] = '*';
		}
		
	}; 

	//Print table
	void print() {
		for (int i = 0; i < height; i++) {
				cout << string(width,row[i])<<endl;
			
		}
	}

    //Destructor
    ~Map() {
		delete[] row;
	};
};
int main() {
	Map map(4, 5);
	map.print();

}