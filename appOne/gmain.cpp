#include"libOne.h"
void gmain() {
    window(1000, 1000);
    angleMode(DEGREES);
    float ax, ay, angle = -15;
    float bx, by, bngle = 30;
    float incDec = 15;
    float dp, cp;
    float angleBitween;
    while (notQuit) {
        clear(0, 40, 0);
        mathAxis(1.5f, 200);

        if (isTrigger(KEY_A))angle += incDec;
        if (isTrigger(KEY_D))angle += -incDec;
        ax = cos(angle);
        ay = sin(angle);

        if (isTrigger(KEY_LEFT))bngle += incDec;
        if (isTrigger(KEY_RIGHT))bngle += -incDec;
        bx = cos(bngle);
        by = sin(bngle);
        if (isPress(MOUSE_LBUTTON)) {
            bx = mathMouseX;
            by = mathMouseY;
        }

        dp = ax * bx + ay * by;
        cp = ax * by - ay * bx;
        angleBitween = atan2(cp, dp);

        strokeWeight(10);
        stroke(255);
        mathArrow(0, 0, ax, ay);
        stroke(122);
        mathArrow(0, 0, bx, by);

        float cx = ax * dp;
        float cy = ay * dp;
        stroke(160, 200, 255);
        mathLine(0, 0, cx, cy);

        float dx = -ay * cp;
        float dy = ax * cp;
        stroke(255, 200, 200);
        mathLine(cx, cy, cx+dx, cy+dy);

        stroke(255, 255, 200);
        mathArc(angle, angleBitween, 0.1f);

        textSize(50);
        fill(160, 200, 255);
        text((let)"dot:   ax*bx+ay*by" + dp, 0, 50);
        fill(255, 200, 200);
        text((let)"cross: ax*by-ay*bx" + cp, 0, 100);
        fill(255, 255, 200);
        text((let)"atan2(cross,dot)="+round(angleBitween), 0, 150);

 
    }
}
