#pragma once

void bouncingBall();

class Config
{
private:


    


public:
    int colorUp;
    int colorDown;
    int velocity;
    Config();

    void printValues();
    

    friend istream& operator>>(istream& is, Config& cfg);

};




