#pragma once

#include <mutex>

class ServerOptions {
private:
    static ServerOptions* m_Instance;
    static std::mutex m_Mutex;

protected:
    ServerOptions() { }
    ~ServerOptions() { }

public:
    ServerOptions(ServerOptions& other) = delete;

    void operator=(ServerOptions const&) = delete;

    static ServerOptions* GetInstance();
};