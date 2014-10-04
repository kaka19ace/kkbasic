#ifndef KKBASIC_VARIANT_H
#define KKBASIC_VARIANT_H

extern "C" {
#include <inttypes.h>
#include <sys/types.h>
}
#include <string>
#include <array>
#include <vector>
#include <map>
#include <tuple>

namespace kkbasic { namespace utils {

enum VariantType {
    V_NULL          = 0,
    V_UNDEFINED     = 1,
    V_BOOL          = 2,

    // intX_t
    V_INT8          = 3,
    V_INT16         = 4,
    V_INT32         = 5,
    V_INT64         = 6,

    // u_intX_t
    V_UINT8         = 7,
    V_UINT16        = 8,
    V_UINT32        = 9,
    V_UINT64        = 10,

    V_DOUBLE        = 11,
    V_NUMBER        = 12,

    V_STRING        = 13,
    V_FIXED_ARRAY   = 14,
    V_DYNAMIC_ARRAY = 15,
    V_DATE          = 16,
    V_TIME          = 17,
    V_TIMESTAMP     = 18,
    V_TABLE         = 19, // lua table
};

//struct tm
//{
//  int tm_sec;			/* Seconds.	[0-60] (1 leap second) */
//  int tm_min;			/* Minutes.	[0-59] */
//  int tm_hour;			/* Hours.	[0-23] */
//  int tm_mday;			/* Day.		[1-31] */
//  int tm_mon;			/* Month.	[0-11] */
//  int tm_year;			/* Year	- 1900.  */
//  int tm_wday;			/* Day of week.	[0-6] */
//  int tm_yday;			/* Days in year.[0-365]	*/
//  int tm_isdst;			/* DST.		[-1/0/1]*/
//}

struct VDate {
private:
    u_int16_t year_;
    u_int8_t  month_;
    u_int8_t  day_;
public:
    VDate()
        :year_(0), month_(0), day_(0)
    {
    }
    VDate(const u_int16_t year, const u_int8_t month, const u_int8_t day) {
        year_ = year;
        month_ = month;
        day_ = day;
    }
    ~VDate(){}

    inline void SetDate(const u_int16_t year, const u_int8_t month, const u_int8_t day) {
        year_ = year;
        month_ = month;
        day_ = day;
    }
    inline u_int16_t GetYear() const  { return year_; }
    inline u_int8_t  GetMonth() const { return month_; }
    inline u_int8_t  GetDay() const   { return day_; }
    inline std::tuple<u_int16_t, u_int8_t, u_int8_t> GetDateValue() const {
        return std::make_tuple(year_, month_, day_);
    }
    inline VDate& operator=(const VDate &d) {
        year_= d.GetYear();
        month_ = d.GetMonth();
        day_ = d.GetDay();
    }
};

struct VTime {
private:
    u_int8_t hour_;
    u_int8_t minute_;
    u_int8_t second_;
public:
    VTime():hour_(0),minute_(0),second_(0) {}
    VTime(const u_int8_t hour, const u_int8_t minute, const u_int8_t second) {
        hour_ = hour;
        minute_ = minute;
        second_ = second;
    }
    ~VTime(){}

    inline void SetTime(const u_int8_t hour, const u_int8_t minute, const u_int8_t second) {
        hour_ = hour;
        minute_ = minute;
        second_ = second;
    }
    inline u_int8_t GetHour() const   { return hour_; }
    inline u_int8_t  GetMinute() const { return minute_; }
    inline u_int8_t  GetSecond() const { return second_; }
    inline std::tuple<u_int8_t, u_int8_t, u_int8_t> GetTimeValue() const {
        return std::make_tuple(hour_, minute_, second_);
    }
    inline VTime& operator=(const VTime &t) {
        hour_ = t.GetHour();
        minute_ = t.GetMinute();
        second_ = t.GetSecond();
    }
};

struct VTimestamp {
private:
    VDate date_;
    VTime time_;
public:
    VTimestamp():date_(), time_() {
    }
    ~VTimestamp(){}
    inline void SetTimestamp(VDate &d, VTime &t) {
        date_ = d;
        time_ = t;
    }
    inline SetTimestamp(const u_int16_t year, const u_int8_t month, const u_int8_t day,
                        const u_int8_t hour, const u_int8_t minute, const u_int8_t second) {
        date_.SetDate(year, month, day);
        time_.SetTime(hour, minute, second);
    }
    inline void SetTimestamp(VDate &d) {
        date_ = d;
    }
    inline void SetTimestamp(VTime &t) {
        time_ = t;
    }
    inline VTimestamp& operator=(VTimestamp &t) {
        date_ = t.Ge
    }

    inline VDate GetDate() { return date_; }
    inline VTime GetTime() { return time_; }
    inline std::tuple<u_int16_t, u_int8_t, u_int8_t, u_int8_t, u_int8_t, u_int8_t> GetTimestampeValue() {
        return std::ma
    }

};


class Variant final
{
private:
     VariantType type_;

     union {
         bool      b;
         int8_t    i8;
         int16_t   i16;
         int32_t   i32;
         int64_t   i64;

         u_int8_t  ui8;
         u_int16_t ui16;
         u_int32_t ui32;
         u_int64_t ui64;

         double    d;
         std::string s;
         std::vector<Variant> v;
         std::array<Variant>  a;
         std::map<std::string, Variant> m;
         struct std::tm *t;
     } value_;

public:
    Variant();

    Variant(const int8_t &val);
    Variant(const int16_t &val);
    Variant(const int32_t &val);
    Variant(const int64_t &val);

    Variant(const u_int8_t &val);
    Variant(const u_int16_t &val);
    Variant(const u_int32_t &val);
    Variant(const u_int64_t &val);

    Variant(const double &val);

    Variant(const char *pVal);
    Variant(const std::string &s);

};







} // namespace utils
} // namespace kkbasic




#endif // VARIANT_H
