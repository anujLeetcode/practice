/*
Find the total area covered by two rectilinear rectangles in a 2D plane.

Each rectangle is defined by its bottom left corner and top right corner as shown in the figure.

Rectangle Area - Check the problem here - 
https://leetcode.com/problems/rectangle-area/description/
Assume that the total area is never beyond the maximum possible value of int.

*/
int computeArea(int A, int B, int C, int D, int E, int F, int G, int H)
{
    int x = min(G, C) > max(E, A) ? (min(G, C) - max(E, A)) : 0;
    int y = min(D, H) > max(B, F) ? (min(D, H) - max(B, F)) : 0;
    return (D - B) * (C - A) + (G - E) * (H - F) - x * y;
}
