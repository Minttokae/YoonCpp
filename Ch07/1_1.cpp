#include <iostream>
using namespace std;

class Car 
{
    int gasolineGauge;
public :
    Car(int gauge) : gasolineGauge(gauge) {}
    int GetGasGauge(){
        return gasolineGauge;
    }
};

class HybridCar : public Car 
{
    int electricGauge;
public:
    HybridCar(int gasgauge, int elecgauge) : Car(gasgauge), electricGauge(elecgauge) {}
    int GetElecGauge(){
        return electricGauge;
    }
};

class HybridWaterCar : public HybridCar 
{
    int waterGauge;
public:
    HybridWaterCar(int gasgauge, int elecgauge, int watergauge):
        HybridCar(gasgauge, elecgauge), waterGauge(watergauge) {}
    void ShowCurrentGauge()
    {
        cout << "Gas : " << GetGasGauge() << endl;
        cout << "Elec : " << GetElecGauge() << endl;
        cout << "Water : " << waterGauge << endl;
    }
};

int main() {
    HybridWaterCar H(100, 100, 100);
    H.ShowCurrentGauge();
    cout << H.GetGasGauge();
    return 0;
}
