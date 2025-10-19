#ifndef SUMMER_H
#define SUMMER_H

#include "SeasonState.h"
#include "Nursery.h"
#include "Autumn.h"
#include "AutumnFactory.h"

#include <string>
using namespace std;

class Summer : public SeasonState {
public:
	virtual void change(Nursery* nursery) override;
	virtual string print() override;
};

#endif