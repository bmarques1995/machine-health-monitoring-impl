#include "Hello.hpp"
#include "CPUMonitor.hpp"

int main()
{
    ClientMonitor::Monitor::ReadActiveProcesses();
    ClientMonitor::Monitor::GetCurrentRAM();
    ClientMonitor::Monitor::GetNumberOfTCPConnections();
    return 0;
}