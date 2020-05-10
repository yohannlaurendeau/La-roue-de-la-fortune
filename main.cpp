#include <X11/Xlib.h>
#include <iostream>
#include <stdio.h>


Display *display;
Window window;
int screen;
XEvent event;
Window child_window;

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

int main(int argc, const char * argv[]){    
    
    display = XOpenDisplay(NULL);

    if (display == NULL) {
        fprintf(stderr,"Cannot open the display\n");
        return 1;
    }
    
    screen = DefaultScreen(display);
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

    while (True) {
        XNextEvent(display, &event);
        switch (event.type)
        {
        case Expose:
            XDrawLine(display, child_window, gc_lightgray, 0, 0, b_width - 1, 0);
            XDrawLine(display, child_window, gc_lightgray, 0, 0, 0, b_height - 1);
            XDrawLine(display, child_window, gc_darkgray, b_width - 1, 0, b_width-1, b_height - 1);
            XDrawLine(display, child_window, gc_darkgray, 0, b_height - 1, b_width-1, b_height - 1);
            break;
        case ButtonPress:
            if (event.xbutton.button = 1) {
                XDrawLine(display, child_window, gc_darkgray, 0, 0, b_width - 1, 0);
                XDrawLine(display, child_window, gc_darkgray, 0, 0, 0, b_height - 1);
                XDrawLine(display, child_window, gc_lightgray, b_width - 1, 0, b_width-1, b_height - 1);
                XDrawLine(display, child_window, gc_lightgray, 0, b_height - 1, b_width-1, b_height - 1);
            }
            
            break;
        case ButtonRelease:
            if (event.xbutton.button = 1) {
                XDrawLine(display, child_window, gc_lightgray, 0, 0, b_width - 1, 0);
                XDrawLine(display, child_window, gc_lightgray, 0, 0, 0, b_height - 1);
                XDrawLine(display, child_window, gc_darkgray, b_width - 1, 0, b_width-1, b_height - 1);
                XDrawLine(display, child_window, gc_darkgray, 0, b_height - 1, b_width-1, b_height - 1);
            }
            break;
        default:
            break;
        }
        
    }
    

    return 0;
}