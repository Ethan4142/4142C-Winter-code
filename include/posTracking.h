using namespace vex;
using namespace std;

class posTracking {
private:
  const double dP = 0;
  const double dI = 0;
  const double dD = 0;

  const int width = 0;
  const int length = 0;

public: 
  float sX;
  float sY;
  float sAng;
  
  float x;
  float y;
  float ang;

  void updatePos();

  float getX();

  float getY();

  float getAng(bool radian); // returns last updates angle in radians!!!

  float PID(float target);
};