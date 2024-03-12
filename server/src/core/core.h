#pragma once

#include <mutex>

class ServerOptions {
private:
    static ServerOptions* m_Instance;
    static std::mutex m_Mutex;

protected:
    ServerOptions() { }
    ~ServerOptions() = default;

public:
    ServerOptions(ServerOptions& other) = delete;

    void operator=(ServerOptions const&) = delete;

    static ServerOptions* GetInstance();

    bool isInitialized() const { return m_isInitialized; }
    void setIsInitialized(bool val) { m_isInitialized = val; }

private:
    bool m_isInitialized = false;

};