#ifndef DIRECTION_H_INCLUDED
#define DIRECTION_H_INCLUDED

class direction
{
public:
    virtual ~direction() = default;
    virtual void (int x, int y, const std::char& direction) = 0;
};

class variationDirection : public direction {
public:
    void notifier(int x, int y, const std::char& direction) override;
private:
    int x,y;
};


#endif // DIRECTION_H_INCLUDED
