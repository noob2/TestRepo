#include <stdio.h>
#include <malloc.h>
#include <string.h>

#define numberOfCars 4

//trqbva da q napravqq s make file

typedef struct {
    char *carModel;
    int hordePower;
    int torque;
    int isTuned;
} Car;

Car *newCar(char *carModel, int hordePower, int torque, int isTuned) {
    Car *myCar = malloc(sizeof(Car));
    myCar->carModel = carModel;
    myCar->hordePower = hordePower;
    myCar->torque = torque;
    myCar->isTuned = isTuned; // 1 - true, 0 - false

    return myCar;
}

void printCar(Car *car) {
    printf("carModel: %s\n", car->carModel);
    printf("hordePower: %d\n", car->hordePower);
    printf("torque: %d\n", car->torque);
    if (car->isTuned == 1) {
        printf("car is tuned\n");
    } else {
        printf("car is NOT tuned\n");
    }
}

Car BestTorqueCar(Car *cars) {
    int index = 0;
    for (int i = 0; i < numberOfCars; ++i) {
        if (cars[i].torque > index) {
            index = i;
        }
    }
    return cars[index];
}

Car CarByName(Car *cars, char *carName) {
    int answer;
    for (int i = 0; i < numberOfCars; ++i) {
        answer = strcmp(cars[i].carModel, carName);
        if (answer == 0) {
            return cars[i];
        }
    }
    return *newCar("null", -1, -1, -1);
}

Car BestHPCar(Car *cars) {
    int index = 0;
    for (int i = 0; i < numberOfCars; ++i) {
        if (cars[i].hordePower > index) {
            index = i;
        }
    }
    return cars[index];
}

int main(int argc, const char *argv[]) {


    Car allCars[numberOfCars] = {{"alfa",                              100,  30, 0},
                                 {"alfaClocked",                       110,  32, 1},
                                 {"alfaClockedVeryMuch",               110,  39, 1},
                                 {"alfaClockedVeryMuch [OVER 9000!!]", 9000, 1,  1}};

    Car bestTorqueCar = BestTorqueCar(allCars);
    Car bestHPCar = BestHPCar(allCars);

    char carName = {0};
    scanf("%s", &carName);
    Car carFound = CarByName(allCars, &carName);

    printf("best TORQUE car:\n");
    printCar(&bestTorqueCar);
    printf("best HP car:\n");
    printCar(&bestHPCar);
    printf("car by name:\n");
    printCar(&carFound);

    return 0;
}
