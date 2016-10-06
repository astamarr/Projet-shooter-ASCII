#pragma once
#include <iostream>;
#include <Windows.h>;
#include <stdlib.h>;
#include <io.h>
#include <map>
#include <fcntl.h>


using namespace std;
class Ressource
{


public:
	std::string _sname;
	std::string _stype;
	CHAR_INFO** _Buffer;
	int xBufferSize;
	int yBufferSize;



	Ressource(std::string name, std::string type, CHAR_INFO ** _Buffer,const int xSize,const int Ysize);
	~Ressource();
};

