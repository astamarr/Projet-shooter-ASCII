#pragma once
#include <iostream>;
#include <Windows.h>;
#include <stdlib.h>;
#include <io.h>
#include <map>
#include <fcntl.h>
#include "Buffer.h";


class Ressource
{


public:
	string _sname;
	string _stype;
	CHAR_INFO** _Buffer;
	int xBufferSize;
	int yBufferSize;



	Ressource(string name, string type, CHAR_INFO ** _Buffer,const int xSize,const int Ysize);
	~Ressource();
};

