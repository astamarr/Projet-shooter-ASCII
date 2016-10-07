#pragma once
#include "stdafx.h"

#include "stdafx.h"
#include "Ressource.h"
#include <iostream>
#include <vector>
#include <map>
#include <Windows.h>
#include <stdlib.h>

#pragma warning (disable : 4996)
#pragma comment( lib, "winmm" )
#include <stdio.h>
#include <sstream>

#include <fstream>



class Assets
{
public:

	Ressource * _RPlayer;

	map<string, Ressource*> _mRessources;
	Assets();



	~Assets();
	
	void LoadPlayerFromFile(std::string file);
	Ressource* GetAsset(string RessourceName);

};

