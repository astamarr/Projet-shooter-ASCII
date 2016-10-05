#include "Ressource.h"



Ressource::Ressource(string name, string type, CHAR_INFO ** ResBuffer,const int xSize, const int Ysize)
{
	_sname = name;
	_stype = type;
	xBufferSize = xSize;
	yBufferSize = Ysize;
	_Buffer = new CHAR_INFO*[xBufferSize];
	_Buffer[0] = new CHAR_INFO[xBufferSize * yBufferSize];
	for (int i = 1; i < xSize; i++)
	{
		_Buffer[i] = _Buffer[i - 1] + yBufferSize;
	}

	
		// ACCESS THE DATA WITH A SINGLE BLOCK :
		// memcpy(newGrid[0], oldGrid[0], height * width * sizeof newGrid[0][0]);
	

}


Ressource::~Ressource()
{

	delete[] _Buffer[0];
	delete[] _Buffer;

}
