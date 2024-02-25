#include <iostream>
#include <ctime>
#include <iostream>
#include <pthread.h>


using namespace::std;

template <typename T>
class Stopwatch {
private:
    T data;

public:
    Stopwatch(T data) : data(data) {}

    void setData(T newData) {
        data = newData;
    }

    T getData() const {
        return data;
    }

    void display() const {
        std::cout << "Data: " << data << std::endl;
    }


};

int main() {
    // Example usage
    Stopwatch<int> w(10);
    w.display();

    Stopwatch<std::string> myStringTemplate("Hello");
    myStringTemplate.display();


    time_t timer;
    struct tm y2k = {0};
    double seconds;

    y2k.tm_hour = 0;   y2k.tm_min = 0; y2k.tm_sec = 0;
    y2k.tm_year = 100; y2k.tm_mon = 0; y2k.tm_mday = 1;
    time(&timer); /* get current time; same as: timer = time(NULL)  */
    

    

    int i=0;
    bool flag = true;
    
    const int count = difftime(timer,mktime(&y2k));

    while(flag){

        time(&timer); /* get current time; same as: timer = time(NULL)  */
        seconds = difftime(timer,mktime(&y2k));
        
        
        

        cout<<"seconds :"<< (seconds-count)<<endl;;

        
        i=i+1;

        

        if( (seconds-count) > 10){
            flag = false;
        }



    }



    return 0;
}