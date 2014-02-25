#include "Graph.hpp"
//Dessine une grille selon le plan XY
void Graph::drawGrid(float size, float step)
{

    // 20x20 grid
    glBegin(GL_LINES);

    glColor3f(0.5f, 0.5f, 0.5f);
    for(float i=step; i <= size; i+= step)
    {
        glVertex3f(-size, i,0);   // lines parallel to X-axis
        glVertex3f( size, i,0);
        glVertex3f(-size, -i,0);   // lines parallel to X-axis
        glVertex3f( size, -i,0);

        glVertex3f( i, -size,0);   // lines parallel to Y-axis
        glVertex3f( i,  size,0);
        glVertex3f(-i, -size,0);   // lines parallel to Y-axis
        glVertex3f(-i,  size,0);
    }

    glEnd();

}
