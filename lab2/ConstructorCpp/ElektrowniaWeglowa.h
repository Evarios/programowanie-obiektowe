#include "logger.h"
#include "stopper.h"
class ElektrowniaWeglowa: Logger, public Stopper{

private:
    int *maxCoalAmmount;
    int *coalAmmountInStore;
    float *efficiency;
    int *workersNumber;
    int *power; //własna własność, moc elektrowni w megawatach (MW)

public:
    ElektrowniaWeglowa();
    ElektrowniaWeglowa(ElektrowniaWeglowa &);
    ElektrowniaWeglowa(ElektrowniaWeglowa &&);
    ElektrowniaWeglowa(int);
    ~ElektrowniaWeglowa();
    void setMaxCoalAmmount(int);
    int readMaxCoalAmmount();
    int addCoalToStore(int);
    int burnCoal();
    int readCoalInStore();
    void setEfficiency(float);
    float readEfficiency();
    void setWorkersNumber(int);
    int retireWorkers(int);
    int readWorkersNumber();
    void setPower(int); //metoda do własnej własności
    int readPower(); //metoda do własnej własności
};