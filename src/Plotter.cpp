#include "Plotter.h"
#include "strlib.h"
using namespace std;

void runPlotterScript(istream& input) {
    Vector<double> starter_spot = {0,0};
    bool upPen = true;
    PenStyle type = { 1, "black"};
    for (string line; getline(input, line); ) {
        Vector<string> info = stringSplit(line, ' ');
        if (info[0] == "PenColor"){
            type.color = info[1];
        }
        if (info[0] == "PenWidth"){
            type.width = stringToDouble(info[1]);
        }
        if (info[0] == "PenDown"){
            upPen = false;
        }
        if (info[0] == "PenUp"){
            upPen = true;
        }
        if (info[0] == "MoveAbs"){
            if (upPen == false){
                drawLine(starter_spot[0], starter_spot[1], stringToReal(info[1]), stringToReal(info[2]), type);
                starter_spot[0] = stringToReal(info[1]);
                starter_spot[1] = stringToReal(info[2]);
            } else {
                starter_spot[0] = stringToReal(info[1]);
                starter_spot[1] = stringToReal(info[2]);
            }
        }
        if (info[0] == "MoveRel"){
            if (upPen == false){
                drawLine(starter_spot[0], starter_spot[1], (stringToReal(info[1]) + starter_spot[0]), (stringToReal(info[2]) + starter_spot[1]), type);
                starter_spot[0] += stringToReal(info[1]);
                starter_spot[1] += stringToReal(info[2]);
            } else {
                starter_spot[0] += stringToReal(info[1]);
                starter_spot[1] += stringToReal(info[2]);
            }
        }
    }
}
