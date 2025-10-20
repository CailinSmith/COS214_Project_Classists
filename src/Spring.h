#ifndef SPRING_H
#define SPRING_H

#include "SeasonState.h"
#include "Nursery.h"
#include "Summer.h"
#include "SummerFactory.h"

#include <string>
using namespace std;

class Spring : public SeasonState {
public:
	virtual void change(Nursery* nursery) override;
	virtual string print() override;
};

#endif