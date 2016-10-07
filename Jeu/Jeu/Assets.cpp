#include "Assets.h"




Assets::Assets()
{
	
}


Assets::~Assets()
{
}

void Assets::LoadPlayerFromFile(std::string file) {


	std::ifstream infile(file, ifstream::in);
	int number_of_lines = 0;
	std::string line;
	int SizeMaxOfLine = 0;
	int xsize;
	int ysize;
	string Type;
	CHAR_INFO ** buffer = nullptr;
	
	int lign = 0;


	while (infile.good())
	{


		getline(infile, line);
		if (number_of_lines == 0) {
			
			// convert first line to int
			xsize = atoi(line.c_str());
			
			++number_of_lines;
			continue;
		}
		else if (number_of_lines == 1) {
			ysize = atoi(line.c_str());
		
			++number_of_lines;
			buffer = new CHAR_INFO*[xsize];
			buffer[0] = new CHAR_INFO[xsize * ysize];

			for (int i = 1; i < xsize; i++)
			{
				buffer[i] = buffer[i - 1] + ysize;
			}
			continue;
		}
		else if (number_of_lines == 2) {
			Type = line;
			++number_of_lines;
			continue;
		}

		else

		{
			char a;

			for (int iterator = 0; iterator < ysize; iterator++) {
 				 a = line.at(iterator);
				buffer[lign][iterator].Char.AsciiChar = a;
				buffer[lign][iterator].Attributes = 0x0a;
			}
		
			
			++number_of_lines;
			++lign;
		}
	}


	
		_mRessources[Type] =  new Ressource(file, Type, buffer, xsize, ysize);



	
		delete[] buffer[0];
		delete[] buffer;







}


Ressource* Assets::GetAsset(string RessourceName) {
	return _mRessources[RessourceName];
}