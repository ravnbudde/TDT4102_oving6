#pragma once

void bouncingBall();

class Config
{
private:
    int colorUp;
    int colorDown;
    int velocity;

    


public:
    Config();

    void printValues();

    friend ostream& operator>>(istream& is, Config& cfg);

};



