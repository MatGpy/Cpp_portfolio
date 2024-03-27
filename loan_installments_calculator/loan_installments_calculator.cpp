#include <iostream>
#include <cstdlib>
#include <time.h>
#include <math.h>
#include <cmath>
#include <map>
#include <string>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <random>
#include <array>
using namespace std;
void takeUserDate(map<string,int> daysReversed, map<string,int> monthsReversed, string& userDate, string& userDay, string& userMonth, string& userYear) {
    cout << "Insert the date when your loan was taken (in dd-mm-yyyy format): \n";
    cin >> userDate;
    userDay = userDate.substr(0,2);
    userMonth = userDate.substr(3,2);
    userYear = userDate.substr(6,4);
    if(daysReversed.count(userDay) == 0 || monthsReversed.count(userMonth) == 0 || stoi(userYear) <= 0) {
        throw(userYear);
    }
}
int takeLoanAmount(int loanAmount) {
    cout << "Insert amount of your loan (in PLN): \n";
    cin >> loanAmount;
    if(loanAmount < 1000) {
        throw(loanAmount);
    }
    return loanAmount;
}
int takeLoanCommission(float loanCommission) {
    cout << "Insert your bank's loan commission (in %): \n";
    cin >> loanCommission;
    if(loanCommission <= 0) {
        throw(loanCommission);
    }
    return loanCommission;
}
int takeLoanInterestRate(float loanInterestRate) {
    cout << "Insert your loan's annual interest rate (in %): \n";
    cin >> loanInterestRate;
    if(loanInterestRate <= 0) {
        throw(loanInterestRate);
    }
    return loanInterestRate;
}
int takePeriodOfPayment(int periodOfPayment) {
    cout << "Insert period of your loan's payment (in months): \n";
    cin >> periodOfPayment;
    if(periodOfPayment > 240 || periodOfPayment <= 0) {
        throw(periodOfPayment);
    }
    return periodOfPayment;
}
int calculateTotalLoan(int loanAmount, float loanCommission, int totalLoanAmount) {
    totalLoanAmount = loanAmount + (loanAmount*loanCommission);
    return totalLoanAmount;
}
int calculateInstallment(int totalLoanAmount, float loanInterestRate, int periodOfPayment, int installment) {
    installment = (totalLoanAmount*(pow(loanInterestRate+1,periodOfPayment))*loanInterestRate)/(pow(loanInterestRate+1,periodOfPayment)-1);
    return installment;
}
int calculateAverageInstallment(int periodOfPayment, float loanInterestRate, int totalLoanAmount, int installment, int month, map<int,float> wiborRates) {
    int i = 1;
    while (i<=periodOfPayment) {
        installment += calculateInstallment(totalLoanAmount, ((loanInterestRate+wiborRates[month]/100)/12), periodOfPayment, installment);
        i++;
        if(month == 12) {
            month = 1;
        } else {
            month++;
        }
    }
    installment /= periodOfPayment;
    return installment;
}
void createTable(int periodOfPayment, int day, int month, int year, int installment, map<int,string> days, map<int,string> months, vector <string>& paymentPlan) {
    for (int i = 0; i < periodOfPayment; i++) {
        if(day == 31 || day == 30) {
            if(month == 1) {
                day = 28;
            } else {
                day = 30;
            }
        }
        if(month == 12) {
            month = 1;
            year++;
        } else {
            month++;
        }
        paymentPlan.push_back(days[day]+"-"+months[month]+"-"+to_string(year));
        paymentPlan.push_back(to_string(installment));
    }
}
void printPaymentPlan(vector<string> paymentPlan, int periodOfPayment) {
    cout << "| Date of the payment | Installment (in PLN) |\n";
    for(int i=1;i<paymentPlan.size();i+=2) {
        cout << "| " << paymentPlan.at(i-1) << " | " << paymentPlan.at(i) << " |\n";
    }
}
int main() {
    try {
        int loanAmount = 0;
        int periodOfPayment = 0;
        int totalLoanAmount = 0;
        int installment = 0;
        float loanCommission = 0.00;
        float loanInterestRate = 0.00;
        string userDate = "";
        string userDay = "";
        string userMonth = "";
        string userYear = "";
        vector <string> paymentPlan;
        map<int,string> months {
            {1, "01"}, {2, "02"}, {3, "03"}, {4, "04"}, {5, "05"}, {6, "06"}, {7, "07"}, {8, "08"}, {9, "09"}, {10, "10"}, {11, "11"}, {12, "12"}
        };
        map<string,int> monthsReversed {
            {"01", 1}, {"02", 2}, {"03", 3}, {"04", 4}, {"05", 5}, {"06", 6}, {"07", 7}, {"08", 8}, {"09", 9}, {"10", 10}, {"11", 11}, {"12", 12}
        };
        map<int,string> days {
            {1, "01"}, {2, "02"}, {3, "03"}, {4, "04"}, {5, "05"}, {6, "06"}, {7, "07"}, {8, "08"}, {9, "09"}, {10, "10"}, {11, "11"}, {12, "12"}, {13, "13"}, {14, "14"}, {15, "15"}, {16, "16"}, {17, "17"}, {18, "18"}, {19, "19"}, {20, "20"}, {21, "21"}, {22, "22"}, {23, "23"}, {24, "24"}, {25, "25"}, {26, "26"}, {27, "27"}, {28, "28"}, {29, "29"}, {30, "30"}, {31, "31"}
        };
        map<string,int> daysReversed {
            {"01", 1}, {"02", 2}, {"03", 3}, {"04", 4}, {"05", 5}, {"06", 6}, {"07", 7}, {"08", 8}, {"09", 9}, {"10", 10}, {"11", 11}, {"12", 12}, {"13", 13}, {"14", 14}, {"15", 15}, {"16", 16}, {"17", 17}, {"18", 18}, {"19", 19}, {"20", 20}, {"21", 21}, {"22", 22}, {"23", 23}, {"24", 24}, {"25", 25}, {"26", 26}, {"27", 27}, {"28", 28}, {"29", 29}, {"30", 30}, {"31", 31}
        };
        map<int,float> wiborRates {
            {1, 7.00}, {2, 7.00}, {3, 6.95}, {4, 6.95}, {5, 6.95}, {6, 6.95}, {7, 6.70}, {8, 6.55}, {9, 5.65}, {10, 5.60}, {11, 5.80}, {12, 5.65}, 
        };
        takeUserDate(daysReversed, monthsReversed, userDate, userDay, userMonth, userYear);
        loanAmount = takeLoanAmount(loanAmount);
        loanCommission = takeLoanCommission(loanCommission);
        loanCommission /= 100;
        loanInterestRate = takeLoanInterestRate(loanInterestRate);
        loanInterestRate /= 100;
        periodOfPayment = takePeriodOfPayment(periodOfPayment);
        totalLoanAmount = calculateTotalLoan(loanAmount, loanCommission, totalLoanAmount);
        installment = calculateAverageInstallment(periodOfPayment, loanInterestRate, totalLoanAmount, installment, monthsReversed[userMonth], wiborRates);
        createTable(periodOfPayment, stoi(userDay), stoi(userMonth), stoi(userYear), installment, days, months, paymentPlan);
        printPaymentPlan(paymentPlan, periodOfPayment);
    } catch(int errorNum) {
        cout << "Error\n";
    } catch(string errorNum) {
        cout << "Error\n"; 
    }
    return 0;
}