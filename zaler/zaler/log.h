#ifndef _ZALAR_LOG_H_
#define _ZALAR_LOG_H
#include<string>
#include<stdint.h>
#include<memory>
#include<list.h>

namespace zaler
{

class LogEvent
{
public:
    typedef std::shared_ptr<LogEvent> ptr;
    LogEvent();
private:
    const char * m_file = nullptr;// C++ 11
    uint32_t m_elaplse = 0;//runtime
    int32_t m_line = 0;//line ID
    uint32_t m_threadId = 0;
    uint32_t m_fiberId = 0;
    uint64_t m_time = 0;
    std::string m_content;
}
//等级
class LogLevel{
public:
    enum Level{
    DEBUG = 1,
    INFO = 2,
    WARN = 3,
    ERROR = 4,
    FATAL = 5,
    };
};
LogLevel::
//format
class LogFormat
{
public:
    typedef std::shared_ptr<LogFormat> ptr;

    std::string format(LogEvent::ptr event);
private:

};

//log to place
class LogAppender
{
public:
    typedef std::shared_ptr<logAppender> ptr;
    virtual ~LogAppender(){};
    void log(LogLevel::ptr levle,LogEvent::ptr event);
private:
    LogLevel::Level m_level;

};
//log
class Logger
{
public:
    
    typedef std::shared_ptr<Logger> ptr;
    enum{
    DEBUG = 1,
    INFO = 2;
    WARN = 3;
    ERROR = 4;
    FATAL = 5;
    };
    Logger()(const std::string name = "root");
    void log(LogLevel::Level level, LogEvent::ptr event);

    void debug(Logevent::ptr event);
    void info(Logevent::ptr event);
    void warn(Logevent::ptr event);
    void error(Logevent::ptr event);
    void fatal(Logevent::ptr event);

    void addAppender(LogAppender::ptr appdender);
    void delAppender(LogAppender::ptr appdender);
    LogLevel::Level getLevel()const {return m_level;}
    void setLevel (Logger::Level val){m_level = val;}
private:
    std::string m_name;
    LogLevel::Level m_level;
    std::list<LogAppender::ptr> m_appenders;
};
class StdoutLogAppender : public LogAppender
{};
class FileLogAppender :public LogAppender
{};

#endif
