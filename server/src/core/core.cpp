#include "core.h"

ServerOptions* ServerOptions::m_Instance { nullptr };
std::mutex ServerOptions::m_Mutex;

ServerOptions* ServerOptions::GetInstance() {
    std::lock_guard<std::mutex> lock(m_Mutex);
    if (m_Instance == nullptr) {
        m_Instance = new ServerOptions();
    }
    return m_Instance;
}