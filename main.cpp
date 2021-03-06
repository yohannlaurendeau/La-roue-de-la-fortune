#include <X11/Xlib.h>
#include <iostream>
#include <stdio.h>
#include "player.h"
#include "roue.h"

/* déclaration des variables */

Display *display;
Window window;
int screen;
XEvent event;
XEvent event2;
Window child_window;
Window child_window2;

int b_x, b_y;
unsigned int b_width, b_height;
Window rootWin;
Colormap colormap;
XColor button_color;
XColor lightgray, darkgray;
XGCValues gcv_lightgray, gcv_darkgray;
GC gc_lightgray, gc_darkgray;
unsigned int border_width;
unsigned int depth;
char * nickname;
int button_cpt;

int main(int argc, const char * argv[]){

    display = XOpenDisplay(NULL);

    if (display == NULL) {
        fprintf(stderr,"Cannot open the display\n");
        return 1;
    }

    screen = DefaultScreen(display);
    button_cpt = 0;
    nickname = new char[20];
    std::cout << "Entrez votre pseudo du Joueur 1 svp : ";
    std::cin >> nickname;
    Player player(nickname,1);
    Roue wheel(3);
    Case setcases[5];
    setcases[0].setValues("Banqueroute","set gains");
    setcases[1].setValues("Passe","passe tour");
    setcases[2].setValues("1000","raise gains");
    setcases[3].setValues("10","raise gains");
    setcases[4].setValues("100","raise gains");
    wheel.setCases(setcases);

    /* Main Window */

    window = XCreateSimpleWindow(display, RootWindow(display, screen), 200, 200, 500, 300, 1, BlackPixel(display, screen), WhitePixel(display, screen));
    XSelectInput(display, window, ExposureMask | KeyPressMask);
    XMapWindow(display, window);

    /* Second Window */

    colormap = DefaultColormap(display, screen);
    XParseColor(display,colormap,"rgb:cc/cc/cc", &button_color);
    XAllocColor(display, colormap, &button_color);

    XParseColor(display, colormap, "rgb:ee/ee/ee", &lightgray);
    XAllocColor(display, colormap, &lightgray);
    gcv_lightgray.foreground = lightgray.pixel;
    gcv_lightgray.background = button_color.pixel;
    gc_lightgray = XCreateGC(display, RootWindow(display, screen), GCForeground | GCBackground, &gcv_lightgray);



    XParseColor(display, colormap, "rgb:88/88/88", &darkgray);
    XAllocColor(display, colormap, &darkgray);
    gcv_darkgray.foreground = darkgray.pixel;
    gcv_darkgray.background = button_color.pixel;
    gc_darkgray = XCreateGC(display, RootWindow(display, screen), GCForeground | GCBackground, &gcv_darkgray);

    child_window = XCreateSimpleWindow(display, window, 20, 20, 200, 100, 1, BlackPixel(display, screen), button_color.pixel);

    XSelectInput(display, child_window, ExposureMask | KeyPressMask | ButtonPressMask | ButtonReleaseMask);
    XMapWindow(display, child_window);


    XGetGeometry(display, child_window, &rootWin, &b_x, &b_y, &b_width, &b_height, &border_width, &depth);


    /* Déroulement de la partie */


    while (button_cpt <= 10) {
        XNextEvent(display, &event);
        switch (event.type)
        {
        case Expose:
            XClearWindow(display,child_window);
            XDrawLine(display, child_window, gc_lightgray, 0, 0, b_width - 1, 0);
            XDrawLine(display, child_window, gc_lightgray, 0, 0, 0, b_height - 1);
            XDrawLine(display, child_window, gc_darkgray, b_width - 1, 0, b_width-1, b_height - 1);
            XDrawLine(display, child_window, gc_darkgray, 0, b_height - 1, b_width-1, b_height - 1);
            XDrawString(display, child_window, DefaultGC(display,screen), b_width / 4, b_height / 2, "Tourner la roue", 15);
            break;
        case ButtonPress:
            if (event.xbutton.button = 1) {
                button_cpt++;
                const char * caseRolled = wheel.tournerRoue();
                if (caseRolled == "Banqueroute") {
                    player.setGains();
                    fprintf(stdout, "Quel dommage ! Vous etes tombé sur la case %s ! \n  Vous perdez tout vos gains !\n", caseRolled);
                }else{
                    player.addGains(std::atoi(caseRolled));
                }
                XClearWindow(display,child_window);
                XDrawLine(display, child_window, gc_darkgray, 0, 0, b_width - 1, 0);
                XDrawLine(display, child_window, gc_darkgray, 0, 0, 0, b_height - 1);
                XDrawLine(display, child_window, gc_lightgray, b_width - 1, 0, b_width-1, b_height - 1);
                XDrawLine(display, child_window, gc_lightgray, 0, b_height - 1, b_width-1, b_height - 1);
                XDrawString(display, child_window, DefaultGC(display,screen), b_width / 4, b_height / 2, "La roue a ete tournee", 21);
            }

            break;
        case ButtonRelease:
            if (event.xbutton.button = 1) {
                XClearWindow(display,child_window);
                XDrawLine(display, child_window, gc_lightgray, 0, 0, b_width - 1, 0);
                XDrawLine(display, child_window, gc_lightgray, 0, 0, 0, b_height - 1);
                XDrawLine(display, child_window, gc_darkgray, b_width - 1, 0, b_width-1, b_height - 1);
                XDrawLine(display, child_window, gc_darkgray, 0, b_height - 1, b_width-1, b_height - 1);
                XDrawString(display, child_window, DefaultGC(display,screen), b_width / 4, b_height / 2, "Tourner la roue", 15);
            }
            break;
        default:
            break;
        }

    }

    std::cout << "La partie est terminée !" << std::endl;
    fprintf(stdout,"%s a accumulé %d crédits, bravo !\n",player.GetNickname(),player.getGains());


    return 0;
}
