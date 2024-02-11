#include "std_lib_facilities.h"
#include "AnimationWindow.h"
#include "bouncingBall.h"

constexpr Point BOUNCE_WINDOW_TOP_LEFT{50, 50};
constexpr int BOUNCE_WINDOW_WIDTH{800}; 
constexpr int BOUNCE_WINDOW_HEIGHT{500};



void bouncingBall() {
    AnimationWindow window{BOUNCE_WINDOW_TOP_LEFT.x, BOUNCE_WINDOW_TOP_LEFT.y, 
                           BOUNCE_WINDOW_WIDTH, BOUNCE_WINDOW_HEIGHT, "Bouncing ball"};
    
    const int radius{30};
    int alpha{1};
    int velocity{2};
    Color colour_up{Color::blue};
    Color colour_down{Color::blue};
    int x{0};
    int y{360};
    int increment_x{0};
    int increment_y{0};
    int count_bounce_top{0};
    int count_bounce_bottom{0};
    int count_num_passes{0};

    // read from configuration file

    // initialise the run


    while (!window.should_close()) {
        // determine increments based on the velocity
        increment_x = velocity * cos(alpha);
        increment_y = velocity * sin(alpha);

        // movement i x-direction
        if ((increment_x + x) > window.width()) {
            // reached right side - wrap around to the leftmost
            x = 0;
            // increment counter which counts number of full left-to-right passes
            count_num_passes++;
            // alternate between slow and fast configuration every fifth pass
            if (count_num_passes % 5 == 0) {
                // change configuration
                // update both velcity and colors
    
            }
        } else {
            // moving rightwards
            x += increment_x;
        }

        // movement i y-direction
        if (((count_bounce_top + count_bounce_bottom) % 2) == 0) {
            // move upwards

            
        } else {
            // move downward


        }
    
        window.next_frame();
    }
}

map<int, Color> colorConverter{
    {1, Color::red},
    {2, Color::blue},
    {3, Color::dark_khaki},
    {4, Color::spring_green}
};

Config::Config(): colorUp{}, colorDown{}, velocity{}
{};

ostream& operator>>(istream& is, Config& cfg){
    string configFromFile;
    getline(is, configFromFile);
    //cfg.colorUp = configFromFile[0];
    configFromFile[0] >> cfg.colorUp;
    configFromFile[2] >> cfg.colorDown;
    configFromFile[4] >> cfg.velocity;
    //cfg.colorDown = configFromFile[2];
    //cfg.velocity = configFromFile[4]; 
    return;   //Må fikse overloaden
}


void Config::printValues(){
    cout << colorUp << endl;
    cout << colorDown << endl;
    cout << velocity << endl;
}
