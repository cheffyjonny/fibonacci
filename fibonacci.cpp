#include <iostream>
#include <string>
#include <random>

struct FibonacciCounter {
    int count0 = 0;
    int count1 = 0;
    
    int fibonacci(int n) {
        if (n == 0) {
            count0++;
            return 0;
        } else if (n == 1) {
            count1++;
            return 1;
        } else {
            return fibonacci(n - 1) + fibonacci(n - 2);
        }
    }
};

int getRandomNumber() {
    std::random_device rd; 
    std::mt19937 mt(rd()); 
    std::uniform_int_distribution<int> dist(0, 40); 

    return dist(mt); 
}

int getNumIterationsFromUser() {
    int numIterations;
    while (true) {
        std::cout << "Enter the number of iterations: ";
        std::cin >> numIterations;

        if (std::cin.fail()) {
            std::cin.clear(); 
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
            std::cout << "Invalid input. Please enter a valid integer." << std::endl;
        }        
        else if (numIterations <= 0) {
            std::cout << "Please enter a positive number of iterations." << std::endl;
        }
        else {
            break; 
        }
    }
    return numIterations;
}

FibonacciCounter getFibonacciCounts(int n) {
    FibonacciCounter counter;
    counter.fibonacci(n);
    return counter;
}

void printFibonacciCounts(int i) {
    int randomNum = getRandomNumber();
    FibonacciCounter result = getFibonacciCounts(randomNum);
    // 과제 출력 요청되로 출력되는 횟수를 공백으로 구분하여서 출력하였습니다. 좀더 구체적인 정보를 입력한 방법도 구현해 보았습니다(line 62)
    std::cout << result.count0 << " " << result.count1 << std::endl;
    // std::cout << "Result for round " << i << " = " << randomNum << ": " << result.count0 << " " << result.count1 << std::endl;
}

int main() {
    int numIterations = getNumIterationsFromUser();
    for (int i = 1; i <= numIterations; ++i) {
       printFibonacciCounts(i);
    }
    return 0;
}