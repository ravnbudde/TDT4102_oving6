#include "std_lib_facilities.h"
#include <fstream>
#pragma once

bool isTxtFile(string string);

void inputToFile();

void addLineNum();

bool testFile(filesystem::path fileName, ifstream& is);
