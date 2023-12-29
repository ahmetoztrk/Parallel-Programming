#include <pthread.h>
#include <iostream>
#include <Windows.h>
#include <conio.h>

using namespace std;

static double currentAccountBalance = 1000.00f;
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

void* Deposit(void* amount)
{
    pthread_mutex_lock(&lock);
    double money = currentAccountBalance;
    Sleep(2000);
    money += *(double*)amount;
    currentAccountBalance = money;
    pthread_mutex_unlock(&lock);
    return NULL;
}

void* Withdraw(void* amount)
{
    pthread_mutex_lock(&lock);
    double money = currentAccountBalance;
    Sleep(2000);
    money -= *(double*)amount;
    currentAccountBalance = money;
    pthread_mutex_unlock(&lock);
    return NULL;
}

int main(int argc, char* argv[])
{
    pthread_t thread1, thread2;
    double amountToWithdraw = 0, amountToDeposit = 0;
    cout << endl << "Current account balance: " << currentAccountBalance;
    cout << endl << "Enter the amount to withdraw: ";
    cin >> amountToWithdraw;
    cout << endl << "Enter the amount to deposit: ";
    cin >> amountToDeposit;
    int result = pthread_create(&thread1, NULL, Deposit, (void*)&amountToDeposit);
    if (result) _exit(-1);
    result = pthread_create(&thread2, NULL, Withdraw, (void*)&amountToWithdraw);
    if (result) _exit(-1);
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    cout << endl << "Your account balance: " << currentAccountBalance;
    cin >> result;
    return 0;
}

