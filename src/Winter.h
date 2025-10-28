#ifndef WINTER_H
#define WINTER_H

#include "SeasonState.h"
#include "Nursery.h"
#include "Spring.h"
#include "SpringFactory.h"

#include <string>
using namespace std;

class Winter : public SeasonState {
public:
	virtual void change(Nursery* nursery) override;
	virtual string print() override;
};

#endif
