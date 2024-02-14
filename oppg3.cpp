#include "oppg3.h"
#include "oppg1.h"


CourseCatalog::CourseCatalog(string savefile): courseCatalog{}, saveFile{savefile+".txt"}
{}

void CourseCatalog::addCourse(string code, string name){
    courseCatalog.insert({code, name});     //Returnerer true om emne blir lagdt til, returnerer false om ikke
}

void CourseCatalog::removeCourse(string code){
    auto a = courseCatalog.find(code);
    if(a == courseCatalog.end()){
        cout << "Could not find course in catalog" << endl;
        return;
    }
    courseCatalog.erase(code);
}

string CourseCatalog::getCourse(string code){
    auto a = courseCatalog.find(code);
    if(a == courseCatalog.end()){
        return "Could not find course in catalog";
    }
    string name = courseCatalog.at(code);
    return name;
}

void CourseCatalog::testClass(){
    addCourse("TDT4110", "Informasjonsteknologi grunnkurs");
    addCourse("TDT4102", "Prosedyre- og objektorientert programmering");
    addCourse("TMA4100", "Matematikk 1");
}

void CourseCatalog::saveData(){
    ofstream os{saveFile};
    for(const auto& m:courseCatalog){
        os << m.first << "|" << m.second << endl;
    }

}

void CourseCatalog::importData(){
    string splitSegment;
    vector<string> segList;
    string line;
    const filesystem::path sf{saveFile};
    
    ifstream file{};
    file.open(saveFile);
    if(!file){
        cout << "Could not find savefile" << endl;
        return;
    }
    file = sf;

    while(getline(file, line)){
        for(int i = 0; i < line.length(); i++){
            if(line[i] == '|'){
                segList.push_back(splitSegment);
                splitSegment.clear();
            }
            else{
                splitSegment += line[i];
            }
        }
        segList.push_back(splitSegment);
        splitSegment.clear();
    }
    for(int i = 0; i < segList.size(); i+=2){
        addCourse(segList[i], segList[i+1]);
    }
}




ostream& operator<<(ostream& os, const CourseCatalog& cc){
    for(const auto& m:cc.courseCatalog){
        os << "Code: " << m.first << ", Name: " << m.second << endl;
    }
    return os;
    
}
