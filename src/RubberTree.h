/**
 * @file RubberTree.h
 * @author Cailin Smith
 * @date 2025-10-09
 */

#ifndef RUBBERTREE_H
#define RUBBERTREE_H

#include "Indoor.h"
#include "MediumMoisture.h"
#include "Thinning.h"

class RubberTree : public Indoor {

public:
	RubberTree() : Indoor(300, new MediumMoisture(), new Thinning(), "Rubber Tree") {}
};

#endif
