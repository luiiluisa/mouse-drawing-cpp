#include <iostream>
#include <graphics.h>
#include <windows.h>

using namespace std;

int culoare = RED;

void desenCerc()
{
    POINT mouse;
    GetCursorPos(&mouse);

    setcolor(culoare);
    setfillstyle(SOLID_FILL, culoare);

    fillellipse(mouse.x, mouse.y, 20, 20);
}

void desenDreptunghi()
{
    POINT mouse;
    GetCursorPos(&mouse);

    setcolor(culoare);
    setfillstyle(SOLID_FILL, culoare);

    bar(mouse.x, mouse.y, mouse.x + 40, mouse.y + 40);
}

void sterge()
{
    POINT mouse;
    GetCursorPos(&mouse);

    setcolor(BLACK);
    setfillstyle(SOLID_FILL, BLACK);

    fillellipse(mouse.x, mouse.y, 50, 50);
}

void schimbaCuloare()
{
    if(culoare==RED)
        culoare=WHITE;
    else if(culoare==WHITE)
        culoare=BLUE;
    else
        culoare=RED;
}

void meniu(int mod)
{
    setcolor(WHITE);
    settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);

    outtextxy(20,20,"CONTROLS");
    outtextxy(20,60,"Left Click  - draw");
    outtextxy(20,100,"Right Click - erase");
    outtextxy(20,140,"UP arrow    - clear screen");
    outtextxy(20,180,"RIGHT arrow - change shape");
    outtextxy(20,220,"LEFT arrow  - change color");
    outtextxy(20,260,"SPACE       - exit");

    settextstyle(DEFAULT_FONT, HORIZ_DIR, 3);

    if(culoare==RED)
        outtextxy(20,320,"Color: RED");
    if(culoare==WHITE)
        outtextxy(20,320,"Color: WHITE");
    if(culoare==BLUE)
        outtextxy(20,320,"Color: BLUE");

    if(mod==1)
        outtextxy(20,380,"Shape: CIRCLE");

    if(mod==2)
        outtextxy(20,380,"Shape: SQUARE");
}

int main()
{
    int x = GetSystemMetrics(SM_CXSCREEN);
    int y = GetSystemMetrics(SM_CYSCREEN);

    initwindow(x,y,"Drawing App",-3,-3);

    int gameover = 1;
    int mod = 1;

    while(gameover)
    {
        meniu(mod);

        if(GetAsyncKeyState(VK_LBUTTON))
        {
            if(mod==1)
                desenCerc();
            else
                desenDreptunghi();
        }

        if(GetAsyncKeyState(VK_RBUTTON))
            sterge();

        if(GetAsyncKeyState(VK_UP))
            cleardevice();

        if(GetAsyncKeyState(VK_RIGHT))
        {
            if(mod==1)
                mod=2;
            else
                mod=1;

            delay(200);
        }

        if(GetAsyncKeyState(VK_LEFT))
        {
            schimbaCuloare();
            delay(200);
        }

        if(GetAsyncKeyState(VK_SPACE))
            gameover=0;

        delay(1);
    }

    getch();
    closegraph();
}
