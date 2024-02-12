#include "std_lib_facilities.h"
#include "AnimationWindow.h"
#include "bouncingBall.h"
#include <fstream>
#include "oppg3.h"
#include "oppg1.h"

constexpr Point BOUNCE_WINDOW_TOP_LEFT{50, 50};
constexpr int BOUNCE_WINDOW_WIDTH{800}; 
constexpr int BOUNCE_WINDOW_HEIGHT{500};

map<int, Color> colorConverter{
    {1, Color::red},
    {2, Color::blue},
    {3, Color::dark_khaki},
    {4, Color::spring_green}
};

Config::Config(): colorUp{}, colorDown{}, velocity{}
{};

istream& operator>>(istream& is, Config& cfg){
    is >> cfg.colorUp;
    is >> cfg.colorDown;
    is >> cfg.velocity;
    return is;
}


void Config::printValues(){
    cout << colorUp << endl;
    cout << colorDown << endl;
    cout << velocity << endl;
}

void bouncingBall() {
    AnimationWindow window{BOUNCE_WINDOW_TOP_LEFT.x, BOUNCE_WINDOW_TOP_LEFT.y, 
                           BOUNCE_WINDOW_WIDTH, BOUNCE_WINDOW_HEIGHT, "Bouncing ball"};
    
    const int radius{30};
    int alpha{1};
    Color color{Color::cornflower_blue};
    int x{0};
    int y{360};
    int increment_x{0};
    int increment_y{0};
    int count_bounce_top{0};
    int count_bounce_bottom{0};
    int count_num_passes{0};

    // read from configuration file
    Config ball{};
    filesystem::path configFileFast{"fastConfig.txt"};
    filesystem::path configFileSlow{"slowConfig.txt"};
    ifstream cinp{};
    bool flip;
    
    if(testFile(configFileFast, cinp)){
        cinp >> ball;
    }
    else{
        cout << "noe feil med lesing av config-fil" << endl;
        return;
    }


    // initialise the run


    while (!window.should_close()) {
        // determine increments based on the velocity
        increment_x = ball.velocity * cos(alpha);
        increment_y = ball.velocity * sin(alpha);

        // movement i x-direction
        if ((increment_x + x-radius) > window.width()) {
            // reached right side - wrap around to the leftmost
            x = 0;
            // increment counter which counts number of full left-to-right passes
            count_num_passes++;
            // alternate between slow and fast configuration every fifth pass
            if (count_num_passes % 5 == 0) {
                // change configuration
                // update both velcity and colors
                if(flip){
                    flip = false;
                    if(testFile(configFileFast, cinp)){
                        cinp >> ball;
                    }
                    else{
                        cout << "noe feil med lesing av config-fil" << endl;
                        return;
                   }
                }
                else if(!flip){
                    flip = true;
                        if(testFile(configFileSlow, cinp)){
                            cinp >> ball;
                        }
                        else{
                            cout << "noe feil med lesing av config-fil" << endl;
                            return;
                        }
                }
                else{
                    cout << "mongo banan i linje 84" << endl;
                }
    
            }
        } else {
            // moving rightwards
            x += increment_x;
        }

        // movement i y-direction
        if (((count_bounce_top + count_bounce_bottom) % 2) == 0) {
            // move upwards
            y -= increment_y;
            if((y - increment_y-radius) < 0){
                count_bounce_top += 1;
                color = colorConverter.at(ball.colorDown);
            }
            
        } else {
            // move downward
            y += increment_y;
            if((y+increment_y+radius) > window.height()){
                count_bounce_bottom += 1;
                color = colorConverter.at(ball.colorUp);
            }

        }
    
        window.draw_circle({x, y}, radius, color, Color::black);

        window.next_frame();
    }
}


