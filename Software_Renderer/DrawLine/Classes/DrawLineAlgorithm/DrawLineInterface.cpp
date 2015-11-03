
#include "DrawLineInterface.h"

#include <vector>
#include "00-DataDefinition.h"
#include "Bresenham's line algorithm.h"

//=========================================================================
//
//					 Draw Line Interface
//
//=========================================================================
void draw2DLine(const Line2D & drawLine, std::vector<Point2D_int> & pointSet)
{
	transform_Line_Pos(drawLine, pointSet);	
}

