#include "graphics.hpp"
#include <vector>
#include <cmath>
#include <cstdlib>

using namespace std;
using namespace genv;

const int XX=800;
const int YY=800;
int pont=0;

class Koordinata {
private:
    int x;
    int y;

public:
    Koordinata(int x, int y) : x(x), y(y) {}
    Koordinata() : x(0), y(0) {}
    int getX() const { return x; }
    int getY() const { return y; }
    void setX(int new_x) { x = new_x; }
    void setY(int new_y) { y = new_y; }
};

class Jatek {
private:
    vector<Koordinata> kigyo;
    Koordinata gyumolcs;

    void palya(){
        gout << color (150, 25, 200);
        gout << move_to(0,0) << box(XX, 20);
        gout << move_to(0,0) << box(20, YY);
        gout << move_to(XX-20,0) << box(20, YY);
        gout << move_to(0,YY-20) << box(XX, 20);
    }

    void kiiras(){
        gout << font("LiberationSans-Regular.ttf",30);
        gout << color(40 , 40, 200);
        string ponty=to_string(pont);
        gout << move_to(0 , 0) << text(ponty);
    }

    void fej(int x, int y){
        gout << color (255, 0, 0);
        gout << move_to(x, y) << box(25, 25);
        gout << color(0, 0, 0);
        gout << move_to(x+5, y+5) << box(5,5);
        gout << move_to(x+15, y+5) << box(5,5);
    }

    void farok(int x, int y){
        gout << color (255, 0, 0);
        gout << move_to(x, y) << box(25, 25);
        gout << color(0, 0, 0);
    }

    void barack(int x, int y) {
        gout << color(255, 204, 0);
        gout << move_to(x, y) << box(25, 25);
    }

    void torol(){
        gout << color (0, 0, 0);
        gout << move_to(0 , 0) << box(XX, YY);
        gout << color (255, 255, 255);
        palya();
        barack(gyumolcs.getX(), gyumolcs.getY());
        kiiras();
    }

    void barack_ell(int x, int y){
        if (x > gyumolcs.getX()-25 && x < gyumolcs.getX()+25 && y > gyumolcs.getY()-25 && y < gyumolcs.getY()+25){
            gyumolcs.setX((rand()%(XX-100))+50);
            gyumolcs.setY((rand()%(YY-100))+50);
            pont ++;
            kigyo.push_back(Koordinata(kigyo.back().getX(), kigyo.back().getY()));
        }
    }



    bool ellenorzes(int x, int y){
        return (x > XX-45 || x < 20 || y > YY-45 || y < 20);
    }

    void vege(){
        torol();
        gout << font("LiberationSans-Regular.ttf",40);
        gout << move_to(250, 350);
        gout << color (150, 25, 200);
        gout << text("GAME OVER!");
        gout << refresh;
    }




public:
    Jatek() {
        kigyo.push_back(Koordinata(400, 400));
        gyumolcs = Koordinata(200, 100);
    }

    void futtat() {
        gout.open(XX,YY);
        gin.timer(40);
        palya();
        bool kezd=1;
        fej(kigyo[0].getX(), kigyo[0].getY());
        gout << refresh;
        event ev;
        int x=-5;
        int y=0;
        bool veg=0;
        while(gin >> ev && ev.keycode!=key_escape) {
            if (kezd) {
            gout << font("LiberationSans-Regular.ttf",30);
            gout << move_to(250, 350);
            gout << color (150, 25, 200);
            gout << text("Kezdéshez nyomd meg az Entert!");
            gout << refresh;
                if (ev.keycode==key_enter){
                    kezd=0;
                }
            } else {
            if (veg){
                vege();
            } else {
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

            int vx = kigyo[0].getX();
            int vy = kigyo[0].getY();
            int prevX = vx;
            int prevY = vy;
            kigyo[0].setX(vx + x);
            kigyo[0].setY(vy + y);
            torol();
            for (size_t i = 0; i < kigyo.size(); i++) {
                if (i == 0) {
                    fej(kigyo[i].getX(), kigyo[i].getY());
                } else {
                    prevX = kigyo[i].getX();
                    prevY = kigyo[i].getY();
                    farok(vx, vy);
                    vx=prevX;
                    vy=prevY;
    }
}


                if (ellenorzes(kigyo[0].getX(), kigyo[0].getY())) veg=1;
                gout << refresh;
                barack_ell(kigyo[0].getX(), kigyo[0].getY());
            }
        }
    }
    }
};

int main()
{
    Jatek jatek;
    jatek.futtat();
    return 0;
}
