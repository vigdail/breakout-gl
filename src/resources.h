#pragma once

struct WindowDimensions {
  int width;
  int height;
  WindowDimensions(int width, int height) : width(width), height(height) {}
};

struct BlockSize {
  int width;
  int height;
  BlockSize(int width, int height) : width(width), height(height) {}
};
