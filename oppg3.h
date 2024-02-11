#include "std_lib_facilities.h"
#include <map>
#include <fstream>
#pragma once


class CourseCatalog
{
private:
    map<string, string> courseCatalog;
    string saveFile;


public:
    CourseCatalog(string savefile);
    void addCourse(string code, string name);
    void removeCourse(string code);
    string getCourse(string code);
    friend ostream& operator<<(ostream& os, const CourseCatalog& cc);
    void testClass();
    void saveData();
    void importData();

};
