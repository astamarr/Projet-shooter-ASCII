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

	for (int x = 0; x < xSize; x++) {

		for (int y = 0; y < Ysize; y++)
		{

			cout << _Buffer[x][y].Char.AsciiChar;
			cout << ResBuffer[x][y].Char.AsciiChar;
			
			_Buffer[x][y].Char.AsciiChar = ResBuffer[x][y].Char.AsciiChar;

		}
	}
	memcpy(_Buffer[0], ResBuffer[0], xBufferSize * yBufferSize * sizeof _Buffer[0][0]);

	for (int test = 0; test < 3; test++) {

		cout << _Buffer[test][1].Char.AsciiChar;
	}

	
		// ACCESS THE DATA WITH A SINGLE BLOCK :
		
	

}


Ressource::~Ressource()
{

	delete[] _Buffer[0];
	delete[] _Buffer;

}
