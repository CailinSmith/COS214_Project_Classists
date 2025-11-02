#ifndef PLANT_H
#define PLANT_H

#include "Product.h"
#include "WateringStrategy.h"
#include "PruningStrategy.h"
#include "SeedState.h"
#include <string>
#include <iostream>

using namespace std;

// Forward declaration to break circular include
class PlantState;

/**
 * @class Plant
 * @author Cailin Smith
 * @author Edwin Kusel
 * @brief Abstract base class representing a plant product in the nursery system.
 * Design Pattern: State, Strategy, Template Method
 * Participant: Context (State), Context (Strategy)
 * 
 * This class serves as the foundation for all plant types in the nursery management system.
 * It implements the State pattern to manage plant growth states (Seed, Growing, Mature, etc.),
 * and the Strategy pattern for watering and pruning behaviors. Plants track their health,
 * height, water level, and other vital statistics. The class provides both internal management
 * methods and customer-facing summary information.
 * 
 * @see Product
 * @see PlantState
 * @see WateringStrategy
 * @see PruningStrategy
 */
class Plant : public Product {
private:
	/**
	 * @brief Strategy for watering this plant
	 */
	WateringStrategy* wateringStrat;
	
	/**
	 * @brief Strategy for pruning this plant
	 */
	PruningStrategy* pruningStrat;
	
	/**
	 * @brief Current water level of the plant
	 */
	float waterLevel;
	
	/**
	 * @brief Current health status of the plant
	 */
	float health;
	
	/**
	 * @brief Current height of the plant in cm
	 */
	float height;
	
	/**
	 * @brief Current growth state of the plant
	 */
	PlantState* currentState;
	
	/**
	 * @brief Maximum height this plant can reach in cm
	 */
	int maxHeight;
	
	/**
	 * @brief Whether the plant has been pruned
	 */
	bool pruned;
	
	/**
	 * @brief Category of plant (Flower, Herb, Fruit, etc.)
	 */
	string category;
	
	/**
	 * @brief Total amount of water given to the plant
	 */
	int totalWater;
	
	/**
	 * @brief Name/variety of the plant
	 */
	string name;
	
	/**
	 * @brief Current cost of the plant
	 */
	float cost;
	
	/**
	 * @brief Season when this plant is available for sale
	 */
	string sellSeason;

public:
	/**
	 * @brief Constructs a Plant with specified characteristics.
	 * @param category The category of plant (Flower, Herb, Fruit, Vegetable, etc.).
	 * @param maxHeight The maximum height this plant can reach in cm.
	 * @param waterStrat Pointer to the watering strategy for this plant.
	 * @param pruneStrat Pointer to the pruning strategy for this plant.
	 * @param name The specific name/variety of this plant.
	 * @param sellSeason The season when this plant is typically available for sale.
	 */
	Plant(string category, int maxHeight, WateringStrategy* waterStrat, PruningStrategy* pruneStrat, string name, string sellSeason);

	/**
	 * @brief Virtual destructor for the Plant class.
	 */
	virtual ~Plant();

	/**
	 * @brief Waters the plant using its watering strategy.
	 */
	void water();

	/**
	 * @brief Prunes the plant using its pruning strategy.
	 */
	void prune();

	/**
	 * @brief Fertilises the plant to promote growth.
	 */
	void fertilise();

	/**
	 * @brief Generates a detailed summary of the plant's status.
	 * @return string A comprehensive summary including all plant statistics.
	 */
	string summary();

	/**
	 * @brief Generates a customer-facing summary of the plant.
	 * @return string A summary with information relevant to customers.
	 */
	string customerSummary();

	/**
	 * @brief Gets the current water level.
	 * @return float The current water level of the plant.
	 */
	float getWaterLevel();

	/**
	 * @brief Sets the water level of the plant.
	 * @param level The new water level to set.
	 */
	void setWaterLevel(float level);

	/**
	 * @brief Checks if the plant has been pruned.
	 * @return bool True if the plant has been pruned, false otherwise.
	 */
	bool getPruned();

	/**
	 * @brief Sets the pruned status of the plant.
	 * @param pruned The new pruned status.
	 */
	void setPruned(bool pruned);

	/**
	 * @brief Gets the plant category.
	 * @return string The category of this plant.
	 */
	string getCategory();

	/**
	 * @brief Gets the current height of the plant.
	 * @return float The current height in cm.
	 */
	float getHeight();

	/**
	 * @brief Sets the height of the plant.
	 * @param height The new height to set in cm.
	 */
	void setHeight(float height);

	/**
	 * @brief Gets the actual height of the plant.
	 * @return float The actual height of the plant in cm.
	 */
	float getActualHeight();

	/**
	 * @brief Gets the current state of the plant as a string.
	 * @return string The name of the current plant state.
	 */
	string getState();

	/**
	 * @brief Sets the plant's current state.
	 * @param state Pointer to the new PlantState.
	 */
	void setState(PlantState* state);

	/**
	 * @brief Sets the health of the plant.
	 * @param health The new health value to set.
	 */
	void setHealth(float health);

	/**
	 * @brief Gets the current health of the plant.
	 * @return float The current health value.
	 */
	float getHealth();

	/**
	 * @brief Sets the total water given to the plant.
	 * @param total The total water amount.
	 */
	void setTotalWater(int total);

	/**
	 * @brief Gets the total water given to the plant.
	 * @return int The total water amount.
	 */
	int getTotalWater();

	/**
	 * @brief Gets the maximum height the plant can reach.
	 * @return int The maximum height in cm.
	 */
	int getMaxHeight();

	/**
	 * @brief Gets a string description of the plant's care strategies.
	 * @return string Description of watering and pruning strategies.
	 */
	string getStrategies();

	/**
	 * @brief Gets the name of the plant.
	 * @return string The plant's name/variety.
	 */
	string getName();

	/**
	 * @brief Triggers a change in the plant's growth state.
	 */
    void changePlantState();

	/**
	 * @brief Updates the plant's health based on its current conditions.
	 */
	void changeHealth();

	/**
	 * @brief Gets the season when this plant is available for sale.
	 * @return string The sell season name.
	 */
	string getSellSeason();

	/**
	 * @brief Calculates the cost based on the current season.
	 * @param currSeason The current season affecting pricing.
	 * @return float The calculated cost of the plant.
	 */
	float calculateCost(string currSeason);
	
	/**
	 * @brief Calculates the base cost of the plant.
	 * @return float The base cost before seasonal or decorator adjustments.
	 */
	virtual float baseCost() = 0;
	
	/**
	 * @brief Calculates seasonal cost adjustments.
	 * @param curSeason The current season.
	 * @return float The seasonally adjusted cost.
	 */
	virtual float seasonCost(string curSeason);
	
	/**
	 * @brief Gets the current cost of the plant.
	 * @return float The current cost value.
	 */
	float getCost();
	
	/**
	 * @brief Gets the image path for this plant.
	 * @return string The path to the plant's image asset.
	 */
	virtual string getImagePath() = 0;

	/**
	 * @brief Gets the base plant (used by decorator pattern).
	 * @return Plant* Pointer to the base plant (returns this for non-decorated plants).
	 */
	virtual Plant* getBasePlant() {
		return this;
	}
};

#endif