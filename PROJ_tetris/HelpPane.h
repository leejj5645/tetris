#ifndef HELP_H
#define HELP_H
#include "Pane.h"


class HelpPane : public Pane {
public:
HelpPane(int x, int y, int w, int h);
void draw();
};

#endif
