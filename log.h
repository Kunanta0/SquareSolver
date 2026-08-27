#ifndef LOG_H_INCLUDED
#define LOG_H_INCLUDED

enum LogLevel
{
    LOG_INFO,
    LOG_WARNING,
    LOG_ERROR
};

#define write_log(file, level, ...)\
{\
    time_t now = time(NULL);\
    char* time_str = ctime(&now);\
    time_str[strcspn(time_str, "\n")] = 0;\
    \
    fprintf(file, "%s ", time_str);\
    fprintf(file, #level": " __VA_ARGS__);\
}
#define PR_VAR(x, specif) #x " = %" #specif "\n", x

#endif // LOG_H_INCLUDED
