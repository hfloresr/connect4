#ifndef __constants

namespace constants {
    
    const bool USE_HASH = true; 
	
  const unsigned long HASH_SIZE = 1024 * 1024 * 8;

  const int BLACK = -1;
  const int NONE = 0;
  const int WHITE = 1;
  
  const unsigned int MAX_FILES = 7;
  const unsigned int MAX_RANKS = 6;
  const unsigned int MAX_DEPTH = 42;
  const unsigned int MAX_MOVES = 42;
  
  const int WORST_VALUE = -10000;
  const int STALEMATE_VALUE = 0;
  const int BEST_VALUE = 10000;
  
  const int WINDOW = 8;
  const int MATE_RANGE = 100;

  const int INVALID = -20000;

  const int NUM_THREATS = 69;

  // const int THREE_VAL = 8;
  // const int TWO_VAL   = 2;
  
  const int RANK_THREE_VAL_TABLE[2][constants::MAX_RANKS] = 
  { // upside down, so first entry is rank[0]:
	  {  // ranks for white (= yellow) from 0 to 6
		2,
		8,
		3,
		8,
		3,
		8
	  },
	  {  // ranks for black (= red) from 0 to  3
		8,
		3,
		8,
		3,
		8,
		3
	  }	  
  };
  
  const int RANK_TWO_VAL_TABLE[2][constants::MAX_RANKS] = 
  { // upside down, so first entry is rank[_, 0]:
	  {  // ranks for white (= yellow) from 0 to 6
		2,
		1,
		2,
		1,
		2,
		1
	  },
	  {  // ranks for black (= red) from 0 to MAX_RANKS-1
		1,
		2,
		1,
		2,
		1,
		2
	  }	  
  };
  
  inline const int RANK_THREE_VAL(const unsigned rank, const int side)
  {
	  //assert(rank < MAX_RANKS);
	  //return RANK_THREE_VAL_TABLE[rank];
	  const unsigned yellowOrRed = side == constants::WHITE ? 0 : 1;
	  return RANK_THREE_VAL_TABLE[yellowOrRed][rank];
  }
  
  inline const int RANK_TWO_VAL(const unsigned rank, const int side)
  {
	  //assert(rank < MAX_RANKS);
	  //return RANK_TWO_VAL_TABLE[rank];
//	  const unsigned yellowOrRed = side == constants::WHITE ? 0 : 1;
//	  return RANK_TWO_VAL_TABLE[yellowOrRed][rank];
	  return 1;
  }

