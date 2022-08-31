class Clock
{
public:
    Clock();
    ~Clock();
    void Update();
    void Dump();

    int Year() const { return mYear; }
    int Mon() const { return mMon; }
    int Day() const { return mDay; }
    int Hour() const { return mHour; }
    int Min() const { return mMin; }
    int Sec() const { return mSec; }

private:
    int mYear;
    int mMon;
    int mDay;
    int mHour;
    int mMin;
    int mSec;
};
