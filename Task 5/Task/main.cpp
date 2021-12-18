#include <pthread.h>
#include <unistd.h>
#include <iostream>
#include <cstring>
#include <queue>
#include <fstream>

std::ofstream ofst("output.txt");

int tasks[3];
int done_tasks[3];
int total_tasks;

pthread_mutex_t mutex;

std::queue<int> first_queue, second_queue, third_queue;

void errMessage() {
    std::cout << "Invalid command line arguments!\n"
        "    Expected:\n"
        "        Command -f input.txt\n"
        "    Or:\n"
        "        Command -n size\n";
}

void checkingProgram(int pNum);
void writingProgram(int pNum);

void* programmer(void* param) {
    int pNum = *((int*)param);

    while (total_tasks > 0) {
        pthread_mutex_lock(&mutex);

        writingProgram(pNum);
        checkingProgram(pNum);

        pthread_mutex_unlock(&mutex);

        sleep(1);
    }

    return nullptr;
}

void checkingProgram(int pNum) {
    std::queue<int>* pNum_queue = &first_queue;
    int first_check = 1, second_check = 2;
    if (pNum == 1) {
        pNum_queue = &second_queue;
        first_check = 0;
        second_check = 2;
    }
    if (pNum == 2) {
        pNum_queue = &third_queue;
        first_check = 0;
        second_check = 1;
    }

    if (!(*pNum_queue).empty()) {
        if ((*pNum_queue).back() == first_check) {
            std::cout << "Programmer №" << pNum + 1 << " checking the program " << done_tasks[first_check] << "...\n";
            ofst << "Programmer №" << pNum + 1 << " checking the program " << done_tasks[first_check] << "...\n";
            if ((rand() % 2) == 0) {
                std::cout << "Programmer №" << pNum + 1 << " marked the program as completed!\n";
                ofst << "Programmer №" << pNum + 1 << " marked the program as completed!\n";
            }
            else {
                std::cout << "Programmer №" << pNum + 1 << " marked the program as unfulfilled(\n";
                std::cout << "Programmer №" << first_check + 1 << " rewrote the program " << done_tasks[first_check] << "\n";

                ofst << "Programmer №" << pNum + 1 << " marked the program as unfulfilled(\n";
                ofst << "Programmer №" << first_check + 1 << " rewrote the program " << done_tasks[first_check] << "\n";
            }

            --tasks[first_check];
            --total_tasks;
            ++done_tasks[first_check];
        }
        else {
            std::cout << "Programmer №" << pNum + 1 << " checking the program " << done_tasks[second_check] << "...\n";
            ofst << "Programmer №" << pNum + 1 << " checking the program " << done_tasks[second_check] << "...\n";
            if ((rand() % 2) == 0) {
                std::cout << "Programmer №" << pNum + 1 << " marked the program as completed!\n";
                ofst << "Programmer №" << pNum + 1 << " marked the program as completed!\n";
            }
            else {
                std::cout << "Programmer №" << pNum + 1 << " marked the program as unfulfilled(\n";
                std::cout << "Programmer №" << second_check + 1 << " rewrote the program " << done_tasks[second_check] << "\n";

                ofst << "Programmer №" << pNum + 1 << " marked the program as unfulfilled(\n";
                ofst << "Programmer №" << second_check + 1 << " rewrote the program " << done_tasks[second_check] << "\n";
            }

            --tasks[second_check];
            --total_tasks;
            ++done_tasks[second_check];
        }

        (*pNum_queue).pop();
    }
}

void writingProgram(int pNum) {
    std::queue<int>* pNum_queue_1 = &second_queue;
    std::queue<int>* pNum_queue_2 = &third_queue;
    int first_check = 1, second_check = 2;
    if (pNum == 1) {
        pNum_queue_1 = &first_queue;
        pNum_queue_2 = &third_queue;
        first_check = 0;
        second_check = 2;
    }
    if (pNum == 2) {
        pNum_queue_1 = &first_queue;
        pNum_queue_2 = &second_queue;
        first_check = 0;
        second_check = 1;
    }

    if (tasks[pNum] > 0) {
        if (rand() % 2 == 0) {
            std::cout << "Programmer №" << pNum + 1 << " writing program " << done_tasks[pNum] << "...\n";
            std::cout << "Programmer №" << pNum + 1 << " sent the program for review to the programmer №" << first_check + 1 << "\n";

            ofst << "Programmer №" << pNum + 1 << " writing program " << done_tasks[pNum] << "...\n";
            ofst << "Programmer №" << pNum + 1 << " sent the program for review to the programmer №" << first_check + 1 << "\n";

            (*pNum_queue_1).push(pNum);
        }
        else {
            std::cout << "Programmer №" << pNum + 1 << " writing program " << done_tasks[pNum] << "...\n";
            std::cout << "Programmer №" << pNum + 1 << " sent the program for review to the programmer №" << second_check + 1 << "\n";

            ofst << "Programmer №" << pNum + 1 << " writing program " << done_tasks[pNum] << "...\n";
            ofst << "Programmer №" << pNum + 1 << " sent the program for review to the programmer №" << second_check + 1 << "\n";

            (*pNum_queue_2).push(pNum);
        }
    }
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        errMessage();
        return 1;
    }

    int size[3];

    if (!strcmp(argv[1], "-f")) {
        std::ifstream ifst(argv[2]);
        ifst >> size[0] >> size[1] >> size[2];
    }
    else if (!strcmp(argv[1], "-n")) {
        size[0] = atoi(argv[2]);
        size[1] = size[2] = size[0];
    }
    else {
        errMessage();
        return 2;
    }

    for (int i = 0; i < 3; ++i) {
        if ((size[i] < 1) || (size[i] > 100)) {
            std::cout << "Incorrect number of programs " << size << " for programmer" << i + 1 << ", expected from 1 to 100.\n";
            return 3;
        }
    }

    std::cout << "Start!\n";
    ofst << "Start!\n";

    first_queue = std::queue<int>();
    second_queue = std::queue<int>();
    third_queue = std::queue<int>();

    for (int i = 0; i < 3; ++i) {
        tasks[i] = size[i];
        total_tasks += size[i];
        done_tasks[i] = 1;
    }

    int num[3];
    for (int i = 0; i < 3; i++) {
        num[i] = i;
    }

    pthread_t programmer1, programmer2, programmer3;

    pthread_mutex_init(&mutex, nullptr);

    pthread_create(&programmer1, nullptr, programmer, (void*)(num));
    pthread_create(&programmer2, nullptr, programmer, (void*)(num + 1));
    pthread_create(&programmer3, nullptr, programmer, (void*)(num + 2));

    pthread_join(programmer1, nullptr);
    pthread_join(programmer2, nullptr);
    pthread_join(programmer3, nullptr);

    std::cout << "End!\n";
    ofst << "End!\n";

    return 0;
}

