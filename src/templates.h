#ifndef _TEMPLATES
#define _TEMPLATES

struct template1Data {
    char* backgroundColor;
    char* mainHeadline;
    char* task1;
    char* task2;
    char* task3;
    char* taskBackgroundColor;

    template1Data() {
        backgroundColor = new char[7];
        mainHeadline = new char[50];
        task1 = new char[50];
        task2 = new char[50];
        task3 = new char[50];
        taskBackgroundColor = new char[7];
    }

    ~template1Data() = default;
};

struct template2Data {
    char* mainHeadline;
    char* firstFloorColor;
    char* subTitle1;
    char* task1;
    char* task2;
    char* task3;
    char* task4;

    template2Data() {
        mainHeadline = new char[50];
        task1 = new char[50];
        task2 = new char[50];
        task3 = new char[50];
        task4 = new char[50];
    }

    ~template2Data() = default;
};

#endif