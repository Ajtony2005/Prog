#include "graphics.hpp"
#include <vector>
#include <cmath>

using namespace std;
using namespace genv;

const int XX=800;
const int YY=800;

struct kigyo{
    int x;
    int y;
};

void palya(){
    gout << color (150, 25, 200);
    gout << move_to(0,0) << box(XX, 20);
    gout << move_to(0,0) << box(20, YY);
    gout << move_to(XX-20,0) << box(20, YY);
    gout << move_to(0,YY-20) << box(XX, 20);

}
void fej(int x, int y){
    gout << color (255, 0, 0);
    gout << move_to(x, y) << box(25, 25);
    gout << color(0, 0, 0);
    gout << move_to(x+5, y+5) << box(5,5);
    gout << move_to(x+15, y+5) << box(5,5);

}
void torol(){
    gout << color (0, 0, 0);
    gout << move_to(0 , 0) << box(XX, YY);
    gout << color (255, 255, 255);
    palya();
}

bool ellenorzes(int x, int y){
    if (x > XX-45 || x < 20) return 1;
    else {if (y > YY-45 || y < 20) return 1;
        else {return 0;}
    }
}
void vege(){
torol;
gout << font("LiberationSans-Regular.ttf",40);
gout << move_to(250, 350);
gout << color (150, 25, 200);
gout << text("GAME OVER!");
gout << refresh;
}





int main()
{

    gout.open(XX,YY);
    gin.timer(40);
    palya();
    kigyo mozog;
    mozog.x=400;
    mozog.y=400;
    fej(mozog.x, mozog.y);
    gout << refresh;
    event ev;
    int x=-5;
    int y=0;
    bool veg=0;
    while(gin >> ev && ev.keycode!=key_escape)
    {
        if (veg){
            vege();
        }else {
        if (ev.keycode==key_up){
            x=0;
            y=-5;
      }
        if (ev.keycode==key_down){
            x=0;
            y=5;
      }
        if (ev.keycode==key_left){
            x=-5;
            y=0;
      }
        if (ev.keycode==key_right){
            x=5;
            y=0;

      }

    mozog.x+=x;
    mozog.y+=y;
    torol();
    fej(mozog.x, mozog.y);}
    if (ellenorzes(mozog.x, mozog.y)) veg=1;
    gout << refresh;

    }
return 0;
}