  const int CENTER_TABLE[MAX_FILES][MAX_RANKS] =
// rank: 0   1   2   3   4   5  
      {{ 3,  4,  5,  5,  4,  3}, // first FILE
       { 4,  6,  8,  8,  6,  4}, // second FILE
       { 5,  8, 11, 11,  8,  5}, // ...
       { 7, 10, 14, 14, 10,  7},
       { 5,  8, 11, 11,  8,  5},
       { 4,  6,  8,  8,  6,  4},
       { 3,  4,  5,  5,  4,  3}};

	   
  const int THREAT_TABLE[MAX_FILES][MAX_RANKS][14] = {
    // first file:
    { {  0, 24, 45, INVALID, INVALID, INVALID, INVALID, INVALID, INVALID, INVALID, INVALID, INVALID, INVALID, INVALID}, 
      {  4, 24, 25, 46, INVALID, INVALID, INVALID, INVALID, INVALID, INVALID, INVALID, INVALID, INVALID, INVALID}, 
      {  8, 24, 25, 26, 47, INVALID, INVALID, INVALID, INVALID, INVALID, INVALID, INVALID, INVALID, INVALID}, 
      { 12, 24, 25, 26, 57, INVALID, INVALID, INVALID, INVALID, INVALID, INVALID, INVALID, INVALID, INVALID}, 
      { 16, 25, 26, 58, INVALID, INVALID, INVALID, INVALID, INVALID, INVALID, INVALID, INVALID, INVALID, INVALID}, 
      { 20, 26, 59, INVALID, INVALID, INVALID, INVALID, INVALID, INVALID, INVALID, INVALID, INVALID, INVALID, INVALID} },
    
    // second file:
    { {  0,  1, 27, 48, INVALID, INVALID, INVALID, INVALID, INVALID, INVALID, INVALID, INVALID, INVALID, INVALID}, 
      {  4,  5, 27, 28, 45, 49, INVALID, INVALID, INVALID, INVALID, INVALID, INVALID, INVALID, INVALID}, 
      {  8,  9, 27, 28, 29, 46, 50, 57, INVALID, INVALID, INVALID, INVALID, INVALID, INVALID}, 
      { 12, 13, 27, 28, 29, 47, 58, 60, INVALID, INVALID, INVALID, INVALID, INVALID, INVALID}, 
      { 16, 17, 28, 29, 59, 61, INVALID, INVALID, INVALID, INVALID, INVALID, INVALID, INVALID, INVALID}, 
      { 20, 21, 29, 62, INVALID, INVALID, INVALID, INVALID, INVALID, INVALID, INVALID, INVALID, INVALID, INVALID} }, 
    
    // third file:
    { {  0,  1,  2, 30, 51, INVALID, INVALID, INVALID, INVALID, INVALID, INVALID, INVALID, INVALID, INVALID}, 
      {  4,  5,  6, 30, 31, 48, 52, 57, INVALID, INVALID, INVALID, INVALID, INVALID, INVALID}, 
      {  8,  9, 10, 30, 31, 32, 45, 49, 53, 58, 60, INVALID, INVALID, INVALID}, 
      { 12, 13, 14, 30, 31, 32, 46, 50, 59, 61, 63, INVALID, INVALID, INVALID}, 
      { 16, 17, 18, 31, 32, 47, 62, 64, INVALID, INVALID, INVALID, INVALID, INVALID, INVALID}, 
      { 20, 21, 22, 32, 65, INVALID, INVALID, INVALID, INVALID, INVALID, INVALID, INVALID, INVALID, INVALID} }, 
    
    // 4th file:
    { {  0,  1,  2,  3, 33, 54, 57, INVALID, INVALID, INVALID, INVALID, INVALID, INVALID, INVALID}, 
      {  4,  5,  6,  7, 33, 34, 51, 55, 58, 60, INVALID, INVALID, INVALID, INVALID}, 
      {  8,  9, 10, 11, 33, 34, 35, 48, 52, 56, 59, 61, 63, INVALID}, 
      { 12, 13, 14, 15, 33, 34, 35, 45, 49, 53, 62, 64, 66, INVALID}, 
      { 16, 17, 18, 19, 34, 35, 46, 50, 65, 67, INVALID, INVALID, INVALID, INVALID}, 
      { 20, 21, 22, 23, 35, 47, 68, INVALID, INVALID, INVALID, INVALID, INVALID, INVALID, INVALID} }, 
    
    // 5th file:
    { {  1,  2,  3, 36, 60, INVALID, INVALID, INVALID, INVALID, INVALID, INVALID, INVALID, INVALID, INVALID}, 
      {  5,  6,  7, 36, 37, 54, 61, 63, INVALID, INVALID, INVALID, INVALID, INVALID, INVALID}, 
      {  9, 10, 11, 36, 37, 38, 51, 55, 62, 64, 66, INVALID, INVALID, INVALID}, 
      { 13, 14, 15, 36, 37, 38, 48, 52, 56, 65, 67, INVALID, INVALID, INVALID}, 
      { 17, 18, 19, 37, 38, 49, 53, 68, INVALID, INVALID, INVALID, INVALID, INVALID, INVALID}, 
      { 21, 22, 23, 38, 50, INVALID, INVALID, INVALID, INVALID, INVALID, INVALID, INVALID, INVALID, INVALID} }, 
    
    // 6th file:
    { {  2,  3, 39, 63, INVALID, INVALID, INVALID, INVALID, INVALID, INVALID, INVALID, INVALID, INVALID, INVALID}, 
      {  6,  7, 39, 40, 64, 66, INVALID, INVALID, INVALID, INVALID, INVALID, INVALID, INVALID, INVALID}, 
      { 10, 11, 39, 40, 41, 54, 65, 67, INVALID, INVALID, INVALID, INVALID, INVALID, INVALID}, 
      { 14, 15, 39, 40, 41, 51, 55, 68, INVALID, INVALID, INVALID, INVALID, INVALID, INVALID}, 
      { 18, 19, 40, 41, 52, 56, INVALID, INVALID, INVALID, INVALID, INVALID, INVALID, INVALID, INVALID}, 
      { 22, 23, 41, 53, INVALID, INVALID, INVALID, INVALID, INVALID, INVALID, INVALID, INVALID, INVALID, INVALID} }, 

    // 7th file:
    { {  3, 42, 66, INVALID, INVALID, INVALID, INVALID, INVALID, INVALID, INVALID, INVALID, INVALID, INVALID, INVALID}, 
      {  7, 42, 43, 67, INVALID, INVALID, INVALID, INVALID, INVALID, INVALID, INVALID, INVALID, INVALID, INVALID}, 
      { 11, 42, 43, 44, 68, INVALID, INVALID, INVALID, INVALID, INVALID, INVALID, INVALID, INVALID, INVALID}, 
      { 15, 42, 43, 44, 54, INVALID, INVALID, INVALID, INVALID, INVALID, INVALID, INVALID, INVALID, INVALID}, 
      { 19, 43, 44, 55, INVALID, INVALID, INVALID, INVALID, INVALID, INVALID, INVALID, INVALID, INVALID, INVALID}, 
      { 23, 44, 56, INVALID, INVALID, INVALID, INVALID, INVALID, INVALID, INVALID, INVALID, INVALID, INVALID, INVALID} }
  };
}  

#define __constants
#endif
