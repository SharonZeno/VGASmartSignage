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
        backgroundColor = new char[7]();
        mainHeadline = new char[50]();
        task1 = new char[50]();
        task2 = new char[50]();
        task3 = new char[50]();
        taskBackgroundColor = new char[7]();
    }

    ~template1Data() = default;
};

struct template2Data {
    char* mainHeadline;
    char* firstFloorHeadline;
    char* firstFloorBackgroundColor;
    char* firstFloorClassDesc1;
    char* firstFloorClassDesc2;
    char* firstFloorClassDesc3;
    char* firstFloorClassDesc4;
    char* secondFloorHeadline;
    char* secondFloorBackgroundColor;
    char* secondFloorClassDesc1;
    char* secondFloorClassDesc2;
    char* secondFloorClassDesc3;
    char* secondFloorClassDesc4;
    char* thirdFloorHeadline;
    char* thirdFloorBackgroundColor;
    char* thirdFloorClassDesc1;
    char* thirdFloorClassDesc2;
    char* thirdFloorClassDesc3;
    char* thirdFloorClassDesc4;
    
    template2Data() {
        mainHeadline = new char[50]();
        firstFloorHeadline = new char[50]();
        firstFloorBackgroundColor = new char[7]();
        firstFloorClassDesc1 = new char[50]();
        firstFloorClassDesc2 = new char[50]();
        firstFloorClassDesc3 = new char[50]();
        firstFloorClassDesc4 = new char[50]();
        secondFloorHeadline = new char[50]();
        secondFloorBackgroundColor = new char[7]();
        secondFloorClassDesc1 = new char[50]();
        secondFloorClassDesc2 = new char[50]();
        secondFloorClassDesc3 = new char[50]();
        secondFloorClassDesc4 = new char[50]();
        thirdFloorHeadline = new char[50]();
        thirdFloorBackgroundColor = new char[7]();
        thirdFloorClassDesc1 = new char[50]();
        thirdFloorClassDesc2 = new char[50]();
        thirdFloorClassDesc3 = new char[50]();
        thirdFloorClassDesc4 = new char[50]();
    }

    ~template2Data() = default;
};

#endif