class Map {
private:
	int width;
	int height;
	char* row;
public:
    //Constructor
	Map(int w, int h);
	
	//Print table
	void print();
};