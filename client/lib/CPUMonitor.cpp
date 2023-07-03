#include "CPUMonitor.hpp"
#include <fstream>
#include <sstream>
#include <iostream>
#include <cstdint>

void ClientMonitor::Monitor::ReadActiveProcesses()
{
    std::string line;
    uint64_t user, niced, sysproc;
    std::stringstream line_info;
    std::ifstream processes("/proc/stat");
    if (processes.is_open()) {
        std::string line_reader;
        std::getline(processes, line);
        line_info << line;
        line_info >> line_reader >> user >> niced >> sysproc; 
        std::cout << user << " " << niced << " " << sysproc << "\n";
        processes.close();
    } else {
        std::cerr << "Unable to open the file." << std::endl;
        exit(1);
    }
}

void ClientMonitor::Monitor::GetCurrentRAM()
{
    std::string line;
    std::stringstream line_info;
    uint64_t total, free, available;
    std::ifstream processes("/proc/meminfo");
    if (processes.is_open()) {
        for (size_t i = 0; i < 3; i++)
        {
            std::getline(processes, line);
            line_info << line << "\n";
        }
        std::string line_reader;
        line_info >> line_reader >> total >> line_reader >> line_reader >> free >> line_reader >> line_reader >> available;
        std::cout << total << " " << free << " " << available << "\n";
        processes.close();
    } else {
        std::cerr << "Unable to open the file." << std::endl;
        exit(1);
    }
}

void ClientMonitor::Monitor::GetNumberOfTCPConnections()
{
    std::string line;
    std::ifstream processes("/proc/net/tcp");
    uint32_t numberOfConnections = 0u;
    if (processes.is_open()) {
        std::string line;
        while (std::getline(processes, line)) {
            std::cout << line << "\n";
            numberOfConnections++;
        }
        numberOfConnections--;
        std::cout << numberOfConnections << "\n";
        processes.close();
    } else {
        std::cerr << "Unable to open the file." << std::endl;
        exit(1);
    }
}