#include <iostream>
#include <ctime>


using namespace std;


bool isPrime(int n)
{
    bool result = true;

    //Replace test with "i*i <= n" to run in O(sqrt(n)) time
    for (int i = 2; i < n; i++)
    {
        int* np = new int;
        if (0 == n % i)  {
            result = false;
            //we could just return here...
            //But not doing so runtime depend more directly on n
            //and not on if n is actually prime or not
        }
        delete np;
    }
    return result;
}

int main()
{

    const int TIMING_REPETITIONS = 100;
    clock_t start = clock();
    cout << start << endl;
	
    int result;
	//Repeat work many times to get measurable duration
    for(int i = 0; i < TIMING_REPETITIONS; i++) {
		//Work we want to measure
 		result = isPrime(100000);
	}

    clock_t end = clock();
    cout << end << endl;
    cout << (end - start) << endl;
    
	//Figure out average time to do work one time
    double seconds = static_cast<double>(end - start)
                        / CLOCKS_PER_SEC;
                        /// TIMING_REPETITIONS;

    cout << endl << "Answer is " << result << endl;

    cout << endl << "Calculations took " << seconds << " seconds" << endl;
}


