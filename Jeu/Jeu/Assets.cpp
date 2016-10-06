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
	CHAR_INFO ** buffer = nullptr;
	
	int lign = 0;


	while (infile.good())
	{


		getline(infile, line);
		if (number_of_lines == 0) {
			
			// convert first line to string
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

		else
		{

			
			
			char a;

			for (int iterator = 0; iterator < ysize; iterator++) {
 				 a = line.at(iterator);
				buffer[lign][iterator].Char.AsciiChar = a;
				buffer[lign][iterator].Attributes = 0x0a;
				 
				CHAR_INFO c = buffer[lign][iterator];
				std::cout << buffer[lign][iterator].Char.AsciiChar;
			}
			cout << endl;
			
			++number_of_lines;
			++lign;

			


		}

	}
	
	for (int x = 0; x < xsize ; x++) {
		cout << endl;
		for (int y = 0; y < ysize; y++)
		{
			CHAR_INFO c = buffer[x][y];

			cout << buffer[x][y].Char.AsciiChar;
		

		}
	}
	//std::cout << buffer[2][2].Char.AsciiChar;
		Player = new Ressource(file, "joueur", buffer, xsize, ysize);

	



}
