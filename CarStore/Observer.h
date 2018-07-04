#pragma once
#pragma once
//#include"BaskeGUI.h"
#include<vector>
#include<algorithm>
class Observer {
public:
	virtual void update() = 0;
};

inline void notify(Observer* obs) {
	obs->update();
}
