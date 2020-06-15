/* Contains and returns the projection matrix
 * switching between orthogonal and perspective
 * zoom */

#ifndef THE_FOURTH_AGE_PROJECTION_H
#define THE_FOURTH_AGE_PROJECTION_H

/* Includes the math library to be able to make vector and matrix calculations */
#include <maths.h>

/* Contains the matrix mode. 0 = Orthogonal, 1 = Perspective */
int     mode;

/* The matrices to be returned and calculated */
mat4    projPerspectiveMatrix;
mat4    projOrthogonalMatrix;

/* Current FOV to be changed by zooming */
int     fov;

/* Initializes variables and matrices to default; to be called at start of program */
void    PROJ_initProjection     ();

/* Changes mode to 0 */
void    PROJ_setOrthogonal      ();

/* Changes mode to 1 */
void    PROJ_setPerspective     ();

/* Changes FOV on zoom in, only if mode = 0 */
void    PROJ_zoomIn             ();

/* Changes FOV on zoom out */
void    PROJ_zoomOut            ();

/* Returns the current projection matrix only if mode = 0 */
mat4    returnProjection        ();

#endif //THE_FOURTH_AGE_PROJECTION_H
