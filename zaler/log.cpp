#include "log.h"
namespace zaler
{
    Logger::Logger()(const std::string name)
    {    im_name(name){}
    }
    void Logger::log(LogLevel::Level level, LogEvent::ptr event)
    
    void Logger::debug(Logevent::ptr event)
    {
        debug(LoggerLevel::DEBUG,event);
    }
    void Logger::info(Logevent::ptr event)
    {
        debug(LoggerLevel::INFO,event);
    }
    void Logger::warn(Logevent::ptr event)
    {
        debug(LoggerLevel::WARN,event);
    }
    void Logger::error(Logevent::ptr event)
    {
        debug(LoggerLevel::ERROR,event);
    }
    void Logger::fatal(Logevent::ptr event)
    {
        debug(LoggerLevel::FATAL,event);
    }
    void Logger::addAppender(LogAppender::ptr appdender)
    {
    m_appenders.push_back(appender);
    }
    void Logger::delAppender(LogAppender::ptr appdender)
    {
        for(auto it = m_appenders,begin(); it != m_appenders.end();++it)
        {
            if (*it  == appender)
            {
            m_appenders.eraser(it);
            break;
            }
        }
    }
}
