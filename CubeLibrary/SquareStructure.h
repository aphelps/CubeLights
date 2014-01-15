#ifndef SQUARESTRUCTURE
#define SQUARESTRUCTURE

#include "PixelUtil.h"

/*
 *   3      0       0
 *    +------------+
 *    | 0    1    2|
 *    |            |
 *   3| 3    4    5|1
 *    |            |
 *    | 6    7    8|
 *    +------------+
 *   2      2       1
 */
#define SQUARE_NUM_EDGES 4
#define SQUARE_NUM_VERTICES 4
#define SQUARE_VERTEX_ORDER 1

#define SQUARE_LED_ROWS 3
#define SQUARE_LED_COLS 3

class Square {
 public:
  static const byte NUM_EDGES    = 4;
  static const byte NUM_VERTICES = 4;
  static const byte VERTEX_ORDER = 1;
  static const byte NUM_LEDS = SQUARE_LED_ROWS * SQUARE_LED_COLS;

  Square() {};
  Square(unsigned int id);

  Square *getEdge(byte edge);
  void setEdge(byte edge, Square *square);

  Square *getVertex(byte vertex, byte index);
  void setVertex(byte vertex, byte index, Square *square);

  void setLedPixels(uint16_t p0, uint16_t p1, uint16_t p2,
		    uint16_t p3, uint16_t p4, uint16_t p5,
		    uint16_t p6, uint16_t p7, uint16_t p8);

  void setColor(byte r, byte g, byte b);
  void setColor(uint32_t c);
  void setColor(byte led, byte r, byte g, byte b);
  void setColor(byte led, uint32_t c);

  uint32_t getColor();
  uint32_t getColor(byte led);
  byte getRed();
  byte getRed(byte vertex);
  byte getGreen();
  byte getGreen(byte vertex);
  byte getBlue();
  byte getBlue(byte vertex);

  void print(byte level);

  // Variables - be careful of object size
  boolean hasLeds;
  boolean updated;
  byte id;
  RGB leds[NUM_LEDS];
  Square *edges[NUM_EDGES];
  Square *vertices[NUM_VERTICES][VERTEX_ORDER];
  byte mark;
};

/* Send updated values to a Pixel chain */
void updateSquarePixels(Square *squares, int numSquares,
			  PixelUtil *pixels);

/* Allocate and return a fully connected cube */
Square* buildCube(int *numSquares, int numLeds, int firstLed);

/* Macros for rotating around the vertices of a square */
#define VERTEX_CW(v) ((v + 1) % SQUARE_NUM_VERTICES)
#define VERTEX_CCW(v) ((v + SQUARE_NUM_VERTICES - 1) % SQUARE_NUM_VERTICES)


#endif
