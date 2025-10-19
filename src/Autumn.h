#ifndef AUTUMN_H
#define AUTUMN_H

#include "SeasonState.h"
#include "Nursery.h"
#include "Winter.h"
#include "WinterFactory.h"

#include <string>
using namespace std;

class Autumn : public SeasonState {
public:
	virtual void change(Nursery* nursery) override;
	virtual string print() override;
};

#endif