#ifndef _CELL_TIMESTAMP_HPP_
#define _CELL_TIMESTAMP_HPP_

//#include <windows.h>
#include<chrono>
using namespace std::chrono;

class CELLTimestamp
{
public:
    CELLTimestamp()
    {
        //QueryPerformanceFrequency(&_frequency);
        //QueryPerformanceCounter(&_startCount);
		update();
    }

    ~CELLTimestamp()
    {}

    void update()
    {
        //QueryPerformanceCounter(&_startCount);
		_begin = high_resolution_clock::now();
    }
    double getElapsedSecond()
    {
    /**
    *   get second
    */
        return  getElapsedTimeInMicroSec() * 0.000001;
    }
    double getElapsedTimeInMilliSec()
    {
    /**
    *   get millisecond
    */
        return this->getElapsedTimeInMicroSec() * 0.001;
    }
    long long getElapsedTimeInMicroSec()
    {
    /**
    *   get microsecond
    */
		/*
        LARGE_INTEGER endCount;
        QueryPerformanceCounter(&endCount);

        double  startTimeInMicroSec =   _startCount.QuadPart * (1000000.0 / _frequency.QuadPart);
        double  endTimeInMicroSec   =   endCount.QuadPart * (1000000.0 / _frequency.QuadPart);

        return  endTimeInMicroSec - startTimeInMicroSec;
		*/
		
		return duration_cast<microseconds>(high_resolution_clock::now() - _begin).count();
    }
protected:
    //LARGE_INTEGER   _frequency;
    //LARGE_INTEGER   _startCount;
	time_point<high_resolution_clock> _begin;
};

#endif // !_CELL_TIMESTAMP_HPP_