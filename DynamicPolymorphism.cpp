#include<iostream>
using namespace std;

class Car
{
    protected:
    string brand;
    string model;
    bool isEngineOn;
    int currentSpeed;

    public:
    Car(string brand, string model){
        this->brand = brand;
        this->model = model;
        this->isEngineOn = false;
        this->currentSpeed = 0;
    }

    void startEngine(){
        isEngineOn = true;
        cout<<brand<<" :Engine Started "<<endl;
    }

    void stopEngine(){
        isEngineOn = false;
        currentSpeed = 0;
        cout<<brand<<" :Engine Stopped"<<endl;
    }

    virtual void accelerate() = 0;

    virtual void brake() = 0;
};

class ManualCar: public Car{
    private:
    int currentGear;

    public:
    ManualCar(string brand, string model):Car(brand, model){
        this->currentGear = 0;
    }

    void shiftGear(int gear){
        currentGear = gear;
        cout<<brand<<": "<<model<<": Shifted Gear to : "<<currentGear<<endl;
    }

    void accelerate(){
        if(!isEngineOn){
            cout<<"Engine is off , can't accelerate"<<endl;
            return;
        }

        currentSpeed += 20;
        cout<<brand<<" cat is accelerating at :"<<currentSpeed<<endl;
    }

    void brake(){
        currentSpeed -= 20;
        cout<<brand<<" breaking , speed is now :"<<currentSpeed<<endl;
    }
};

class ElectricCar: public Car
{
      private:
      int batteryLevel;

      public:
      ElectricCar(string brand, string model):Car(brand, model){
        this->batteryLevel = 100;
      }

      void chargeBattery(){
        batteryLevel = 100;
        cout<<"Battery is fully charged "<<endl;
      }

      void accelerate(){
        if(!isEngineOn){
            cout<<"Sorry can't accelerate engine is not on :"<<endl;
            return;
        }
        if(batteryLevel<1){
            cout<<"Battery level is to low , can't accelerate :"<<endl;
            return;
        }

        currentSpeed += 20;
        cout<<brand<<" : The car is accelerating at the speed :"<<currentSpeed<<endl<<"Current battery level is :"<<batteryLevel<<endl;
      }

      void brake(){
        currentSpeed -= 15;
        if(currentSpeed<0) currentSpeed = 0;
        cout<<brand<<"Car is now accelerating at :"<<currentSpeed<<endl;
      }
};

int main(){

    Car* myManualCar = new ManualCar("Suzuki", "Suv");
    myManualCar->startEngine();
    myManualCar->accelerate();
    myManualCar->accelerate();
    myManualCar->brake();
    myManualCar->stopEngine();    

    cout<<endl<<endl<<endl<<"-------------------------------------"<<endl;

    Car* myElectricCar = new ElectricCar("Tesla", "Model 5");
    myElectricCar->startEngine();
    myElectricCar->accelerate();
    myElectricCar->accelerate();
    myElectricCar->brake();
    myElectricCar->stopEngine();


    delete myElectricCar;
    delete myManualCar;

    return 0;
}