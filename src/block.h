#pragma once

#include "position.h"
#include <map>
#include <vector>

class Block {
public:
  std::map<int, std::vector<Position>> rotations;
  int rotationState = 0;

  Block();
  void move(int rows, int columns);
  virtual int id() = 0;
  virtual void center() = 0;
  std::vector<Position> getMovedCellPositions();

  void rotateForward();
  void rotateBackward();

private:
  int cellSize = 30;
  int rowOffset = 0;
  int columnOffset = 0;
};
