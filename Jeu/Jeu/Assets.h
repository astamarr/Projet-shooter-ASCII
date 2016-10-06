#pragma once
#include "stdafx.h"
#include "Buffer.h"
#include "stdafx.h"
#include "Ressource.h"
#include <iostream>
#include <Windows.h>
#include <stdlib.h>
#include "Buffer.h"
#pragma warning (disable : 4996)
#pragma comment( lib, "winmm" )
#include <stdio.h>
#include <sstream>

#include <fstream>



class Assets
{
public:

	Ressource * Player;

	Assets();

	~Assets();
	void LoadPlayerFromFile(std::string file);

};

