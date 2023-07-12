#pragma once

#include "block.h"
#include "grid.h"
#include <memory>
#include <vector>

class Game {
public:
  const static int CELL_SIZE = 30;
  const static int PADDING_SIZE = 10;

  bool gameOver = false;

  Grid grid = Grid();

  Game();
  void applyGravity();
  void draw();
  void handleInput();
  void restart();

  std::shared_ptr<Block> getCurrentBlock() { return currentBlock; }
  int getScore() { return score; }

private:
  int score = 0;

  std::vector<std::shared_ptr<Block>> blocks = getDefaultBlocks();
  std::shared_ptr<Block> currentBlock = popRandomBlock();
  std::shared_ptr<Block> nextBlock = popRandomBlock();

  std::shared_ptr<Block> popRandomBlock();
  std::vector<std::shared_ptr<Block>> getDefaultBlocks();

  void drawGrid();

  void giveScoreForFullRows(int fullRows);
  void giveScoreForManualDrop() { score += 1; };

  bool isBlockOutsideGrid();
  bool blockFits();

  void lockBlockAndSpawnNextBlock();

  void moveBlockLeft();
  void moveBlockRight();
  void moveBlockDown();

  bool moveBlockIfItFits(int rows, int columns);

  void rotateBlockForward();
  void rotateBlockBackward();
};
