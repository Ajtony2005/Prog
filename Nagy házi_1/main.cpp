#include "graphics.hpp"
#include <vector>
#include <cmath>


const int XX=800;
const int YY=800;

struct tomb{

double x;
double y;

};


using namespace std;
using namespace genv;
int main()
{
    double c;
    gout.open(XX,YY);
    tomb pont;
    vector<tomb> pontok;
    for (int i=0; i<100; i++){
        pont.x=rand()%XX;
        pont.y=rand()%YY;
        pontok.push_back(pont);
    }
    gin.timer(40);
    for (tomb p : pontok){
    gout << move_to(p.x, p.y) << line(2, 2);
    }
    event ev;
    gout << refresh;
    int x, y;
    while(gin >> ev && ev.keycode!=key_escape)
    {
    if (ev.type == ev_mouse){

        x=ev.pos_x;
        y=ev.pos_y;

        }
        if (ev.keycode ==' '){
        for (int i=0; i<100; i++){
        pont.x=rand()%XX;
        pont.y=0;
        pontok.push_back(pont);
    }
        }
    if (ev.type == ev_timer){
            int i=0;
            gout << color (0, 0, 0);
        gout << move_to(0, 0) << box(XX, YY);
        gout << refresh;
        for (tomb & p : pontok){

                gout << color (200, 200, i*5);
                c=sqrt((x-p.x)*(x-p.x)+(y-p.y)*(y-p.y));
                p.x+=((x-p.x)/c*(c/40));
                p.y+=((y-p.y)/c*(c/40));
                gout << move_to(p.x, p.y) << line(2 , 2);
                i++;

    }
    gout << refresh;

    }




    }
return 0;
}
