class Map {
private:
	int width;
	int height;
	char* map;
public:
    //Constructor
	Map(int, int);
	
	//Copy constructor
	Map(const Map &);
	
	//Assignment operator
	Map& operator = (const Map &);

	//Operator constructor
	friend Map operator + (Map const &, Map const &);

	//Print table
	void print();

	~Map();
};