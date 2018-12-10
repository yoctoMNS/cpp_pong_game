#ifndef INCLUDED_STAGE_HPP
#define INCLUDED_STAGE_HPP


class Stage
{
private:
  int width, height;


public:
  Stage(int w, int h);


public:
  inline int getWidth() { return width; }
  inline int getHeight() { return height; }
};


#endif // !#ifndef INCLUDED_STAGE_HPP
