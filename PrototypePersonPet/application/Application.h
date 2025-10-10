#pragma once
#include <windows.h>
#include "ICommon.h"
#include "IApplication.h"
#include "IPerson.h"
#include "IPet.h"


namespace LEApplication{
    class Application : public IApplication{
    public:
        Application();
        ~Application();
        
        void Shutdown();

        void Run(std::string exampleName) override;

        void LoadPerson();
        void LoadPet();

        //void SetCaseName(std::string sampleName) override;
    private:
        //std::string caseName_ = "case001";
        HMODULE dll_person;
        human::IPerson *p_person = NULL;
        HMODULE dll_pet;
        animal::IPet *p_pet = NULL;
    };

    extern "C" void* CreateInstance();
    extern "C" void DestroyInstance(void *p);

    /*
    struct Person : public IPerson {
        Person(const char* name, int age);
        ~Person();

        void greet() override;
        void playWith(animal::IPet* pet) override;

        void setPet(animal::IPet *pet) override;
        void playWithPet() override;
    private:
        struct Impl;   // 前向声明
        std::unique_ptr<Impl> pImpl;
    };
    //Note: 这里用Impl隔离了一层，用户只能调用Person的greet和playWith函数，Person再转发给Impl

    extern "C" IPerson* CreatePerson(const char* name, int age); //need this function so GetProcAddress() can get correct address
    //Note: 这是一个"工厂函数"，也叫"导出函数"，它是这个Person DLL唯一暴露给外面的函数。用户通过这个函数获得指针后，就可以调用其内部的成员函数了。
    */
}