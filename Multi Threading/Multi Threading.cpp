#include <iostream>
#include <thread>

using namespace std;

void foo() {

    this_thread::sleep_for(chrono::seconds(1));
    cout << "1"<<endl;
    this_thread::sleep_for(chrono::seconds(1));
    cout << "2" << endl;
    this_thread::sleep_for(chrono::seconds(1));
    cout << "3" << endl;

}

int main()
{
    
    thread thd(foo);

    cout << "Starting!" << endl;

    thd.join();

    cout << "Finished"<<endl;

}

