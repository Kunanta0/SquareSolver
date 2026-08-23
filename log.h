#ifndef LOG_H_INCLUDED
#define LOG_H_INCLUDED

enum
{
    LOG_INFO,
    LOG_WARNING,
    LOG_ERROR
};

#define write_log(file, time, level, ...)\
{\
    fprintf(file, "%s ", time);\
    fprintf(file, #level": " __VA_ARGS__);\
}
#define PR_VAR(x, specif) #x " = %" #specif "\n", x

#endif // LOG_H_INCLUDED
