#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

typedef struct{
    char* carModel;
    int hordePower;
    int torque;
    int isTuned;
} Car;

Car * newCar(char* carModel,int hordePower, int torque, int isTuned){
    Car * myCar = malloc(sizeof(Car));
    myCar->carModel = carModel;
    myCar->hordePower = hordePower;
    myCar->torque = torque;
    myCar->isTuned = isTuned; // 1 - true, 0 - false

    return myCar;
}

void printCar(Car * car){
    printf("carModel: %s\n",car->carModel);
    printf("hordePower: %d\n",car->hordePower);
    printf("torque: %d\n",car->torque);
    if (car->isTuned == 1){
        printf("car is tuned\n");
    } else{
        printf("car is NOT tuned\n");
    }
}

Car BestTorqueCar(Car* cars){
    int index = 0;
    for (int i = 0; i < 3; ++i) {
        if(cars->torque > index){
            index = i;
        }
    }
    return cars[index];
}

Car BestHPCar(Car* cars){
    int index = 0;
    for (int i = 0; i < 3; ++i) {
        if(cars->hordePower > index){
            index = i;
        }
    }
    return cars[index];
}

int main(int argc, const char * argv[])
{
    Car* allCars[3] = {
            {"alfa", 100, 30, 0}
    };,{"alfaClocked", 110, 32, 1},{"alfaClockedVeryMuch", 110, 39, 1},{"alfaClockedVeryMuch [OVER 9000!!]", 9000, 42, 1}

    Car bestTorqueCar = BestTorqueCar(*allCars);
    Car bestHPCar = BestHPCar(*allCars);

    printCar(allCars[0]);
    printCar(allCars[1]);

    printf("best TORQUE car:\n");
    printCar(&bestTorqueCar);
    printf("best HP car:\n");
    printCar(&bestHPCar);

    return 0;
}
