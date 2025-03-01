#include <iostream>
#include <cstring>
using namespace std;

namespace RISK_LEVEL
{
       enum {RISK_A = 1, RISK_B, RISK_C};
};

class Employee {
	char name[100];
public:
	Employee(const char* name)
	{
		strcpy(this->name, name);
	}

	void ShownameInfo() const
	{
		cout << name << endl;
	}
	virtual void ShowSalaryInfo() const = 0;
	virtual int GetPay() const = 0;
};


class PermanentWorker : public Employee {
	int salary;
public:
	PermanentWorker(const char* name, int money) : Employee(name), salary(money) {}

	void ShowSalaryInfo() const
	{
		cout << GetPay() << endl;
	}

	int GetPay() const
	{
		return salary;
	}
};


class SalesWorker : public PermanentWorker
{
	int salesRes;
	double bonusRatio;
public:
	SalesWorker(const char* name, int money, double bonus) : PermanentWorker(name, money), bonusRatio(bonus) {}

	void AddSales(int n)
	{
		salesRes += n;
	}

    int GetPay() const
	{
		return PermanentWorker::GetPay() + (int)(salesRes * bonusRatio);
	}

	void ShowSalaryInfo() const
	{
		cout << GetPay() << endl;
	}	

    int ShowSalesInfo() const
    {
        return salesRes; 
    }
};


class ForeignSalesWorker : public SalesWorker
{
    int Risklevel;

public:
    ForeignSalesWorker(const char* name, int money, double bonus, int risklv) :
        SalesWorker(name, money, bonus), Risklevel(risklv) {}

    double RiskBonus() const
    {
        double Riskbonus;
        
        switch (Risklevel) 
        {
            case RISK_LEVEL::RISK_A : Riskbonus = 0.3; break;
            case RISK_LEVEL::RISK_B : Riskbonus = 0.2; break;
            case RISK_LEVEL::RISK_C : Riskbonus = 0.1; break;
        }

        return Riskbonus;
    }

    int GetPay() const 
    {
        double Riskbonus;
        
        switch (Risklevel) 
        {
            case RISK_LEVEL::RISK_A : Riskbonus = 1.3; break;
            case RISK_LEVEL::RISK_B : Riskbonus = 1.2; break;
            case RISK_LEVEL::RISK_C : Riskbonus = 1.1; break;
        };
        
        return (int)(SalesWorker::GetPay() * (1 + RiskBonus()));
    }

    void ShowSalaryInfo() const
    	{
            cout << "Name : "; ShownameInfo();
            cout << "Salary : " << SalesWorker::GetPay() << endl;
            cout << "Risk pay : " << (int)(SalesWorker::GetPay() * RiskBonus()) << endl;
    		cout << "Sum : " << GetPay() << endl;
    	}
};


class EmpManager 
{
	Employee* empList[50];
	int empnum;

public:
	EmpManager() : empnum(0) {}

	void Addemp(Employee* emp) 
	{
		empList[empnum++] = emp;
	}

	void ShowAllSalaryInfo() const
	{
		for (int i = 0; i < empnum; i++) 
		{
			empList[i]->ShowSalaryInfo();
            cout << endl;
		}
	}

	void ShowTotalSalaryInfo() const
	{
		int sum = 0;
		for (int i = 0; i < empnum; i++) {
			sum += empList[i]->GetPay();
		}
        cout << sum << endl;
	}

	~EmpManager() 
	{
		for (int i = 0; i < empnum; i++) {
			delete empList[i];
		}
	}
};



int main(void) {
	EmpManager manager;
	
	ForeignSalesWorker* fseller1 = new ForeignSalesWorker("Hong", 1000, 0.1, RISK_LEVEL::RISK_A);
    fseller1->AddSales(7000);
    manager.Addemp(fseller1);

	ForeignSalesWorker* fseller2 = new ForeignSalesWorker("Yoon", 1000, 0.1, RISK_LEVEL::RISK_B);
    fseller2->AddSales(7000);
    manager.Addemp(fseller2);
    
	ForeignSalesWorker* fseller3 = new ForeignSalesWorker("Lee", 1000, 0.1, RISK_LEVEL::RISK_C);
    fseller3->AddSales(7000);
    manager.Addemp(fseller3);

    manager.ShowAllSalaryInfo();
	return 0;
}
