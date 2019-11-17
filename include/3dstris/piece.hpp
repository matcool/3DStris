#pragma once

#include <3dstris/shapes.hpp>
#include <3dstris/util.hpp>

class Board;
class Piece {
   public:
	Piece(Board& board, const PieceShape& shape, const PieceType type);
	Piece(Board& board, const PieceType type);

	void reset(const PieceShape& shape, const PieceType type);
	void reset(const PieceType type);

	void set();

	void draw(const Vector2 origin, const u32 tileSize) const;
	static void draw(const Vector2 origin, const u32 tileSize,
					 const PieceShape& shape, const Color color);

	bool move(const Direction dir);

	void rotate(const bool ccw);

	bool collides(const int offX, const int offY) const;
	bool hasSet() const { return _hasSet; }

	void update(const double dt, const u32 kDown, const u32 kHeld);

	PieceType getType();

   private:
	Board& board;

	PieceType type;
	Vector2 pos;

	Color color;
	Color ghostColor;
	PieceShape shape;

	double fallTimer;
	// Vector2 as they need one for left and right
	Vector2d dasTimer;

	double arr;
	double arrTimer;

	double das;

	bool _hasSet;
};