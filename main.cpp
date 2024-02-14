#include "std_lib_facilities.h"
#include "oppg1.h"
#include "oppg3.h"
#include "bouncingBall.h"



int main() {
    //Oppg1 
    //inputToFile();
    //addLineNum();


    // //Oppg3a
    // CourseCatalog test{};

    // test.testClass();
    // cout << test;
    // test.addCourse("TDT4102", "C++");
    // cout << "_____________" << endl;
    // cout << test;

    // //Ingenting skjer om man legget til en ny med insert, men om man bruker [] blir verdien til koden oppdatert
    // //Bedre metode er kanskje å skrive ut at koden allerede finnes, og heller
    // //legge til en funksjon updatecoursename og bruke if(!course.insert(code, name).second){course[code] = name}
    
    // //oppgave 3f
    //CourseCatalog test2{"oppg3f"};
    //test2.testClass();
    //test2.saveData();
    //test2.importData();
    //test2.addCourse("IMAT2012", "Matematikk for ingeniørfag 2");
    //test2.addCourse("IFYT1002", "Fysikk");
    //test2.addCourse("TMA4245", "Statistikk");
    //test2.saveData();
    //cout << test2 << endl;



    CourseCatalog test{"oppg3f"};

    test.importData();

    test.removeCourse("TDT4012");

    cout << endl << test << endl;

    test.removeCourse("TDT4102");

    cout << test;



    //bouncingBall();





    return 0;
}

