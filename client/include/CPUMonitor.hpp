#ifndef CPU_MONITOR_HPP
#define CPU_MONITOR_HPP

#include <json/json.h>

namespace ClientMonitor
{
    class Monitor
    {
    public:
        static void ReadActiveProcesses();
        static void GetCurrentRAM();
        static void GetNumberOfTCPConnections();
    };
}

#endif // CPU_MONITOR_HPP
