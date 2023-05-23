#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class BranchFinances {
protected:
    const int RENT = 50; // арендная ставка в галлеонах в месяц
    const int RENT_THRESHOLD = 270; // сумма выручки, сверх которой нужно платить процент
    const double RENT_PERCENT = 0.07; // процент, который нужно платить сверх выручки сверх порога

    const int EMPLOYEE_SALARY = 35; // зарплата сотрудника в галлеонах в месяц
    const int AUROR_SERVICES = 15; // расходы на услуги мракоборцев в галлеонах в месяц

    double revenue; // выручка в галлеонах в месяц
    double expenses; // расходы в галлеонах в месяц

public:
    BranchFinances() {
        revenue = 0;
        expenses = 0;
    }

    ~BranchFinances() {}

    void calculateRent() {
        if (revenue > RENT_THRESHOLD) {
            expenses += RENT + ((revenue - RENT_THRESHOLD) * RENT_PERCENT);
        }
        else {
            expenses += RENT;
        }
    }

    void calculateExpenses() {
        expenses += EMPLOYEE_SALARY + AUROR_SERVICES;
    }

    void printExpenses() {
        cout << "Expenses:" << endl;
        cout << "- Employee salary: " << EMPLOYEE_SALARY << " galleons/month" << endl;
        cout << "- Rent: " << RENT << " galleons/month" << endl;
        if (revenue > RENT_THRESHOLD) {
            cout << "- Additional rent: " << ((revenue - RENT_THRESHOLD) * RENT_PERCENT) << " galleons/month" << endl;
        }
        cout << "- Auror services: " << AUROR_SERVICES << " galleons/month" << endl;
        cout << "Total expenses: " << expenses << " galleons/month" << endl;
    }

    void generateRevenue() {
        srand(time(nullptr));
        revenue = rand() % 251 + 250; // случайное значение выручки в диапазоне от 250 до 500 галлеонов
    }

    double calculateNetProfit() {
        return revenue - expenses;
    }
};

class NewBranch : public BranchFinances {
private:
    string branchName;

public:
    NewBranch(string name) : BranchFinances() {
        branchName = name;
    }

    ~NewBranch() {}

    void run() {
        generateRevenue();
        calculateRent();
        calculateExpenses();
        printExpenses();
        double netProfit = calculateNetProfit();
        cout << "Net profit: " << netProfit << " galleons/month" << endl;
    }
};

int main() {
    NewBranch branch("London");
    branch.run();
    return 0;
}